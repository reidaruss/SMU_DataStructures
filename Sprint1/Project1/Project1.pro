TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    tweet.cpp \
    word.cpp \
    user.cpp \
    fileread.cpp \
    output.cpp

HEADERS += \
    tweet.h \
    word.h \
    user.h \
    fileread.h \
    output.h
