#if !defined(__ITEM_HPP__)
	#define __ITEM_HPP__

	#include "include/NotMovableGameObject.hpp"
	#include "include/Personage.hpp"
	#include "include/consts.hpp"

class NotMovableGameObject;
class Personage;

// /**
//  * @brief Représente les catégories d'items.
//  * TODO - Compléter....
//  * Va surtout aider dans l'utilisation de l'item et son comportement
//  */
// enum class ItemsCategories
// {
// 	MONEY,
// 	TELEPORTKEY, //
// 	//
// 	DEFEND,
// 	ATTACK_BODY_TO_BODY,  // Boxing gloves
// 	ATTACK_SEMI_DISTANCE, // Sword
// 	ATTACK_DISTANCE,
// 	// HEALTH_RESTORE,
// 	// EXP_RESTORE,
// 	VIAL_EXP,
// 	VIAL_HEALTH,
// 	VIAL_ATTACK_EXP,
// 	VIAL_ATTACK_HEALTH,
// };

/**
 * @brief Représente éssentiellement les object que pourra manipuler les personnages
 *
 */
class Item : public NotMovableGameObject
{
public:
	// Constructeurs/Destructeur
	Item(std::string_view const& imageSpritePath, game::ItemsCategories categorie);
	~Item();

	// Fonctions/Méthodes
	/**
	 * @brief Get the Categorie object
	 *
	 * @return game::ItemsCategories&
	 */
	game::ItemsCategories const& getCategorie() const;

	/**
	 * @brief émit quand il entre en contacte avec un autre élément
	 *
	 * @param collision
	 */
	virtual void onCollisionEnter(Collision const& collision) const = 0;
	virtual void update() = 0;

	// /**
	//  * @brief Utiliser l'item sur le personnage indiqué
	//  *
	//  * @param personage
	//  */
	// virtual void useOn(Personage& personage) = 0;

	/**
	 * @brief Returne la valeur de l'effet de cet arme
	 *
	 * @return unsigned const&
	 */
	unsigned const& getValue() const
	{
		return value;
	}
	/**
	 * @brief Retourne le rayon d'action de l'item
	 *
	 * @return float const&
	 */
	float const& getRangeOfAction() const
	{
		return rangeOfAction;
	}
	/**
	 * @brief Retourne le temps d'attente pour que l'action soit faite
	 *
	 * @return float const&
	 */
	float const& getWaitingTimeForAction() const
	{
		return waitingTimeForAction;
	}

protected:
	// Variables
	/**
	 * @brief Valeur de l'item à l'utilisation...
	 *
	 */
	unsigned value;
	/**
	 * @brief rayon d'action de l'item
	 *
	 */
	float rangeOfAction;
	/**
	 * @brief Le temps d'attente pour que l'action soit faite
	 *
	 */
	float waitingTimeForAction;
	/**
	 * @brief Représente les categories d'item.
	 * utilis pour définir les éffets...
	 *
	 */
	const game::ItemsCategories categorie;

	// Fonctions d'initialisation

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 *
	 */
	virtual void updatePosition(float posX, float posY) = 0;
};

#endif // __ITEM_HPP__
