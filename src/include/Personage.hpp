#ifndef __PERSONGE_HPP__
#define __PERSONGE_HPP__

#include "include/Bag.hpp"
#include "include/Gui.hpp"
#include "include/MovableGameObject.hpp"
#include "include/consts.hpp"
#include <string>

class Bag;
class MovableGameObject;
namespace gui
{
class ProgressBar;
}

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

	const int& getExperienceLevel() const
	{
		return m_experienceLevel;
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

	void updateMousePosWindow(sf::Vector2i mousePosWindow);

	void setGameObjectName(std::string name);

	void onCollisionEnter(Collision const& collision) const override;

	virtual void move(MyVector& speed) override;

	void renderBagInventory(sf::RenderTarget& target);

	virtual void simpleAttack(Personage& target) = 0;
	virtual void specialAttack(Personage& target) = 0;

	/**
	 * @brief pour recevoir les dégats de santé
	 * Retourne les dégats réelemnt concidéré (au cas ou la personne utilise un bouclié ou...)
	 *
	 * @param value
	 * @return unsigned
	 */
	virtual unsigned receiveHealthDamage(int value);
	/**
	 * @brief pour recevoir les dégats d'exp
	 * Retourne les dégats réelemnt concidéré (au cas ou la personne utilise un bouclié ou...)
	 *
	 * @param value
	 * @return unsigned
	 */
	virtual unsigned receiveExpDamage(int value);
	/**
	 * @brief pour recevoir les soins santé
	 * Retourne les dégats réelemnt concidéré (au cas ou la personne utilise un bouclié ou...)
	 *
	 * @param value
	 * @return unsigned
	 */
	virtual unsigned receiveHealthCare(int value);
	/**
	 * @brief pour recevoir les soins Exp
	 * Retourne les dégats réelemnt concidéré (au cas ou la personne utilise un bouclié ou...)
	 *
	 * @param value
	 * @return unsigned
	 */
	virtual unsigned receiveExpCare(int value);
	/**
	 * @brief Pour activer la protection du bouclier.
	 * Il faut noter que son activation est temporaire et protège la santé en diminuant l'ataque
	 *
	 * @param value
	 */
	virtual void receiveShieldboost(int value);

protected:
	Bag* bag;
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
	void initAnimations() override;
	void initEXPBar();
	void initHPBar();
	void initBag();

	sf::Vector2f calculateProgressBarsPosition();

	/**
	 * @brief Augmenter la santé
	 *
	 * @param value
	 */
	void increaseHealth(int value);
	/**
	 * @brief Augmenter l'expérience
	 *
	 * @param value
	 */
	void increaseExp(int value);
	/**
	 * @brief Diminuer la santé
	 *
	 * @param value
	 */
	void decreaseHealth(int value);
	/**
	 * @brief Diminuer l'expériance
	 *
	 * @param value
	 */
	void decreaseExp(int value);

	// La quantité de vie du personnage
	int m_healthLevel { 100 };

	// int m_specialityLevel { 50 };
	/**
	 * @brief La quantité de ça spécialité.
	 * NOTE -
	 *
	 */
	int m_experienceLevel { 50 };

	/**
	 * @brief représente la valeur de protection offerte par le bouclié.
	 * NOTE - Meme si la valeur n'est pas nulle, tant que le bouclié n'est pas activé, cette dernière n'est pas concidérée
	 *
	 */
	int m_shieldBoost { 0 };

	// Le nom de la spécialité
	std::string m_specialtyName;

	// Valeur de l'attaque
	int m_simpleAttackValue { 10 };

	// Valeur de l'attaque
	int m_specialAttackValue { 25 };

	// probabilité d'attaque réussi (entre 0 et 1) mais évitons le zéro
	float m_probabilitySuccessAttack { .5f };

	float m_probabilityDodge { .1 };

	// variation de l'attaque (valeur de l'attaque +/- cette valeur)
	int m_attackVariation { 5 };

	// sf::Texture m_healthBarTexture;
	sf::Sprite m_healthBarSprite;

	// sf::Texture m_specialityBarTexture;
	sf::Sprite m_specialityBarSprite;

	/**
	 * @brief Représente la tenue du personage.
	 * REVIEW
	 *
	 */
	sf::Sprite m_suit;

	const bool m_isPlayer;

	sf::RenderTarget* m_window { 0 };

	//EXP Bar
	gui::ProgressBar* expBar;

	//HP Bar
	gui::ProgressBar* hpBar;

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 * Cette position sera déterminé par l'évenement reçu au préalable.
	 * Aussi il s'agit dans ce cas d'une accélération uniforme.
	 */
	virtual void updatePosition(float posX, float posY) override;

	void updateEXPBar();
	void updateHPBar();

	void renderEXPBar(sf::RenderTarget& target);
	void renderHPBar(sf::RenderTarget& target);
};

#endif // __PERSONGE_HPP__
