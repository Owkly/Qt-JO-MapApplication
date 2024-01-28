# Projet Jeux Olympiques

# 1. Récupération du projet et exécution

## Clonage du projet
```bash
git clone https://github.com/Owkly/Projet-Jeux-Olympiques
cd Projet_Jeux_Olympique
```

## Exécution du projet
```bash
qmake
make
./Projet_Jeux_Olympique
```

Ce projet nécessite l'installation de certaines dépendances.
Par la suite nous supposerons que vous êtes sur Ubuntu
Suivez les étapes ci-dessous pour installer les dépendances nécessaires.


# 2. Installation des dépendances et librairies nécessaires

## Mise à jour du système

```bash
sudo apt update
sudo apt upgrade
```

## Installation de Qt

```bash
sudo apt install qt5-default qt5-doc qtbase5-doc-html qtbase5-examples qtdeclarative5-dev qtdeclarative5-doc-html
```

## Installations de certains packages

```bash
sudo apt install libqt5svg5 libqt5svg5-dev
sudo apt install qttools5-dev qttools5-dev-tools
sudo apt install qtwebengine5-dev
sudo apt install qtmultimedia5-dev
sudo apt install qtlocation5-dev qtpositioning5-dev
```

## Vérification de l'installation de qmake

```bash
qmake --version
```

