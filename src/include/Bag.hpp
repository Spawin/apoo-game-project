#if !defined(__BAG_HPP__)
	#define __BAG_HPP__

	#include "include/NotMovableGameObject.hpp"
	#include "include/Inventory.hpp"
	#include "include/Item.hpp"
	#include "include/consts.hpp"

class Bag : public NotMovableGameObject
{
public:
	// Constructeurs/Destructeur
	Bag();
	~Bag();

	// Fonctions/Méthodes
	// void
	Inventory* getInventory();
	/**
	 * @brief émit quand il entre en contacte avec un autre élément
	 *
	 * @param collision
	 */
	virtual void onCollisionEnter(Collision const& collision) const override;
	virtual void update() override;

	void renderInventory(sf::RenderTarget& target);

private:
	// Variables
	Inventory* inventory;

	// Fonctions d'initialisation
	void initInventory();
	// void initAnimations() override;

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 *
	 */
	virtual void updatePosition(float posX, float posY);
};

#endif // __BAG_HPP__
