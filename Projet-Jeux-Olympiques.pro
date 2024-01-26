TEMPLATE = app
TARGET = Projet_Jeux_Olympiques
INCLUDEPATH += .

QT += core gui widgets quickwidgets location


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
