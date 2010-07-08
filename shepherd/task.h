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

#ifndef TASK_H
#define TASK_H

#include <QThread>
#include <interfaces.h>

//! List of Action objects
/*!
 * The Task class contains a list of actions and regulates their
 * execution. It is the basic constituent of a Job (along with
 * the Condition class)
 */

class Task : public QThread
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = 0);
private:
    QVector<ActionInterface*> actionsequence;
    int id;
};

#endif // TASK_H
