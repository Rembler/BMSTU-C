TEMPLATE = app
TARGET = men
QT += gui widgets
CONFIG += release
# Input
HEADERS += mainForm.h \
    addForm.h \
    delForm.h \
    drawForm.h \
    showForm.h \
    tableFile.h
SOURCES += mainForm.cpp start.cpp \
    addForm.cpp \
    delForm.cpp \
    drawForm.cpp \
    showForm.cpp \
    tableFile.cpp
