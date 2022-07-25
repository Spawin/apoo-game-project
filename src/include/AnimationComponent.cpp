#include "include/AnimationComponent.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet) :
	sprite(sprite),
	textureSheet(textureSheet),
	lastAnimation(nullptr)
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
const bool& AnimationComponent::isDone(const std::string key)
{
	return this->animations[key]->isDone();
}

void AnimationComponent::addAnimation(int priority, const std::string animation, float animationTimer, int start_x, int start_y, int end_x, int end_y, int width, int height, bool fixLastFrame)
{
	this->animations[animation] = new Animation(priority, this->sprite, this->textureSheet, animationTimer, start_x, start_y, end_x, end_y, width, height, fixLastFrame);
}

bool AnimationComponent::canPlay(const std::string& animationKey, bool allowSimilar)
{
	if (this->lastAnimation == nullptr)
	{
		return true;
	}

	if (allowSimilar)
		if (this->animations[animationKey] == this->lastAnimation)
		{
			return true;
		}

	return this->animations[animationKey]->getPriority() < this->lastAnimation->getPriority() || this->lastAnimation->isDone();
}

const bool& AnimationComponent::play(const std::string& animationKey, const float& deltatime)
{
	if (this->lastAnimation == nullptr)
	{
		// std::cout << "Ancien null\n";
		this->lastAnimation = this->animations[animationKey];
	}

	// A la même priorité ou une priorité égale à l'ancienne animation (valable aussi pour une même animation)
	if (this->animations[animationKey]->getPriority() <= this->lastAnimation->getPriority())
	{
		// std::cout << "Est prioritaire\n";
		if (this->lastAnimation != this->animations[animationKey])
		{
			// std::cout << "ancien diférent du nouveau\n";
			this->lastAnimation->reset();
			this->lastAnimation = this->animations[animationKey]; // REVIEW - On dirait une réafectation inutile. on le place pluto dans la condition précédente et c bon
		}

		return this->animations[animationKey]->play(deltatime);
	}
	else
	{
		// On joue l'ancienne car la nouvelle n'est pas prioritaire.
		if (!this->lastAnimation->isDone())
		{
			// std::cout << "l'ancienne n'est pas finie\n";
			return this->lastAnimation->play(deltatime);
		}

		// std::cout << "l'ancienne est finie\n";
		// L'ancienne animation est finie donc on va aller sur la nouvelle
		this->lastAnimation->reset();
		this->lastAnimation = this->animations[animationKey];
		return this->animations[animationKey]->play(deltatime);
	}
}
