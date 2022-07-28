#if !defined(__SWORD__HPP__)
	#define __SWORD__HPP__

	#include "include/Item.hpp"

class Item;

class Sword : public Item
{
public:
	// Constructeurs/Destructeur
	Sword();
	~Sword();

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

#endif // __SWORD__HPP__
