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
    QSettings* mainconfig;
    QSettings* jobconfig;
    QScriptEngine* sengine;
    QVector<QObject*> triggers;
    QVector<QObject*> actions;
    QVector<Job*> jobs;
};

#endif // SHEPHERDDAEMON_H
