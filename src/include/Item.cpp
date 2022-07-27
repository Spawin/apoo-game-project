#include "include/Item.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Item::Item(std::string_view const& imageSpritePath) :
	NotMovableGameObject(imageSpritePath)
{
}

Item::~Item()
{
}

// Fonctions/Méthodes
