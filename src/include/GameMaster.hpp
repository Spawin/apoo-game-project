#if !defined(__GAME_MASTER__)
	#define __GAME_MASTER__

	#include "include/GameState.hpp"
	#include "include/MainMenuState.hpp"

class GameMaster
{
public:
	GameMaster();
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

private:
	// Variables
	StateData stateData;
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float deltaTime;

	std::stack<State*> states;

	// Initialisation
	void initWindow();
	void intiStateData();
	void intiStates();
	//
	//
	//
	//
	static int m_countInstance;
	// Retourne l'objet gameMaster actuel
	static GameMaster* m_gameMaster;

	// std::vector<std::shared_ptr<sf::Texture>> textures;
	/**
	 * @brief Coordonnées du centre des carrés de sprite 32x32
	 *
	 */
	static const sf::Vector2i m_spriteBoxCenter;

	// Texture des éléments du jeu
	sf::Texture m_gameTexture;
};

#endif // __GAME_MASTER__
