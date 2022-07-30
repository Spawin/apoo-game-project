#include "include/TeleportKey.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
TeleportKey::TeleportKey() :
	Item("content/gameObjects/teleportKey.png", game::ItemsCategories::TELEPORTKEY)
{
	this->setGameObjectName("TeleportKey");

	m_body.setScale((float)game::ITEM_VIEW_WIDTH / (float)m_texture.getSize().x, (float)game::ITEM_VIEW_WIDTH / (float)m_texture.getSize().y);

	this->value = 1;
}

TeleportKey::~TeleportKey()
{
}

// Fonctions/Méthodes
void TeleportKey::onCollisionEnter(Collision const& collision) const
{
	collision.test(); // REVIEW -
}

void TeleportKey::update()
{}

// void TeleportKey::useOn(Personage& personage)
// {
// 	std::cerr << "Utilisation de la clé de téléportation sur " << personage.getGameObjectName() << std::endl;
// }

void TeleportKey::updatePosition(float posX, float posY)
{
	m_position->setPosition(posX, posY);
	// On replace le body
	m_body.setPosition(m_position->getPosition().toVector2f());

	std::cout << "Position du " << m_gameObjectName << " : " << m_position << " => " << (*m_position) << std::endl;
}
