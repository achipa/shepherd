/**
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

#include "shepherddaemon.h"

#include "interfaces.h"

#include <QDebug>
#include <QtCore/QPluginLoader>
#include <QCoreApplication>
#include <QDir>

ShepherdDaemon::ShepherdDaemon(QObject *parent)
    : QObject(parent), sengine(new QScriptEngine())
{
    qDebug() << "Loading plugins";
    loadPlugins();
    loadConfig();
}

void ShepherdDaemon::loadPlugins()
{
//   foreach (QObject *plugin, QPluginLoader::staticInstances())
//        populateMenus(plugin);
    QDir pluginsDir;
    QStringList pluginFileNames;

    pluginsDir = QDir(QCoreApplication::instance()->applicationDirPath());

    foreach (QString plugintype, QStringList() << "triggers" << "actions")
    {
        pluginsDir.cd(plugintype);

        foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
            if (!fileName.endsWith(".so"))
                continue;

            qDebug() << fileName;
            QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
            QObject *plugin = loader.instance();
            if (plugin) {
    //            populateMenus(plugin);
                pluginFileNames += fileName;
                qDebug() << "Loaded " << plugintype << " (" << qobject_cast<InfoInterface *>(plugin)->name() << ")";
    //            connect(this, SIGNAL(about()), plugin, SLOT(aboutPlugin()));
    //            emit about();
            } else {
                qWarning() << "FAILED " << plugintype << loader.errorString();
            }
        }
        pluginsDir.cd("..");
    }
}

void ShepherdDaemon::loadConfig()
{
    // delete mainconfig;
    mainconfig = new QSettings("shepherd", "shepherd");

    // delete jobconfig;
    jobconfig = new QSettings("shepherd", "jobs");

    foreach (QString jobname, jobconfig->childGroups())
    {
        jobconfig->beginGroup(jobname);

        jobconfig->endGroup();
    }
}


ShepherdDaemon::~ShepherdDaemon()
{

}
