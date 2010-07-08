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


#include "condition.h"

Condition::Condition(QObject *parent, QScriptEngine* qse) :
    QObject(parent), condstate(false), sengine(qse)
{
}


bool Condition::evaluate()
{
    QScriptValue val = sengine->evaluate(expr);
    bool oldstate = condstate;
    condstate = val.toBool();
    if (condstate != oldstate)
        emit stateChanged(condstate);
        if (condstate)
            emit turnedTrue();
        else
            emit turnedFalse();

    return condstate;
}

void Condition::setExpression(QString e)
{
    // "triggers.dummy('myparam')
    /*QPushButton button;
    QScriptValue scriptButton = myEngine.newQObject(&button);
    myEngine.globalObject().setProperty("button", scriptButton);

    myEngine.evaluate("button.checkable = true");
*/
    expr = e;

}
