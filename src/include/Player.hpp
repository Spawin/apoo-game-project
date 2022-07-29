#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "include/Personage.hpp"

class Personage;

class Player
{
public:
	Player(Personage* personage);
	~Player();

	// Fonctions/Méthodes
	sf::Vector2f getPosition() const;
	Personage* getPersonage();

	void manageMove(const float& deltaTime);
	// void updateAnimation(const float& deltaTime);

	void updateMousePosWindow(sf::Vector2i mousePosWindow);
	void update(const float& deltaTime);
	void render(sf::RenderTarget& target);

private:
	// Variables
	Personage* personage;
	/**
	 * @brief Permet de controler de quelque coté diriger une animation (gauche ou droite)
	 * TODO - Placer cela dans l'animation!
	 *
	 */
	bool lastSideIsRight;

	// float waitAnimationEnd;

	// Fonctions d'initialisation

	bool haveThisItem(ItemsCategories const& categorie) const;
};

#endif // __PLAYER_HPP__
