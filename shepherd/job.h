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

#ifndef JOB_H
#define JOB_H

#include <QObject>
#include "condition.h"
#include "task.h"

//! A combination of a Condition and a Task
/**
 * A Job is a class that links a Condition (a set of Triggers forming a
 * boolean expression) with a Task (a set of Actions to be executed)
 */

class Job : public QObject
{
    Q_OBJECT
public:
    explicit Job(QObject *parent = 0, Condition* c = 0, Task* t = 0);

signals:

public slots:
private:
    Condition* condition;
    Task* task;
};

#endif // JOB_H
