#include "include/Money.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Money::Money() :
	Item("content/gameObjects/gold_coin.png", ItemsCategories::MONEY)
{
}

Money::~Money()
{
}

// Fonctions/Méthodes
void Money::onCollisionEnter(Collision const& collision) const
{
	collision.test(); // REVIEW -
}

void Money::update()
{}

void Money::updatePosition(float posX, float posY)
{
	m_position->setPosition(posX, posY);
	// On replace le body
	m_body.setPosition(m_position->getPosition().toVector2f());

	std::cout << "Position du " << m_gameObjectName << " : " << m_position << " => " << (*m_position) << std::endl;
}
