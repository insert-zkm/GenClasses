TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

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
