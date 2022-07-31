#include "include/TransitDoor.hpp"

// Fonction static

// Fonctions d'initialisation
// void TransitDoor::initHalls(std::vector<Hall*> halls) {}

void TransitDoor::initHallsNumber()
{
	this->hallsNumber = 2;
}

// Constructeurs/Destructeur
TransitDoor::TransitDoor(sf::Vector2f coordinates, Hall* first_hall, Hall* second_hall) :
	Door(coordinates)
{
	this->initHallsNumber();
	this->initHalls({ first_hall, second_hall });

	this->setGameObjectName("TransitDoor");
}

TransitDoor::~TransitDoor()
{
}

// Fonctions/Méthodes
