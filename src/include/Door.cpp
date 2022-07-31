#include "include/Door.hpp"

// Fonction static
// Initialisation à vide de la liste des portes
Door::DoorMap Door::doors = [] {
	DoorMap ret;
	return ret;
}();

// Fonctions d'initialisation
void Door::initHalls(std::vector<Hall*> halls)
{
	if (this->hallsNumber <= -1)
	{

		if ((short)halls.size() != this->hallsNumber)
		{
			// REVIEW -
			std::cerr << "Erreur nombre de hall\n";
			exit(-1);
		}

		for (size_t i = 0; i < halls.size(); i++)
		{
			this->halls.push_back(halls[i]);
		}
	}

	if (halls.size() == 0)
	{
		// REVIEW -
		std::cerr << "Erreur nombre de hall\n";
		exit(-1);
	}

	for (short i = 0; i < this->hallsNumber; i++)
	{
		this->halls.push_back(halls[i]);
	}
}

// Constructeurs/Destructeur
Door::Door(sf::IntRect rect) :
	NotMovableGameObject("content/gameObjects/door.png"),
	intRect(rect)
{
	// On ajoute cette porte à la liste de portes
	Door::doors[this->getGameObjectId()] = this;

	this->setGameObjectName("Door");
}

Door::~Door()
{}

// Fonctions/Méthodes
short const& Door::getHallsNumber() const
{
	return this->hallsNumber;
}

void Door::onCollisionEnter(Collision const& collision) const
{
	collision.test();
}

void Door::update()
{
	// this->inventory-
}
