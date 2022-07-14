#ifndef __PERSONGE_HPP__
#define __PERSONGE_HPP__

#include "include/GameObject.hpp"
#include <SFML/Graphics.hpp>

class Personage : public GameObject
{
public:
	Personage();
	Personage(std::string_view const& imageSpritePath);
	// virtual ~Personage();
	//Sera appelé à chaque frame...
	virtual void update();

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
