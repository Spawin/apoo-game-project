#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "include/Personage.hpp"

class Player
{
public:
	Player(Personage* personage);
	~Player();

	// Fonctions/Méthodes
	void update(const float& deltaTime);
	void render(sf::RenderTarget& target);

private:
	// Variables
	Personage* m_personnage;

	// Fonctions d'initialisation
};

#endif // __PLAYER_HPP__
