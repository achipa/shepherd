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

#include "beep.h"

#include <QMessageBox>
#include <QApplication>

BeepActionPlugin::BeepActionPlugin()
{
    pix = new QPixmap();
}

QString BeepActionPlugin::name()
{
    return QString("Beep");
}

QString BeepActionPlugin::description()
{
    return QString("Beep Beep");
}

QPixmap* BeepActionPlugin::pixmap()
{
    return pix;
}

void BeepActionPlugin::aboutPlugin()
{
    QMessageBox::about(0, "Beep Action", "Beep.");
}

void BeepActionPlugin::setValue(const QVariant &p)
{
}

bool BeepActionPlugin::execute()
{
    QApplication::beep();
    return true;
}

Q_EXPORT_PLUGIN2(beep, BeepActionPlugin)
