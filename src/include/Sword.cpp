#include "include/Sword.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Sword::Sword() :
	Armory("content/gameObjects/sword.png", ItemsCategories::ATTACK_BODY_TO_BODY)
{
	m_gameObjectName = "Sword";

	m_body.setScale((float)game::INVENTORY_BLOCK_WIDTH / (float)m_texture.getSize().x, (float)game::INVENTORY_BLOCK_WIDTH / (float)m_texture.getSize().y);
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

void Sword::updatePosition(float posX, float posY)
{
	m_position->setPosition(posX, posY);
	// On replace le body
	m_body.setPosition(m_position->getPosition().toVector2f());

	std::cout << "Position du " << m_gameObjectName << " : " << m_position << " => " << (*m_position) << std::endl;
}
