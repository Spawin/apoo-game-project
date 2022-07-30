#include "include/Money.hpp"
#include "include/consts.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Money::Money() :
	Item("content/gameObjects/gold_coin.png", game::ItemsCategories::MONEY)
{
	this->setGameObjectName("Money");

	m_body.setScale((float)game::ITEM_VIEW_WIDTH / (float)m_texture.getSize().x, (float)game::ITEM_VIEW_WIDTH / (float)m_texture.getSize().y);

	// REVIEW -
	this->value = 1;
	this->rangeOfAction = 30.f;
	this->waitingTimeForAction = .2f;
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

// void Money::useOn(Personage& personage)
// {
// 	std::cerr << "!!! Utilisation de l'argent sur " << personage.getGameObjectName() << std::endl;
// }

void Money::updatePosition(float posX, float posY)
{
	m_position->setPosition(posX, posY);
	// On replace le body
	m_body.setPosition(m_position->getPosition().toVector2f());

	std::cout << "Position du " << m_gameObjectName << " : " << m_position << " => " << (*m_position) << std::endl;
}
