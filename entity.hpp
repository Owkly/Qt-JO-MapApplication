// entity.hpp
#pragma once
#include <QString>

class Entity {
public:
    // Constructeur et destructeur
    Entity(int id) : id(id) {}
    virtual ~Entity() {}

    // Getters
    int getId() const { return id; }

    // Méhode virtuelle pure pour afficher les détails d'un objet
    virtual void display() const = 0;

protected:
    // Attributs
    int id;
};
