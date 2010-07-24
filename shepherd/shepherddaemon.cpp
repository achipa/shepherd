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
    : QObject(parent), mainconfig(0), jobconfig(0), pluginconfig(0), sengine(new QScriptEngine())
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
                plugins.insert(qobject_cast<InfoInterface *>(plugin)->id(), pluginsDir.absoluteFilePath(fileName));
    //            connect(this, SIGNAL(about()), plugin, SLOT(aboutPlugin()));
    //            emit about();
                delete plugin;
            } else {
                qWarning() << "FAILED " << plugintype << loader.errorString();
            }
        }
        pluginsDir.cd("..");
    }
}

void ShepherdDaemon::loadConfig()
{
    // load main config

    if (mainconfig) delete mainconfig;
    mainconfig = new QSettings("shepherd", "shepherd");
//    mainconfig->setValue("vacak","ize");

    // load plugin config

    if (pluginconfig) delete pluginconfig;
    pluginconfig = new QSettings("shepherd", "plugins");
//    triggerconfig->setValue("vacak","ize");

    // parse plugin config

    foreach (QString pluginname, pluginconfig->childGroups())
    {
        pluginconfig->beginGroup(pluginname);

        // hardcoded config metafields used for loading are prefixed with _, the rest belong to the plugin itself

        QPluginLoader loader(plugins.value(pluginconfig->value("_plugin","").toString()));
        QObject *plugin = loader.instance();
        if (pluginconfig->value("_plugintype", "trigger").toString() == "trigger")
        {
            triggers.insert(pluginname, qobject_cast<TriggerInterface *>(plugin));

            QVariantMap qvm; //! the config variant map used to set the state/config of a particular instance
            foreach (QString key, pluginconfig->allKeys())
            {
                if (key.startsWith("_"))
                    continue;
                qvm.insert(key, pluginconfig->value(key,""));
            }
            triggers.value(pluginname)->setConfig(qvm);

            // register trigger to the script engine

            sengine->globalObject().setProperty(pluginname, sengine->newQObject(plugin, QScriptEngine::AutoOwnership));
        }
        else
        {
            actions.insert(pluginname, qobject_cast<ActionInterface *>(plugin));
        }


        pluginconfig->endGroup();
    }

    if (jobconfig) delete jobconfig;
    jobconfig = new QSettings("shepherd", "jobs");
//  jobconfig->setValue("vacak","ize");

    // parse job config

    foreach (QString jobname, jobconfig->childGroups())
    {
        jobconfig->beginGroup(jobname);

        Condition* c = new Condition();
        Task* t = new Task();
        Job* job = new Job(this, c, t);
        job->setEnabled(jobconfig->value("enabled", true).toBool());

        jobconfig->endGroup();
    }
}


ShepherdDaemon::~ShepherdDaemon()
{

}
