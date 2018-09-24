TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    input.cpp \
    output.cpp \
    test.cpp \
    index.cpp

HEADERS += \
    dsvector.h \
    catch.hpp \
    input.h \
    output.h \
    index.h
