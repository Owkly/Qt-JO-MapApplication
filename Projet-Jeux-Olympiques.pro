TEMPLATE = app
TARGET = Projet_Jeux_Olympiques
INCLUDEPATH += .

# INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5/QtLocation
# LIBS += -L/usr/lib/x86_64-linux-gnu/qt5/QtLocation/lib -lQt5Location


# Ajouter les modules Qt nécessaires
QT += core gui widgets 
# quick location quickwidgets positioning

# Input

# HEADERS += $$PWD/headers/*.hpp
# SOURCES += $$PWD/src/*.cpp

# List of resource files
# RESOURCES += resources.qrc



SOURCES += \
    main.cpp \
    mainwindow.cpp \
	dataManager.cpp \
    detailedwindow.cpp
    # Ajoutez d'autres fichiers sources (.cpp) ici si nécessaire

HEADERS += \
    mainwindow.hpp \
    lieu.hpp \
    epreuve.hpp \
	dataManager.hpp \
    detailedwindow.hpp
    # Ajoutez d'autres en-têtes (.h) ici si nécessaire

FORMS += \
    mainwindow.ui \
    detailedwindow.ui

# List of resource files
RESOURCES += ressources.qrc
