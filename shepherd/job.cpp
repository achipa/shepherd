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

#include "job.h"

Job::Job(QObject *parent, Condition* c, Task* t) :
    QObject(parent), condition(c), task(t)
{
    connect(c, SIGNAL(turnedTrue()), SLOT(startTask()));
}

void Job::startTask()
{
    if (task && !task->isRunning())
        task->start(QThread::LowestPriority);
}
