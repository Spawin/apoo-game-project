#include "include/Item.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Item::Item(std::string_view const& imageSpritePath, game::ItemsCategories categorie) :
	NotMovableGameObject(imageSpritePath),
	categorie(categorie)
{
	this->value = 10;
	this->rangeOfAction = 30.f;
	this->waitingTimeForAction = 1.f;
	this->oneUse = false;
}

Item::~Item()
{}

// Fonctions/Méthodes
game::ItemsCategories const& Item::getCategorie() const
{
	return this->categorie;
}
