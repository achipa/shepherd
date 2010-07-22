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

#ifndef INTERFACES_H
#define INTERFACES_H

#include <QtPlugin>
#include <QtGui/QPixmap>
#include <QVariantMap>
//! Base info about the plugin
/*!
 * The InfoInterface defines the way for a plugin to communicate its
 * basic parameters and settings
 */

class InfoInterface
{
public:
    virtual ~InfoInterface() {}
    virtual QString name() =0;     //!< Plugin name
    virtual QString description() =0; //!< Textual description
    virtual QPixmap* pixmap() =0;  //!< Small 32x32 pixmap (for expression visualization)
    virtual void aboutPlugin() =0; //!< Launch about dialog
};

//! Plugin-specific data input
/*!
 * @interface Input
 * The InputInterface defines the way for a plugin to input data
 * through a plugin-specific dialog. Both Action and Trigger objects
 * can have InputInterfaces. The returned data is a QVariant which
 * can be serialized in order to be saved/loaded
 *
 * Example Trigger InputInterfaces:
 * A map for a GPS Trigger plugin
 * A clock for an alarm Trigger
 *
 * Example Action InputInterfaces:
 * A profile ID for a profile switcher Action plugin
 * A message for a notify Action plugin
 */
class InputInterface
{
public:
    virtual ~InputInterface() {}
    //! configure plugin via a plugin specific QDialog
    virtual bool configure() = 0;
    //! configure plugin instance via serialized QString (usually from conf file)
    virtual bool configure(QString cfg) = 0;
    //! return current configuration of the plugin object
    virtual const QVariantMap& config() = 0;
};

//! Triggers are inputs that can trigger actions
/*!
 * @interface Trigger
 * The TriggerInterface defines methods to set up a Trigger
 */
class TriggerInterface
{
public:
    virtual ~TriggerInterface() {}
    /*!
     * Set the parameter to which the Trigger will compare to. This
     * can be a QString (like an SSID name), numer (battery charge level),
     * but also custom data like GPS locations, etc.
     */
    virtual void setConfig(const QVariantMap&) =0; //!< set QVariant (usually read from an InputInterface)

    /*!
     * emitted when the condition evaluation changes state, either
     * going from true to false or the other way around
     *
     * \param b the new state
     */
    virtual void stateChanged(bool b) = 0;
    virtual void turnedTrue() = 0;   //!< Condition evaluation changed and became true
    virtual void turnedFalse() = 0;  //!< Condition evaluation changed and became false
    /*!
     * Evaluate current trigger state, returning a true/false result
     * depending on configuration
     */
    virtual bool eval() = 0;
};


//! Actions are the output or effect
/*!
 * @interface Action
 * The ActionInterface defines the way the Task object can
 * execute the actions
 */
class ActionInterface
{
public:
    virtual ~ActionInterface() {}
    /*!
     * Set the parameter to which the Trigger will compare to. This
     * can be a QString (like an SSID name), numer (battery charge level),
     * but also custom data like GPS locations, etc.
     */
    virtual void setConfig(const QVariantMap&) =0; //!< set QVariant (usually read from an InputInterface)
    //! execute action
    virtual bool execute() =0;
};

Q_DECLARE_INTERFACE(InfoInterface, "org.shepherd.InfoInterface/1.0")
Q_DECLARE_INTERFACE(InputInterface, "org.shepherd.InputInterface/1.0")
Q_DECLARE_INTERFACE(TriggerInterface, "org.shepherd.TriggerInterface/1.0")
Q_DECLARE_INTERFACE(ActionInterface, "org.shepherd.ActionInterface/1.0")

#endif // INTERFACES_H
