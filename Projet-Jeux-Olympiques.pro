TEMPLATE = app
TARGET = Projet_Jeux_Olympiques
INCLUDEPATH += .

# INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5/QtLocation
# LIBS += -L/usr/lib/x86_64-linux-gnu/qt5/QtLocation/lib -lQt5Location


# Ajouter les modules Qt nécessaires
QT += core gui widgets 
# quick location quickwidgets positioning


SOURCES += dataManager.cpp \
           detailedWindow.cpp \
           main.cpp \
           mainWindow.cpp


HEADERS += mainWindow.hpp \
           dataManager.hpp \
           detailedWindow.hpp \
           entite.hpp \
           epreuve.hpp \
           lieu.hpp \
           restaurant.hpp

FORMS += mainWindow.ui \
    detailedWindow.ui

# List of resource files
RESOURCES += ressources.qrc
