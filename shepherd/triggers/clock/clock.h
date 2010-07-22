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

#ifndef CLOCKTRIGGERPLUGIN_H
#define CLOCKTRIGGERPLUGIN_H

#include "interfaces.h"
#include <QObject>
#include <QTime>

enum e_timeRelation { before, at, after };

class ClockTriggerPlugin : public QObject, public InfoInterface, public InputInterface, public TriggerInterface
{
    Q_OBJECT
    Q_INTERFACES(InfoInterface)
    Q_INTERFACES(InputInterface)
    Q_INTERFACES(TriggerInterface)

public:
    ClockTriggerPlugin();
    QString name();
    QString description();
    QPixmap* pixmap();
    bool configure();
    bool configure(QString cfg);
    const QVariantMap& config();
    void setConfig(const QVariantMap&);
    bool eval();
signals:
    void stateChanged(bool b);
    void turnedTrue();
    void turnedFalse();
public slots:
    void aboutPlugin();
private slots:
    void evalTime();
private:
    void setTimer();
    QPixmap* pix;
    QTime t;
    int rel;
};
//! [0]

#endif
