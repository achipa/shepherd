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
#include <QLibraryInfo>

ShepherdDaemon::ShepherdDaemon(QObject *parent)
    : QObject(parent), mainconfig(0), jobconfig(0), triggerconfig(0), sengine(new QScriptEngine())
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

#ifdef QT_DEBUG
    // I use separate build dirs, so for me the executable is at paths like /home/maemo/shepherd/shepherd-build-desktop/shepherd-daemon...
    pluginsDir = QDir(QCoreApplication::instance()->applicationDirPath());
    pluginsDir.cdUp();
    pluginsDir.cd("shepherd");
#else
    pluginsDir = QDir(QString(QLibraryInfo::PluginsPath) + QDir::separator() + "shepherd");
#endif

    foreach (QString plugintype, QStringList() << "triggers" << "actions")
    {
        if (!pluginsDir.cd(plugintype))
        {
            pluginsDir.cdUp();
            pluginsDir.cd(plugintype);
        }

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
    if (mainconfig) delete mainconfig;
    mainconfig = new QSettings("shepherd", "shepherd");
    mainconfig->setValue("vacak","ize");

    if (jobconfig) delete jobconfig;
    jobconfig = new QSettings("shepherd", "jobs");
    jobconfig->setValue("vacak","ize");

    if (triggerconfig) delete jobconfig;
    triggerconfig = new QSettings("shepherd", "triggers");
    triggerconfig->setValue("vacak","ize");

    foreach (QString jobname, jobconfig->childGroups())
    {
        jobconfig->beginGroup(jobname);

        jobconfig->endGroup();
    }
}


ShepherdDaemon::~ShepherdDaemon()
{

}
