#ifndef __PERSONGE_HPP__
#define __PERSONGE_HPP__

#include "include/GameObject.hpp"
#include <string>

class Personage : public GameObject
{
public:
	explicit Personage();
	// explicit Personage(Personage const& p) = delete; // NOTE -  Pour empêcher la copie de la classe lors de l'initialisati d...
	explicit Personage(std::string_view const& imageSpritePath);
	virtual ~Personage();
	//Sera appelé à chaque frame...
	virtual void update() override;

	inline void setGameObjectName(std::string name)
	{
		m_gameObjectName = name;
	};

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
	virtual void updatePosition() override;
};

#endif // __PERSONGE_HPP__
