#if !defined(__GAME_STATE_HPP__)
	#define __GAME_STATE_HPP__

	#include "include/State.hpp"
	#include "include/PauseMenu.hpp"
	#include "include/GameMap.hpp"
	#include "include/Hall.hpp"
	#include <vector>
	#include "include/Enemy.hpp"
	#include "include/EnemyManager.hpp"
	#include "include/Player.hpp"

class State;
class PauseMenu;
class GameMap;
class Hall;
class Enemy;
class EnemyManager;
class Player;

struct StateData;

class GameState : public State
{

public:
	// Constructeurs/Destructeur
	GameState(StateData* stateData);
	virtual ~GameState();

	// Fonctions/Méthodes
	// void endState() override;
	bool getKeyTime() override;

	virtual void updateSFMLEvents(const sf::Event& sfEvent) override;
	void updateInput(const float& deltaTime) override;
	void updatePauseMenuButtons();

	void update(const float& deltaTime) override;
	void render(sf::RenderTarget* target = nullptr) override;

private:
	// Variables
	sf::View view;
	sf::RenderTexture renderTexture;
	sf::Sprite renderSprite;
	sf::Font font;

	// Pour gérer le temps d'apuis sur les touches
	sf::Clock keyTimer;
	// Temps de réponse pour une touche
	float keyTimeMax;

	Player* player;

	// Enemy* testEnemy;
	EnemyManager* enemyManager;

	PauseMenu* pauseMenu;

	GameMap* gameMap;

	std::vector<Hall*> halls;

	// Fonctions d'initialisation
	void initDeferredRender();
	void initFonts();
	void initPauseMenu();
	void initKeyTime();

	void initGameMap();
	void initHalls();
	void initPlayer();
	void initEnemyManager();
	void initDoors();
};

#endif // __GAME_STATE_HPP__
