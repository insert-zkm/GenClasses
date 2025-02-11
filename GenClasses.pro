TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += src/

include(src/LanguageFactory/languagefactory.pri)
include(src/CppUnit/cppunit.pri)
include(src/CsUnit/csunit.pri)
include(src/JavaUnit/javaunit.pri)
include(src/Units/units.pri)

SOURCES += \
        classunit.cpp \
        main.cpp \
        methodunit.cpp \
        unit.cpp

HEADERS += \
    PrintOperationUnit.h \
    classunit.h \
    methodunit.h \
    unit.h
