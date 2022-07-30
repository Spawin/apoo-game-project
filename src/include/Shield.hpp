#if !defined(__SHIELD_HPP__)
	#define __SHIELD_HPP__

	#include "include/Collision.hpp"
	#include "include/Armory.hpp"

class Armory;
class Collision;

class Shield : public Armory
{
public:
	// Constructeurs/Destructeur
	Shield();
	~Shield();

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

#endif // __SHIELD_HPP__
