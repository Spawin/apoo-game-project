#include "include/Animation.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Animation::Animation(int priority, sf::Sprite& sprite, sf::Texture& textureSheet, float animationTimer, int start_x, int start_y, int end_x, int end_y, int width, int height, bool fixLastFrame) :
	priority(priority),
	sprite(sprite),
	textureSheet(textureSheet),
	animationTimer(animationTimer),
	width(width),
	height(height),
	fixLastFrame(fixLastFrame)
{
	this->timer = 0.f;
	this->currentRect = this->startRect = sf::IntRect(start_x * width, start_y * height, width, height);
	this->endRect = sf::IntRect(end_x * width, end_y * height, width, height);

	this->sprite.setTexture(this->textureSheet, true);
	this->sprite.setTextureRect(this->startRect);
}

Animation::~Animation()
{
}

// Fonctions/Méthodes
const bool& Animation::isDone() const
{
	return this->done;
}

const bool& Animation::play(const float& deltatime)
{
	this->done = false;
	// Mise à jour du timer
	this->timer += 100.f * deltatime;
	if (this->timer >= this->animationTimer)
	{
		// Réinitialisation du timer
		this->timer = 0.f;

		// Animer
		if (this->currentRect != this->endRect)
		{
			this->currentRect.left += this->width;
		}
		else // On recommence
		{
			// On réinitalise uniquement si la dernière frame de l'animation n'est pas fixée
			if (!fixLastFrame)
			{
				this->currentRect.left = this->startRect.left;
			}

			this->done = true;
		}

		this->sprite.setTextureRect(this->currentRect);
	}

	return this->done;
}

void Animation::reset()
{
	// this->timer = 0.f;
	// Car la première image me sempble pas importante
	this->timer = this->animationTimer;
	this->currentRect = this->startRect;
}

const int& Animation::getPriority() const
{
	return this->priority;
}
