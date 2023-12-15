TEMPLATE = app
TARGET = Map_JO
INCLUDEPATH += .

# Ajouter les modules Qt nécessaires
QT += core gui widgets

#Input

HEADERS += $$PWD/headers/*.hpp
SOURCES += $$PWD/src/*.cpp

# List of resource files
RESOURCES += resources.qrc
