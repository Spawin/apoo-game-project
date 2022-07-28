#if !defined(__GAME_STATE_HPP__)
	#define __GAME_STATE_HPP__

	#include "include/State.hpp"
	#include "include/PauseMenu.hpp"
	#include "include/GameMap.hpp"
	#include "include/Hall.hpp"
	#include <vector>

class State;
class PauseMenu;
class GameMap;
class Hall;

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

	PauseMenu* pauseMenu;

	GameMap* gameMap;

	std::vector<Hall*> halls;

	// Fonctions d'initialisation
	void initDeferredRender();
	void initFonts();
	void initPauseMenu();
	void initKeyTime();

	void initGameMap();
	void initPlayer();
	void initHalls();
};

#endif // __GAME_STATE_HPP__
