#include "include/TransitDoor.hpp"

// Fonction static

// Fonctions d'initialisation
// void TransitDoor::initHalls(std::vector<Hall*> halls) {}

void TransitDoor::initHallsNumber()
{
	this->hallsNumber = 2;
}

// Constructeurs/Destructeur
TransitDoor::TransitDoor(sf::IntRect rect, std::vector<Hall*> halls) :
	Door(rect)
{
	this->initHallsNumber();
	this->initHalls(halls);
}

TransitDoor::~TransitDoor()
{
}

// Fonctions/Méthodes
