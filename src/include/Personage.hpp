#ifndef __PERSONGE_HPP__
#define __PERSONGE_HPP__

#include "include/GameObject.hpp"
#include <string>

class Personage : public GameObject
{
public:
	explicit Personage(bool isPlayer = false);
	// explicit Personage(Personage const& p) = delete; // NOTE -  Pour empêcher la copie de la classe lors de l'initialisati d...
	explicit Personage(std::string_view const& imageSpritePath, bool isPlayer = false);
	/**
	 * @brief Construct a new Personage object
	 *
	 * @param posX la position x de l'objet
	 * @param posY la position y de l'objet
	 */
	explicit Personage(float posX, float posY, bool isPlayer = false);
	virtual ~Personage();

	//Sera appelé à chaque frame...
	void update() override;

	void setGameObjectName(std::string name);

	void onCollisionEnter(Collision const& collision) const override;

protected:
	/**
	 * @brief Pour initialiser les valeur par défaut du GameObject
	 *
	 */
	void init();
	// La quantité de vie du personnage
	int m_life;
	// Valeur de l'accélération du déplacement (accélération uniforme)
	const float MOVE_SPEED { 100.f };

	const bool m_isPlayer;

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 * Cette position sera déterminé par l'évenement reçu au préalable.
	 * Aussi il s'agit dans ce cas d'une accélération uniforme.
	 */
	virtual void updatePosition() override;
};

#endif // __PERSONGE_HPP__
