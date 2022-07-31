#include "include/Lounge.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Lounge::Lounge(size_t index, sf::Vector2i topLeftPoint, int width, int height) :
	Hall(topLeftPoint, width, height, index)
{
}

Lounge::~Lounge()
{
}

// Fonctions/Méthodes
