#include "include/Shield.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Shield::Shield() :
	Armory("content/gameObjects/iron_shield.png", ItemsCategories::DEFEND)
{
	m_gameObjectName = "Sword";

	m_body.setScale((float)game::INVENTORY_BLOCK_WIDTH / (float)m_texture.getSize().x, (float)game::INVENTORY_BLOCK_WIDTH / (float)m_texture.getSize().y);
}

Shield::~Shield()
{
}

// Fonctions/Méthodes
void Shield::onCollisionEnter(Collision const& collision) const
{
	collision.test(); // REVIEW -
}

void Shield::update()
{}

void Shield::updatePosition(float posX, float posY)
{
	m_position->setPosition(posX, posY);
	// On replace le body
	m_body.setPosition(m_position->getPosition().toVector2f());

	std::cout << "Position du " << m_gameObjectName << " : " << m_position << " => " << (*m_position) << std::endl;
}
