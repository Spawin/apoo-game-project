#if !defined(__ANIMATION_HPP__)
	#define __ANIMATION_HPP__

	#include <map>
	#include <string>

class Animation
{
public:
	// Constructeurs/Destructeur
	Animation(sf::Sprite& sprite, sf::Texture& textureSheet, float animationTimer, int start_x, int start_y, int end_x, int end_y, int width, int height);
	~Animation();

	// Fonctions/Méthodes
	void play(const float& deltatime);
	// void pause();
	void reset();

private:
	// Variables
	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	float animationTimer;
	float timer;
	int width;
	int height;
	sf::IntRect startRect;
	sf::IntRect currentRect;
	sf::IntRect endRect;

	// Fonctions d'initialisation
};

#endif // __ANIMATION_HPP__
