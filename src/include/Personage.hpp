#ifndef __PERSONGE_HPP__
#define __PERSONGE_HPP__

#include "include/GameOject.hpp"
#include <SFML/Graphics.hpp>

class Personage : public GameOject
{
public:
	Personage();
	// virtual ~Personage();
	/**
	 * @brief Sera appelé à chaque frame...
	 *
	 * @param time
	 */
	virtual void update(float time);

protected:
	// La quantité de vie du personnage
	int m_life;
	// Valeur de l'accélération du déplacement (accélération uniforme)
	const float MOVE_SPEED { 50.f };

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 * Cette position sera déterminé par l'évenement reçu au préalable.
	 * Aussi il s'agit dans ce cas d'une accélération uniforme.
	 */
	virtual void updatePosition();
};

#endif // __PERSONGE_HPP__
