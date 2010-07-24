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

#ifndef SHEPHERDDAEMON_H
#define SHEPHERDDAEMON_H

#include <QtCore/QObject>
#include <QtCore/QSettings>
#include <QtScript/QScriptEngine>

#include "job.h"

//! Base daemon class
/*!
 * The ShepherDaemon is the base daemon class. It's main tasks are loading
 * and maintaining the jobs based on the config files.
 *
 */
class ShepherdDaemon : public QObject
{
    Q_OBJECT
signals:
public:
    ShepherdDaemon(QObject *parent = 0);

/*! Load plugins (both triggers and actions) */
    void loadPlugins();

/*! Destroys the ShepherdDaemon object */
    ~ShepherdDaemon();

public slots:
//! (re)load job settings from config files.
/*!
 * Used on startup but also when the GUI config editor changes job settings
 */
    void loadConfig();
private:
    QSettings* mainconfig;                          //! Shepherd daemon config
    QSettings* jobconfig;                           //! stored config of Job objects
    QSettings* pluginconfig;                        //! stored config of particular plugin instances (used in jobs)
    QScriptEngine* sengine;                         //! the script engine used for condition evaluation (shared across the plugins)
    QMap<QString, TriggerInterface*> triggers;      //! instantiated trigger plugins
    QMap<QString, ActionInterface*> actions;        //! instantiated action plugins
    QMap<QString, QString> plugins;                 //! link between plugin names and which .so are they stored in
    QVector<Job*> jobs;                             //! Job = condition + task
};

#endif // SHEPHERDDAEMON_H
