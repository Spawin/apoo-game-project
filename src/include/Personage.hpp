#ifndef __PERSONGE_HPP__
#define __PERSONGE_HPP__

#include "include/MovableGameObject.hpp"
#include <string>

class Personage : public MovableGameObject
{
public:
	explicit Personage(bool isPlayer = false);
	// NOTE -  Pour empêcher la copie de la classe lors de l'initialisati d...
	explicit Personage(Personage const& p) = delete;
	// explicit Personage(std::string_view const& imageSpritePath, bool isPlayer = false);
	// /**
	//  * @brief Construct a new Personage object
	//  *
	//  * @param posX la position x de l'objet
	//  * @param posY la position y de l'objet
	//  */
	// explicit Personage(float posX, float posY, bool isPlayer = false);
	virtual ~Personage();

	// Fonctions/Méthodes
	// Getters
	const int& getHealthLevel() const
	{
		return m_healthLevel;
	}

	const int& getSpecialityLevel() const
	{
		return m_specialityLevel;
	}

	//
	bool isDied() const;

	/**
	 * @brief Pour dessiner l'élement dans la fenêtre.
	 *
	 * @param window
	 */
	virtual void show(sf::RenderTarget& target) override;

	//Sera appelé à chaque frame...
	void update() override;

	void setGameObjectName(std::string name);

	void onCollisionEnter(Collision const& collision) const override;

	virtual void simpleAttack(Personage& target) = 0;
	virtual void specialAttack(Personage& target) = 0;
	virtual void move(MyVector& speed) override;

protected:
	// REVIEW - Faire les initialisation dans le cpp
	/**
	 * @brief Pour initialiser les valeur par défaut du GameObject
	 *
	 */
	void init();
	/**
	 * @brief Pour ajouter les animation pour un personnage
	 *
	 */
	void initAnimations();

	// La quantité de vie du personnage
	int m_healthLevel { 100 };

	// La quantité de ça spécialité
	int m_specialityLevel { 100 };

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
