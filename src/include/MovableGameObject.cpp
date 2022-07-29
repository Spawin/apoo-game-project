#include "include/MovableGameObject.hpp"

// Fonction static

// Fonctions d'initialisation
void MovableGameObject::initPosition(float posX, float posY)
{
	m_position = new Position(posX, posY);
	m_body.setPosition(m_position->getPosition().toVector2f());
}

// Constructeurs/Destructeur
MovableGameObject::MovableGameObject(std::string_view const& imageSpritePath) :
	GameObject(imageSpritePath)
{
	this->initPosition(200 * 4.f, 200 * 75.f);
}

MovableGameObject::~MovableGameObject()
{
	delete this->animationComponent;
	delete m_position;
	m_position = nullptr;
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

const Hall* MovableGameObject::getActualHall() const
{
	return this->hall;
}

void MovableGameObject::show(sf::RenderTarget& window)
{
	GameObject::show(window);
}

void MovableGameObject::setPositionMovementLimit(const Hall* hall)
{
	this->m_position->setPositionMovementLimit(hall->getIntRect());
}
