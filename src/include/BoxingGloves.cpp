#include "include/BoxingGloves.hpp"
#include "include/consts.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
BoxingGloves::BoxingGloves() :
	Armory("content/gameObjects/boxing_gloves.png", game::ItemsCategories::ATTACK_BODY_TO_BODY)
{
	// m_gameObjectName = "";
	this->setGameObjectName("BoxingGloves");

	m_body.setScale((float)game::ITEM_VIEW_WIDTH / (float)m_texture.getSize().x, (float)game::ITEM_VIEW_WIDTH / (float)m_texture.getSize().y);

	this->value = 40;
	this->rangeOfAction = 30.f;
	this->waitingTimeForAction = .5f;
}

BoxingGloves::~BoxingGloves()
{
}

// Fonctions/Méthodes
void BoxingGloves::onCollisionEnter(Collision const& collision) const
{
	collision.test(); // REVIEW -
}

void BoxingGloves::update()
{}

// void BoxingGloves::useOn(Personage& personage)
// {
// 	personage.receiveHealthDamage(this->value);
// }

void BoxingGloves::updatePosition(float posX, float posY)
{
	m_position->setPosition(posX, posY);
	// On replace le body
	m_body.setPosition(m_position->getPosition().toVector2f());

	std::cout << "Position du " << m_gameObjectName << " : " << m_position << " => " << (*m_position) << std::endl;
}
