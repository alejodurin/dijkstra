QT += core
QT -= gui

CONFIG += c++11

TARGET = Dijkstra_final_2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    graph.cpp \
    dijkstra.cpp

HEADERS += \
    graph.h \
    dijkstra.h
