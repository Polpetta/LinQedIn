#-------------------------------------------------
#
# Project created by QtCreator 2015-07-18T15:22:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LinQedIn
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    event.cpp \
    personal.cpp \
    hobby.cpp \
    interests.cpp \
    experiences.cpp \
    user.cpp \
    member.cpp \
    friendships.cpp \
    bio.cpp \
    profile.cpp \
    credentials.cpp \
    memberbasic.cpp \
    database.cpp \
    userdata.cpp \
    smartuser.cpp

HEADERS  += mainwindow.h \
    event.h \
    personal.h \
    hobby.h \
    interests.h \
    experiences.h \
    user.h \
    member.h \
    friendships.h \
    bio.h \
    profile.h \
    credentials.h \
    memberbasic.h \
    database.h \
    userdata.h \
    smartuser.h

#QMAKE_CXXFLAGS += -std=c++11 -Wall #ricordarsi eliminare -Wall
