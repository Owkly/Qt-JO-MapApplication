// entite.hpp
#pragma once

#include <QString>

class Entite {
public:
    // Constructeurs et destructeur
    Entite(int id) : id(id) {}
    virtual ~Entite() {}

    // Getters
    int getId() const { return id; }

    // Méthode virtuelle pure
    virtual void afficher() const = 0;

protected:
    // Attribut
    int id;
};
