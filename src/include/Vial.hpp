#if !defined(__VIAL_HPP__)
	#define __VIAL_HPP__

	#include "include/Collision.hpp"
	#include "include/Item.hpp"

class Item;
// class Personage;
class Collision;

class Vial : public Item
{
public:
	// Constructeurs/Destructeur
	Vial(game::ItemsCategories categorie);
	~Vial();

	// Fonctions/Méthodes

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

#endif // __VIAL_HPP__
