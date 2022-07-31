#include "include/TeleportDoor.hpp"

// Fonction static

// Fonctions d'initialisation
// void TeleportDoor::initHalls(std::vector<Hall*> halls)
// {
// 	if (this->hallsNumber != -1)
// 	{

// 		if (halls.size() != this->hallsNumber)
// 		{
// 			// REVIEW -
// 			std::cerr << "Erreur nombre de hall\n";
// 			exit(-1);
// 		}
// 	}

// 	if (halls.size() == 0)
// 	{
// 		// REVIEW -
// 		std::cerr << "Erreur nombre de hall\n";
// 		exit(-1);
// 	}

// 	for (size_t i = 0; i < this->hallsNumber; i++)
// 	{
// 		this->halls.push_back(halls[i]);
// 	}

// }

void TeleportDoor::initHallsNumber()
{
	// Pas de limite
	this->hallsNumber = -1;
}

// Constructeurs/Destructeur
TeleportDoor::TeleportDoor(sf::IntRect rect, std::vector<Hall*> halls) :
	Door(rect)
{
	this->initHallsNumber();
	this->initHalls(halls);
}

TeleportDoor::~TeleportDoor()
{}

// Fonctions/Méthodes