#include "include/MovableGameObject.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
MovableGameObject::MovableGameObject(std::string_view const& imageSpritePath) :
	GameObject(imageSpritePath)
{}

MovableGameObject::~MovableGameObject()
{
	delete this->animationComponent;
}

// Fonctions/Méthodes
void MovableGameObject::createAnimationComponent(sf::Texture& texture)
{
	this->animationComponent = new AnimationComponent(m_body, texture);
}

AnimationComponent* MovableGameObject::getAnimationComponent()
{
	return this->animationComponent;
}

bool MovableGameObject::addToHall(Hall* hall)
{
	this->hall = hall;
	this->setPositionMovementLimit(this->hall);
	return true;
}

void MovableGameObject::show(sf::RenderTarget& window)
{
	GameObject::show(window);
}

void MovableGameObject::setPositionMovementLimit(const Hall* hall)
{
	this->m_position->setPositionMovementLimit(hall->getIntRect());
}
