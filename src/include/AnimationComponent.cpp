#include "include/AnimationComponent.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet) :
	sprite(sprite),
	textureSheet(textureSheet)
{
}

AnimationComponent::~AnimationComponent()
{

	for (auto& it : this->animations)
	{
		delete it.second;
	}
}

// Fonctions/Méthodes
void AnimationComponent::addAnimation(const std::string animation, float animationTimer, int start_x, int start_y, int end_x, int end_y, int width, int height)
{
	this->animations[animation] = new Animation(this->sprite, this->textureSheet, animationTimer, start_x, start_y, end_x, end_y, width, height);
}

// void AnimationComponent::startAnimation(const std::string animation){}

// void AnimationComponent::pauseAnimation(const std::string animation){}

// void AnimationComponent::resetAnimation(const std::string animation){}

void AnimationComponent::play(const std::string animation, const float& deltatime)
{
	this->animations[animation]->play(deltatime);
}
