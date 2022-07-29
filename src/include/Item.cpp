#include "include/Item.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Item::Item(std::string_view const& imageSpritePath, ItemsCategories categorie) :
	NotMovableGameObject(imageSpritePath),
	categorie(categorie)
{
	this->value = 10;
}

Item::~Item()
{}

// Fonctions/Méthodes
ItemsCategories const& Item::getCategorie() const
{
	return this->categorie;
}
