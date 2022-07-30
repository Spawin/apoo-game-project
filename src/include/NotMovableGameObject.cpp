#include "include/NotMovableGameObject.hpp"

// Fonction static

// Fonctions d'initialisation
void NotMovableGameObject::initPosition(float posX, float posY)
{
	m_position = new Position(posX, posY, false);
	m_body.setPosition(m_position->getPosition().toVector2f());
}

// Constructeurs/Destructeur
NotMovableGameObject::NotMovableGameObject(std::string_view const& imageSpritePath) :
	GameObject(imageSpritePath)
{
	this->initPosition(200 * 4.f, 200 * 70.f);
}

NotMovableGameObject::~NotMovableGameObject()
{
	// delete this->animationComponent;
	delete m_position;
	m_position = nullptr;
}

// Fonctions/Méthodes
// void NotMovableGameObject::createAnimationComponent(sf::Texture& texture)
// {
// 	this->animationComponent = new AnimationComponent(m_body, texture);
// }

// AnimationComponent* NotMovableGameObject::getAnimationComponent()
// {
// 	return this->animationComponent;
// }

// bool NotMovableGameObject::addToHall(Hall* hall)
// {
// 	this->hall = hall;
// 	// this->setPositionMovementLimit(this->hall);
// 	return true;
// }

void NotMovableGameObject::show(sf::RenderTarget& window)
{
	GameObject::show(window);
}

void NotMovableGameObject::setPosition(sf::Vector2f const& coordinates)
{
	// m_position->setPosition(coordinates.x, coordinates.y);
	// REVIEW -
	this->updatePosition(coordinates.x, coordinates.y);
}

// void NotMovableGameObject::setPositionMovementLimit(sf::IntRect const& hall)
// {
// 	// this->m_position->setPositionMovementLimit(hall->getIntRect());
// 	this->m_position->setPositionMovementLimit(hall);
// }
