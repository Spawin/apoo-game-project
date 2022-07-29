#if !defined(__ENEMY_MANAGER_HPP__)
	#define __ENEMY_MANAGER_HPP__

	#include "include/Enemy.hpp"
	#include <vector>

class Enemy;

struct EnemyData
{
	/**
	 * @brief Est vrai si l'énémi se trouve dans la meme salle que le joueur
	 *
	 */
	bool active;
	Enemy* enemy;
};

class EnemyManager
{
public:
	// Constructeurs/Destructeur
	EnemyManager();
	~EnemyManager();

	// Fonctions/Méthodes
	void createEnemy();
	void removeEnemy(const int index);

	/**
	 * @brief Pour rendre actif les énemis qui se trouve dans la même sale que le joueur.
	 *
	 * @param playerCoordinates
	 */
	void updateEnemiesState(sf::Vector2f const& playerCoordinates);
	void update(const float& deltatime);
	void render(sf::RenderTarget& target);

private:
	// Variables
	std::vector<EnemyData> enemies;

	// Fonctions d'initialisation
};

#endif // __ENEMY_MANAGER_HPP__
