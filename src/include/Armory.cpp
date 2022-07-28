#include "include/Armory.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Armory::Armory(std::string_view const& imageSpritePath, ItemsCategories categorie) :
	Item(imageSpritePath, categorie)
{
}

Armory::~Armory()
{
}

// Fonctions/Méthodes
