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


#ifndef CONDITION_H
#define CONDITION_H

#include <QObject>
#include <QScriptEngine>
#include <interfaces.h>

//! QtScript expressions containing triggers
/*!
 * If the expressions evaluates to true, the condition is fulfilled,
 * usually signalling the start of a Task. The expression itself is
 * a simple string, and it contains function calls that hook into the
 * respective Trigger objects
 */

class Condition : public QObject
{
    Q_OBJECT
public:
    explicit Condition(QObject *parent = 0, QScriptEngine* qse = 0); //!< Condition object constructor
    bool state() { return condstate; }  //!< return current evaluated expression state
    void setExpression(QString e);      //!< set Condition expression containing the Trigger objects
signals:
    /*!
     * emitted when the condition evaluation changes state, either
     * going from true to false or the other way around
     *
     * \param b the new state
     */
    void stateChanged(bool b);
    void turnedTrue();   //!< Condition evaluation changed and became true
    void turnedFalse();  //!< Condition evaluation changed and became false

public slots:
    /*!
     * Force condition evaluation. This slot is usually called from the
     * Trigger object when it itself changes state and wishes to propagate
     * the changes
     */
    bool evaluate();
private:
    bool condstate;
    QString expr;
    int id;
    QScriptEngine* sengine;
};

#endif // CONDITION_H
