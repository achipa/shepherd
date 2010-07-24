#-------------------------------------------------
#
# Project created by QtCreator 2010-07-07T09:46:42
#
#-------------------------------------------------

QT       += core network script
QT       -= gui

TARGET = shepherd-daemon
TEMPLATE = app


SOURCES += main.cpp\
        shepherddaemon.cpp \
    task.cpp \
    condition.cpp \
    job.cpp

HEADERS  += shepherddaemon.h \
    interfaces.h \
    task.h \
    condition.h \
    job.h

Debug:DEFINES+=DEBUG

CONFIG += qdbus mobility
MOBILITY = 

maemo5 {
    message("Maemo5 build")
    QT+= maemo5
}
unix {
    message("Unix build")
    # VARIABLES
    isEmpty(PREFIX):PREFIX = /usr # /local ?
    BINDIR = $$PREFIX/bin
    DATADIR = $$PREFIX/share
    DEFINES += DATADIR=\"$$DATADIR\" \
        PKGDATADIR=\"$$PKGDATADIR\"
    contains(QT_CONFIG, hildon)::DEFINES += CHIMGDIR=\'\"$$DATADIR/$${TARGET}\"\'

    # MAKE INSTALL
    INSTALLS += target \
        imagery \
        appconf \
        desktop \
        iconxpm \
        icon26 \
        icon40 \
        icon64
    target.path = $$BINDIR
    imagery.path = $$DATADIR/$${TARGET}/images
    imagery.files += ../flashlauncher/images/*png
    desktop.path = $$DATADIR/applications/hildon
    desktop.files += $${TARGET}.desktop
    iconxpm.path = $$DATADIR/pixmap
    iconxpm.files += ../data/maemo/$${TARGET}.xpm
    icon26.path = $$DATADIR/icons/hicolor/26x26/apps
    icon26.files += ../data/26x26/$${TARGET}.png
    icon40.path = $$DATADIR/icons/hicolor/40x40/apps
    icon40.files += ../data/40x40/$${TARGET}.png
    icon64.path = $$DATADIR/icons/hicolor/64x64/apps
    icon64.files += ../data/64x64/$${TARGET}.png
    appconf.path = $$DATADIR/flashlauncher
    appconf.files += ../flashlauncher/applications.conf
}


symbian {
    TARGET.UID3 = 0xec508043
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

OTHER_FILES += \
    config/shepherd.conf \
    config/jobs.conf \
    config/plugins.conf
