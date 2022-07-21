#include "include/MovableGameObject.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
MovableGameObject::MovableGameObject(std::string_view const& imageSpritePath, float posX, float posY) :
	GameObject(imageSpritePath, posX, posY)
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
