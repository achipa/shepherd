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

#include "dummy.h"

#include <QMessageBox>

DummyTriggerPlugin::DummyTriggerPlugin()
{
    pix = new QPixmap();
}

QString DummyTriggerPlugin::name()
{
    return QString("Dummy Trigger Plugin");
}

QString DummyTriggerPlugin::description()
{
    return QString("Dummy Trigger Plugin Description");
}

QPixmap* DummyTriggerPlugin::pixmap()
{
    return pix;
}

void DummyTriggerPlugin::aboutPlugin()
{
    QMessageBox::about(0, "Teh dummy plugin", "A dummy plugin to demonstrate how to interface to Shepherd");
}

void DummyTriggerPlugin::setValue(const QVariant &p)
{
}

Q_EXPORT_PLUGIN2(dummy, DummyTriggerPlugin)
