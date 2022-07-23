#if !defined(__GAME_MASTER__)
	#define __GAME_MASTER__

	#include "include/GameState.hpp"
	#include "include/MainMenuState.hpp"
	#include "include/consts.hpp"

class GameMaster
{
public:
	GameMaster(/*util::Platform& platform*/);
	~GameMaster();

	// Fonctions
	void endApplication();

	void updateDeltatime();
	void updateSFMLEvents();
	void update();
	void render();
	// Core
	void run();

	//
	//
	//
	//
	//
	//
	//
	//
	static const GameMaster* GAME_MASTER();
	static const sf::Vector2i getSPRITE_BOX_CENTER();
	static float getSCREEN_SCALING_FACTOR();

private:
	// Variables
	GraphicsSettings graphicsSettings;
	StateData stateData;
	sf::RenderWindow* window;
	sf::Event sfEvent;

	// util::Platform platform;

	sf::Clock dtClock;
	float deltaTime;

	std::stack<State*> states;

	// Initialisation
	void initGraphicsSettings();
	void initWindow();
	void intiStateData();
	void intiStates();
	//
	//
	//
	//
	static int m_countInstance;
	// L'objet gameMaster actuel
	static GameMaster* m_gameMaster;

	// std::vector<std::shared_ptr<sf::Texture>> textures;
	/**
	 * @brief Coordonnées du centre des carrés de sprite 32x32
	 *
	 */
	static const sf::Vector2i m_spriteBoxCenter;

	static float screenScalingFactor;

	// Texture des éléments du jeu
	sf::Texture m_gameTexture;
};

#endif // __GAME_MASTER__
