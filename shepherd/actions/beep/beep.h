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

#ifndef BEEPACTIONPLUGIN_H
#define BEEPACTIONPLUGIN_H

#include "interfaces.h"
#include <QObject>

class BeepActionPlugin : public QObject, public InfoInterface, public InputInterface, public ActionInterface
{
    Q_OBJECT
    Q_INTERFACES(InfoInterface)
    Q_INTERFACES(InputInterface)
    Q_INTERFACES(ActionInterface)

public:
    BeepActionPlugin();
    QString name();
    QString description();
    QPixmap* pixmap();
    void setValue(const QVariant& p);
public slots:
    bool execute();
    void aboutPlugin();
private:
    QPixmap* pix;
};

#endif
