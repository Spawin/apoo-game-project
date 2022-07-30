#if !defined(__ENEMY_HPP__)
	#define __ENEMY_HPP__

	#include "include/Personage.hpp"

class Personage;

class Enemy
{
public:
	// Constructeurs/Destructeur
	Enemy(Personage* personage);
	~Enemy();

	// Fonctions/Méthodes
	sf::Vector2f getPosition() const;
	Personage* getPersonage();

	void manageMove(const float& deltaTime);

	// void updateMousePosWindow(sf::Vector2i mousePosWindow);
	void update(const float& deltaTime);
	void render(sf::RenderTarget& target);

private:
	// Variables
	Personage* personage;

	// Fonctions d'initialisation

	game::AnimationSide getLastAnimationSide();
	bool isLastAnimationSideRight();
};

#endif // __ENEMY_HPP__
