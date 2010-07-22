/*!
 * @file
 * @author Attila Csipa <maemo at csipa.in.rs>
 *
 * @section LICENSE
 *
 * GNU General Public License Usage
 * Alternatively, this file may be used under the terms of the GNU
 * General Public License version 2 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.  Please review the following information to
 * ensure the GNU General Public License version 2 requirements
 * will be met: http://www.gnu.org/licenses/old-licenses/gpl-2.html.
 *
 */

#include "clock.h"
#include "timeinputdialog.h"

#include <QMessageBox>
#include <QTimer>

ClockTriggerPlugin::ClockTriggerPlugin() : pix(new QPixmap()), t(QTime()), rel(at)
{
}

QString ClockTriggerPlugin::name()
{
    return QString("Clock Trigger Plugin");
}

QString ClockTriggerPlugin::description()
{
    return QString("A platform independent clock/date plugin");
}

QPixmap* ClockTriggerPlugin::pixmap()
{
    return pix;
}

void ClockTriggerPlugin::aboutPlugin()
{
    QMessageBox::about(0, "Clock plugin", "A clock plugin to demonstrate platform independent time-based triggering");
}

void ClockTriggerPlugin::setTimer()
{
    int offs = QTime::currentTime().secsTo(t);
    if (offs < 0)
        offs += 86400; // tomorrow
    QTimer::singleShot(offs, this, SLOT(evalTime()));
}

void ClockTriggerPlugin::evalTime()
{
    if (rel == before)
    {
        emit stateChanged(false);
        emit turnedFalse();
    }
    else if (rel == after)
    {
        emit stateChanged(true);
        emit turnedTrue();
    }
    else // at
    {
        emit stateChanged(true);
        emit turnedTrue();
        emit stateChanged(false);
        emit turnedFalse();
    }
    setTimer(); // next iteration
}

bool ClockTriggerPlugin::eval()
{
    if (rel == before && QTime::currentTime().secsTo(t) > 0)
        return true;
    else if (rel == at && QTime::currentTime().secsTo(t) <= 1)
        return true;
    else if (rel == after && QTime::currentTime().secsTo(t) < 0)
        return true;

    return false;
}

bool ClockTriggerPlugin::configure()
{
    TimeInputDialog tid;
    if (!tid.exec())
        return false;
    t = tid.time();
    setTimer();
    return true;
}

void ClockTriggerPlugin::setConfig(const QVariantMap &p)
{
    if (p.contains("time") && p.contains("relation"))
    {
        t = p["time"].toTime();
        rel = p["relation"].toInt();
        setTimer();
    }
}

const QVariantMap& ClockTriggerPlugin::config()
{
    QVariantMap* qvm = new QVariantMap();
    qvm->insert("time", t);
    qvm->insert("relation", int(rel));
    return *qvm;
}


Q_EXPORT_PLUGIN2(clock, ClockTriggerPlugin)
