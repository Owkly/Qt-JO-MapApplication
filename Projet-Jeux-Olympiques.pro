TEMPLATE = app
TARGET = Map_JO
INCLUDEPATH += .

# Ajouter les modules Qt nécessaires
QT += core gui widgets

# Input
HEADERS += mainwindow.hpp
SOURCES += main.cpp \
           mainwindow.cpp

# List of resource files
RESOURCES += resources.qrc
