TEMPLATE = app
TARGET = QueueApp
CONFIG += release
QT += gui widgets
# Input
HEADERS += graph.h queue.h
FORMS += graph.ui
SOURCES += graph.cpp queue.cpp start.cpp
