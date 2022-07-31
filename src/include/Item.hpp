#if !defined(__ITEM_HPP__)
	#define __ITEM_HPP__

	#include "include/Personage.hpp"
	#include "include/consts.hpp"
	#include "include/Collision.hpp"
	#include "include/NotMovableGameObject.hpp"

class NotMovableGameObject;
class Personage;
class Collision;

// // ANCHOR - Mettre dans un fichier propre?
// /**
//  * @brief Va permettre la manipulation lors de certains transferts
//  *
//  */
// struct ItemData
// {
// 	Item* item;
// 	/**
// 	 * @brief est il pris? Si oui alors il sera récupéré et placé dans l'inventaire du joueur
// 	 *
// 	 */
// 	bool taken;
// };

namespace game
{
enum class ItemsCategories;
} // namespace game

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

	void updateMousePosWindow(sf::Vector2i mousePosWindow);

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
	unsigned const& getValue() const;
	/**
	 * @brief Retourne le rayon d'action de l'item
	 *
	 * @return float const&
	 */
	float const& getRangeOfAction() const;
	/**
	 * @brief Retourne le temps d'attente pour que l'action soit faite
	 *
	 * @return float const&
	 */
	float const& getWaitingTimeForAction() const;
	/**
	 * @brief Indique si l'item est à usage unique
	 *
	 * @return true
	 * @return false
	 */
	bool const& isOneUse() const;

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
	/**
	 * @brief Indique si l'item ne peut etre utilisé qu'une seule fois.
	 *
	 */
	bool oneUse;

	// Fonctions d'initialisation

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 *
	 */
	virtual void updatePosition(float posX, float posY) = 0;
};

#endif // __ITEM_HPP__
