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

	/**
	 * @brief Pour dessiner l'élement dans la fenêtre.
	 *
	 * @param window
	 */
	virtual void show(sf::RenderTarget& window) override;

	//Sera appelé à chaque frame...
	void update() override;

	void setGameObjectName(std::string name);

	void onCollisionEnter(Collision const& collision) const override;

	/**
	 * @brief Get the Health object
	 *
	 * @return int
	 */
	int getHealth() const;

	virtual void simpleAttack(Personage& target) = 0;
	virtual void specialAttack(Personage& target) = 0;
	virtual void move(MyVector& speed) override;

protected:
	/**
	 * @brief Pour initialiser les valeur par défaut du GameObject
	 *
	 */
	void init();

	// La quantité de vie du personnage
	int m_health { 100 };

	// La quantité de ça spécialité
	int m_speciality { 100 };

	// Le nom de la spécialité
	std::string m_specialtyName;

	// Valeur de l'attaque
	int m_simpleAttackValue { 10 };

	// Valeur de l'attaque
	int m_specialAttackValue { 25 };

	// probabilité d'attaque réussi (entre 0 et 1) mais évitons le zéro
	float m_probabilitySuccessAttack { .5f };

	// variation de l'attaque (valeur de l'attaque +/- cette valeur)
	int m_attackVariation { 5 };

	// sf::Texture m_healthBarTexture;
	sf::Sprite m_healthBarSprite;

	// sf::Texture m_specialityBarTexture;
	sf::Sprite m_specialityBarSprite;

	// sf::Texture m_
	sf::Sprite m_suit;

	// Valeur de l'accélération du déplacement (accélération uniforme)
	// const float m_MOVE_SPEED { 200.f };

	const bool m_isPlayer;

	sf::RenderTarget* m_window { 0 };

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 * Cette position sera déterminé par l'évenement reçu au préalable.
	 * Aussi il s'agit dans ce cas d'une accélération uniforme.
	 */
	virtual void updatePosition(Position& position) override;
};

#endif // __PERSONGE_HPP__
