QT -= gui

TARGET = proxy.grx
CONFIG += c++11 console
CONFIG -= app_bundle
DEFINES += QT_DEPRECATED_WARNINGS
HEADERS += simplecrypt.h
SOURCES += main.cpp \
            simplecrypt.cpp

