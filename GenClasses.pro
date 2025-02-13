TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += src/

include(src/LanguageFactory/languagefactory.pri)
include(src/Units/units.pri)
include(src/Languages/languages.pri)

SOURCES += main.cpp

HEADERS +=
