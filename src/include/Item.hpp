#if !defined(__ITEM_HPP__)
	#define __ITEM_HPP__

	#include "include/NotMovableGameObject.hpp"

class NotMovableGameObject;

/**
 * @brief Représente éssentiellement les object que pourra manipuler les personnages
 *
 */
class Item : public NotMovableGameObject
{
public:
	Item(std::string_view const& imageSpritePath);
	~Item();
	// Constructeurs/Destructeur

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

	// Fonctions d'initialisation

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 *
	 */
	virtual void updatePosition(float posX, float posY) = 0;
};

#endif // __ITEM_HPP__
