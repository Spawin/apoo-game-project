#if !defined(__ANIMATION_HPP__)
	#define __ANIMATION_HPP__

	#include <map>
	#include <string>

class Animation
{
public:
	// Constructeurs/Destructeur
	Animation(int priority, sf::Sprite& sprite, sf::Texture& textureSheet, float animationTimer, int start_x, int start_y, int end_x, int end_y, int width, int height, bool fixLastFrame = false);
	~Animation();

	// Fonctions/Méthodes
	const bool& isDone() const;
	const bool& play(const float& deltatime);
	// void pause();
	void reset();
	// Retourne la priorité de l'animation
	const int& getPriority() const;

private:
	// Variables
	// La priorité d'une animation (Haute priorité : 0)
	int priority;
	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	float animationTimer;
	float timer;
	bool done;
	int width;
	int height;
	bool fixLastFrame;
	sf::IntRect startRect;
	sf::IntRect currentRect;
	sf::IntRect endRect;

	// Fonctions d'initialisation
};

#endif // __ANIMATION_HPP__
