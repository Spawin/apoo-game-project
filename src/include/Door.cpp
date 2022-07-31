#include "include/Door.hpp"
#include "include/consts.hpp"

// Fonction static
// Initialisation à vide de la liste des portes
Door::DoorMap Door::doors = [] {
	DoorMap ret;
	return ret;
}();

// Fonctions d'initialisation
void Door::initHalls(std::vector<Hall*> halls)
{
	if (this->hallsNumber == -1)
	{

		// if ((short)halls.size() != this->hallsNumber)
		// {
		// 	// REVIEW -
		// 	std::cerr << "Erreur nombre de hall\n";
		// 	exit(-1);
		// }

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
Door::Door(sf::Vector2f coordinates) :
	NotMovableGameObject("content/gameObjects/door.png"),
	intRect(coordinates.x, coordinates.y, game::DOORS_TEXTURE_WIDTH, game::DOORS_TEXTURE_HEIGHT)
{
	// On ajoute cette porte à la liste de portes
	Door::doors[this->getGameObjectId()] = this;

	this->m_body.setOrigin(game::DOORS_TEXTURE_WIDTH / 2.f, game::DOORS_TEXTURE_HEIGHT);
	this->updatePosition(coordinates.x, coordinates.y);

	this->rectShape.setOrigin(game::DOORS_TEXTURE_WIDTH / 2.f, game::DOORS_TEXTURE_HEIGHT);
	this->rectShape.setPosition(coordinates.x, coordinates.y);
	this->rectShape.setSize(sf::Vector2f(game::DOORS_TEXTURE_WIDTH, game::DOORS_TEXTURE_HEIGHT));
	this->rectShape.setFillColor(sf::Color::Transparent);
	this->rectShape.setOutlineThickness(-10.f);
	this->rectShape.setOutlineColor(sf::Color::Red);

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

void Door::updatePosition(float posX, float posY)
{
	m_position->setPosition(posX, posY);
	// On replace le body
	m_body.setPosition(m_position->getPosition().toVector2f());

	std::cout << "Position du " << m_gameObjectName << " : " << m_position << " => " << (*m_position) << std::endl;
}

void Door::show(sf::RenderTarget& target)
{
	NotMovableGameObject::show(target);

	target.draw(this->rectShape);
}
