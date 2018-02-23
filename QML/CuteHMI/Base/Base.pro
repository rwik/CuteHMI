include(../../../common.pri)

TEMPLATE = lib
TARGET = $$qtLibraryTarget(cutehmi_base_1_qml)
DESTDIR = $$PWD/plugins	# QtDesigner can find library only in a location relative to qmldir file.

QT += qml quick

CONFIG += plugin

# Translations.
TRANSLATIONS = locale/cutehmi_base_1_qml_pl.ts

include(../../../cutehmi_1/import.pri)

DISTFILES += \
    qmldir \
    TextDisplay.qml \
    designer/Base.metainfo \
    Pipe.qml \
    PipeEmitterSettings.qml \
    PipePoint.qml \
    NumberDisplay.qml \
    Palette.qml \
    ColorSet.qml \
    PropItem.qml \
    Element.qml

RESOURCES +=

HEADERS += \
    src/CuteHMIBaseQMLPlugin.hpp

SOURCES += \
    src/CuteHMIBaseQMLPlugin.cpp

