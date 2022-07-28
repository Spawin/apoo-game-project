#include "include/Bag.hpp"

// Fonction static

// Fonctions d'initialisation
void Bag::initInventory()
{
	this->inventory = new Inventory();
}

// void Bag::initAnimations()
// {
// 	this->createAnimationComponent(m_texture);
// 	this->animationComponent->addAnimation(0, "NOPE", 10.f, 0, 0, 0, 0, 80, 80);
// }

// Constructeurs/Destructeur
Bag::Bag() :
	NotMovableGameObject("content/gameObjects/bag.png")
{
	this->initInventory();
	m_gameObjectName = "Bag";
}

Bag::~Bag()
{
	delete this->inventory;
}

// Fonctions/Méthodes
Inventory* Bag::getInventory()
{
	return this->inventory;
}

void Bag::onCollisionEnter(Collision const& collision) const
{
	collision.test();
}

void Bag::update()
{
	// this->inventory-
}

void Bag::updatePosition(float posX, float posY)
{
	m_position->setPosition(posX, posY);
	// On replace le body
	m_body.setPosition(m_position->getPosition().toVector2f());
}
