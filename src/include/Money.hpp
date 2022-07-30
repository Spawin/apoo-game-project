#if !defined(__MONEY_HPP__)
	#define __MONEY_HPP__

	#include "include/Item.hpp"

class Item;
class Personage;

class Money : public Item
{
public:
	// Constructeurs/Destructeur
	Money();
	~Money();

	/**
	 * @brief émit quand il entre en contacte avec un autre élément
	 *
	 * @param collision
	 */
	virtual void onCollisionEnter(Collision const& collision) const override;
	virtual void update() override;

	// virtual void useOn(Personage& personage) override;

private:
	// Variables

	// Fonctions d'initialisation

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 *
	 */
	virtual void updatePosition(float posX, float posY) override;
};

#endif // __MONEY_HPP__
