#if !defined(__DRUID_HPP__)
	#define __DRUID_HPP__

	#include "include/Personage.hpp"

class Personage;

class Druid : public Personage
{
public:
	Druid();
	~Druid();

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

#endif // __DRUID_HPP__
