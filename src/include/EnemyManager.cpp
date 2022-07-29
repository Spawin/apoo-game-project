#include "include/EnemyManager.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		delete this->enemies[i].enemy;
	}
}

// Fonctions/Méthodes
void EnemyManager::createEnemy()
{}

void EnemyManager::removeEnemy(const int index)
{
	try
	{
		delete this->enemies[index].enemy;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "ERROR::ENEMYMANAGER::REMOVEENEMY::..."
				  << "\n";
	}
	this->enemies.erase(this->enemies.begin() + index);
}

void EnemyManager::updateEnemiesState(sf::Vector2f const& playerCoordinates)
{
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].active = this->enemies[i].enemy->getPersonage()->getActualHall()->isIn(playerCoordinates);
	}
}

void EnemyManager::update(const float& deltatime)
{
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		if (this->enemies[i].active)
		{
			this->enemies[i].enemy->update(deltatime);
		}
	}
}

void EnemyManager::render(sf::RenderTarget& target)
{
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		if (this->enemies[i].active)
		{
			this->enemies[i].enemy->render(target);
		}
	}
}
