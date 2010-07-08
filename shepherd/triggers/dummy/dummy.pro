#! [0]
TEMPLATE      = lib
CONFIG       += plugin
INCLUDEPATH  += ../..
HEADERS       = dummy.h
SOURCES       = dummy.cpp
TARGET        = $$qtLibraryTarget(dummy)
DESTDIR       = ../

#! [0]
# install
target.path = $$[QT_INSTALL_EXAMPLES]/tools/plugandpaint/plugins
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS extrafilters.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/tools/plugandpaintplugins/extrafilters
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)

symbian:TARGET.EPOCALLOWDLLDATA = 1
