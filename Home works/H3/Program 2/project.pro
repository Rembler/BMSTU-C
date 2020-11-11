TEMPLATE = app
TARGET = DrawApp
CONFIG += release
QT += gui widgets
# Input
HEADERS += draw.h \
    figures.h
FORMS += draw.ui
SOURCES += draw.cpp start.cpp \
    figures.cpp
