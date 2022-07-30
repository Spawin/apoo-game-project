#include "include/Sword.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Sword::Sword() :
	Armory("content/gameObjects/sword.png", game::ItemsCategories::ATTACK_SEMI_DISTANCE)
{
	// m_gameObjectName = "";
	this->setGameObjectName("Sword");

	m_body.setScale((float)game::ITEM_VIEW_WIDTH / (float)m_texture.getSize().x, (float)game::ITEM_VIEW_WIDTH / (float)m_texture.getSize().y);

	// REVIEW -
	this->value = 40;
	this->rangeOfAction = 30.f;
	this->waitingTimeForAction = .3f;
}

Sword::~Sword()
{
}

// Fonctions/Méthodes
void Sword::onCollisionEnter(Collision const& collision) const
{
	collision.test(); // REVIEW -
}

void Sword::update()
{}

// void Sword::useOn(Personage& personage)
// {
// 	personage.receiveHealthDamage(this->value);
// }

void Sword::updatePosition(float posX, float posY)
{
	m_position->setPosition(posX, posY);
	// On replace le body
	m_body.setPosition(m_position->getPosition().toVector2f());

	std::cout << "Position du " << m_gameObjectName << " : " << m_position << " => " << (*m_position) << std::endl;
}
