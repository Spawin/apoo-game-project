#if !defined(__VIAL_HPP__)
	#define __VIAL_HPP__

	#include "include/Item.hpp"

class Item;
class Personage;
class Collision;

// enum class VialCategorie {
// 	MEDECINE_HEALTH, // Augmente la santé
// 	MEDECINE_EXP,// Augmente l'exp
// 	POISON_HEALTH,// Diminue la santé
// 	POISON_EXP,// Diminue l'exp
// };

class Vial : public Item
{
public:
	// Constructeurs/Destructeur
	Vial(/*std::string_view const& imageSpritePath, */ game::ItemsCategories categorie);
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
