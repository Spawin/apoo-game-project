#if !defined(__ITEM_HPP__)
	#define __ITEM_HPP__

	#include "include/NotMovableGameObject.hpp"

class NotMovableGameObject;

/**
	 * @brief Représente les catégories d'items.
	 * TODO - Compléter....
	 *
	 */
enum class ItemsCategories
{
	MONEY,
	TELEPORTKEY,
	DEFEND,
	ATTACK_BODY_TO_BODY,
	ATTACK_DISTANCE,
	HEALTH_RESTORE,
	EXP_RESTORE,
};

/**
 * @brief Représente éssentiellement les object que pourra manipuler les personnages
 *
 */
class Item : public NotMovableGameObject
{
public:
	// Constructeurs/Destructeur
	Item(std::string_view const& imageSpritePath, ItemsCategories categorie);
	~Item();

	// Fonctions/Méthodes

	/**
	 * @brief émit quand il entre en contacte avec un autre élément
	 *
	 * @param collision
	 */
	virtual void onCollisionEnter(Collision const& collision) const = 0;
	virtual void update() = 0;

protected:
	// Variables
	const ItemsCategories categorie;

	// Fonctions d'initialisation

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 *
	 */
	virtual void updatePosition(float posX, float posY) = 0;
};

#endif // __ITEM_HPP__
