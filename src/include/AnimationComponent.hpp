#if !defined(__ANIMATION_COMPONENT_HPP__)
	#define __ANIMATION_COMPONENT_HPP__

	#include "include/Animation.hpp"

class AnimationComponent
{
public:
	// Constructeurs/Destructeur
	AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);
	~AnimationComponent();

	// Fonctions/Méthodes
	void addAnimation(const std::string animation, float animationTimer, int start_x, int start_y, int end_x, int end_y, int width, int height);
	// void startAnimation(const std::string animation);
	// void pauseAnimation(const std::string animation);
	// void resetAnimation(const std::string animation);
	void play(const std::string animation, const float& deltatime);

private:
	// Variables
	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animations;

	// Fonctions d'initialisation
};

#endif // __ANIMATION_COMPONENT_HPP__
