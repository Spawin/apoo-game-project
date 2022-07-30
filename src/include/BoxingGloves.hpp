#if !defined(__BOXING_GLOVES__HPP__)
	#define __BOXING_GLOVES__HPP__

	#include "include/Armory.hpp"
	#include "include/Collision.hpp"

class Armory;
class Collision;

class BoxingGloves : public Armory
{
public:
	// Constructeurs/Destructeur
	BoxingGloves();
	~BoxingGloves();

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

#endif // __BOXING_GLOVES__HPP__
