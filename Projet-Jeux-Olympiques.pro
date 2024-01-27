TEMPLATE = app
TARGET = Projet_Jeux_Olympiques
INCLUDEPATH += .

QT += core gui widgets quick quickwidgets location positioning


SOURCES += main.cpp \
           dataManager.cpp \
           mainWindow.cpp \
           scrollAreaManager.cpp \
           detailedDialog.cpp


HEADERS += entity.hpp \
           location.hpp \
           event.hpp \
           restaurant.hpp \
           dataManager.hpp \
           mainWindow.hpp \
           scrollAreaManager.hpp \
           clickableWidget.hpp \
           detailedDialog.hpp

FORMS += mainWindow.ui \
    detailedDialog.ui

# List of resource files
RESOURCES += ressources.qrc
