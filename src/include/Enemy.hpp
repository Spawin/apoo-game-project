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
	/**
	 * @brief Permet de controler de quelque coté diriger une animation (gauche ou droite)
	 * TODO - Placer cela dans l'animation!
	 *
	 */
	bool lastSideIsRight;

	// Fonctions d'initialisation
};

#endif // __ENEMY_HPP__
