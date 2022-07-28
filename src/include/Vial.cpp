#include "include/Vial.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Vial::Vial(std::string_view const& imageSpritePath, ItemsCategories categorie) :
	Item(imageSpritePath, categorie)
{
}

Vial::~Vial()
{
}

// Fonctions/Méthodes