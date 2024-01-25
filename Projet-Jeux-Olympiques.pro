TEMPLATE = app
TARGET = Projet_Jeux_Olympiques
INCLUDEPATH += .

# INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5/QtLocation
# LIBS += -L/usr/lib/x86_64-linux-gnu/qt5/QtLocation/lib -lQt5Location


# Ajouter les modules Qt nécessaires
QT += core gui widgets 
# quick location quickwidgets positioning


SOURCES += main.cpp \
           mainWindow.cpp \
           dataManager.cpp \
           detailedWindow.cpp \
           clickableWidget.cpp 


HEADERS += mainWindow.hpp \
           entity.hpp \
           location.hpp \
           event.hpp \
           restaurant.hpp \
           dataManager.hpp \
           detailedWindow.hpp \
           clickableWidget.hpp 

FORMS += mainWindow.ui \
    detailedWindow.ui

# List of resource files
RESOURCES += ressources.qrc
