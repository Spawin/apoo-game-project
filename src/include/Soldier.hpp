#if !defined(__SOLDIER_HPP__)
	#define __SOLDIER_HPP__

	#include "include/Personage.hpp"

class Soldier : public Personage
{
public:
	explicit Soldier(bool isPlayer = false);
	~Soldier();

	/**
	 * @brief Pour dessiner l'élement dans la fenêtre.
	 *
	 * @param window
	 */
	// virtual void show(sf::RenderTarget& window) override;// REVIEW

	virtual void simpleAttack(Personage& target) override;
	virtual void specialAttack(Personage& target) override;

	// /**
	//  * @brief pour recevoir les dégats de santé
	//  * Retourne les dégats réelemnt concidéré (au cas ou la personne utilise un bouclié ou...)
	//  *
	//  * @param value
	//  * @return unsigned
	//  */
	// virtual unsigned receiveHealthDamage(int value) override;
	// /**
	//  * @brief pour recevoir les dégats d'exp
	//  * Retourne les dégats réelemnt concidéré (au cas ou la personne utilise un bouclié ou...)
	//  *
	//  * @param value
	//  * @return unsigned
	//  */
	// virtual unsigned receiveExpDamage(int value) override;
	// /**
	//  * @brief pour recevoir les soins santé
	//  * Retourne les dégats réelemnt concidéré (au cas ou la personne utilise un bouclié ou...)
	//  *
	//  * @param value
	//  * @return unsigned
	//  */
	// virtual unsigned receiveHealthCare(int value) override;
	// /**
	//  * @brief pour recevoir les soins Exp
	//  * Retourne les dégats réelemnt concidéré (au cas ou la personne utilise un bouclié ou...)
	//  *
	//  * @param value
	//  * @return unsigned
	//  */
	// virtual unsigned receiveExpCare(int value) override;
	// /**
	//  * @brief Pour activer la protection du bouclier.
	//  * Il faut noter que son activation est temporaire et protège la santé en diminuant l'ataque
	//  *
	//  * @param value
	//  */
	// virtual void receiveShieldboost(int value) override;

private:
	void init();
};

#endif // __SOLDIER_HPP__
