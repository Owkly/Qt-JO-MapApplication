TEMPLATE = app
TARGET = Projet_Jeux_Olympiques
INCLUDEPATH += .

QT += core gui widgets quick quickwidgets location positioning


SOURCES += main.cpp \
           mainWindow.cpp \
           dataManager.cpp \
           clickableWidget.cpp \
           detailedDialog.cpp


HEADERS += mainWindow.hpp \
           entity.hpp \
           location.hpp \
           event.hpp \
           restaurant.hpp \
           dataManager.hpp \
           clickableWidget.hpp \
           detailedDialog.hpp

FORMS += mainWindow.ui \
    detailedDialog.ui

# List of resource files
RESOURCES += ressources.qrc
