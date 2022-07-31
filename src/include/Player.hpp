#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "include/Item.hpp"
#include "include/Personage.hpp"
#include "include/consts.hpp"

class Personage;
class item;

class Player
{
public:
	Player(Personage* personage);
	~Player();

	// Fonctions/Méthodes
	sf::Vector2f getPosition() const;
	Personage* getPersonage();

	void manageActionToOtherPersonage(); // REVIEW - Private?
	void manageActionWithDoors();
	void manageMove(const float& deltaTime);
	// void updateAnimation(const float& deltaTime);

	void updateMousePosWindow(sf::Vector2i mousePosWindow);
	void update(const float& deltaTime);
	void render(sf::RenderTarget& target);

private:
	// Variables
	game::PlayerStats playerStats;
	Personage* personage;

	/**
	 * @brief Il s'agit du resultat de la dernière utilisation d'un item sur un personnage (sur soi meme ou pas)
	 *
	 */
	game::ItemActionResult lastItemActionResult;
	/**
	 * @brief Permet de controler de quelque coté diriger une animation (gauche ou droite)
	 * TODO - Placer cela dans l'animation!
	 *
	 */
	// bool lastSideIsRight;

	// float waitAnimationEnd;

	game::AttackSateInformations attackSateInformations;

	game::HallChangeStateInformations hallChangeStateInformations;

	// Fonctions d'initialisation
	void initPlayerStats();

	bool haveThisItem(game::ItemsCategories const& categorie) const;
	Item const* getFirstItemMatch(game::ItemsCategories const& categorie) const;
	Item* getFirstItemMatchNonConst(game::ItemsCategories const& categorie);
	game::AnimationSide getLastAnimationSide();
	bool isLastAnimationSideRight();
	/**
	 * @brief Remet les valeur par défaut
	 *
	 */
	void resetLastItemActionResult();
	void resetAttackSateInformations();
	void resetHallChangeStateInformations();
};

#endif // __PLAYER_HPP__
