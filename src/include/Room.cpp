#include "include/Room.hpp"
// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Room::Room(size_t index, sf::Vector2i topLeftPoint, int width, int height) :
	Hall(topLeftPoint, width, height, index)
{
}

Room::~Room()
{
}

// Fonctions/Méthodes