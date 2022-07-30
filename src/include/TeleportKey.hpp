#if !defined(__TELEPORT_KEY_HPP__)
	#define __TELEPORT_KEY_HPP__

	#include "include/Item.hpp"
	#include "include/Collision.hpp"

class Item;
class collision;

class TeleportKey : public Item
{
public:
	// Constructeurs/Destructeur
	TeleportKey();
	~TeleportKey();

	// Fonctions/Méthodes

	/**
	 * @brief émit quand il entre en contacte avec un autre élément
	 *
	 * @param collision
	 */
	virtual void onCollisionEnter(Collision const& collision) const override;
	virtual void update() override;

private:
	// Variables

	// Fonctions d'initialisation

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 *
	 */
	virtual void updatePosition(float posX, float posY) override;
};

#endif // __TELEPORT_KEY_HPP__
