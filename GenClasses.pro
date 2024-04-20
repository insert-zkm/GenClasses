TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += src/

include(src/LanguageFactory/languagefactory.pri)
include(src/CPP/cpp.pri)
include(src/CS/cs.pri)
include(src/Java/java.pri)
include(src/Units/units.pri)

SOURCES += main.cpp
