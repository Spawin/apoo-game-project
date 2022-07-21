#include "include/Animation.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Animation::Animation(sf::Sprite& sprite, sf::Texture& textureSheet, float animationTimer, int start_x, int start_y, int end_x, int end_y, int width, int height) :
	sprite(sprite),
	textureSheet(textureSheet),
	animationTimer(animationTimer),
	width(width),
	height(height)
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
// void Animation::pause()
// {}

void Animation::play(const float& deltatime)
{
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
			this->currentRect.left = this->startRect.left;
		}

		this->sprite.setTextureRect(this->currentRect);
	}
}

void Animation::reset()
{
	this->timer = 0.f;
	this->currentRect = this->startRect;
}
