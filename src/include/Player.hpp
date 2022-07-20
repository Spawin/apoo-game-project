#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "include/Personage.hpp"

class Player
{
public:
	Player(Personage* personage);
	~Player();

	// Fonctions/Méthodes
	void manageMove(const float& deltaTime);
	void update(const float& deltaTime);
	void render(sf::RenderTarget& target);

private:
	// Variables
	Personage* personage;

	// Fonctions d'initialisation
};

#endif // __PLAYER_HPP__
