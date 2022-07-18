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
	virtual void show(sf::RenderWindow& window) override;

	virtual void simpleAttack(Personage& target) override;
	virtual void specialAttack(Personage& target) override;

private:
	void init();
};

#endif // __SOLDIER_HPP__
