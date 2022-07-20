#if !defined(__STATE_HPP__)
	#define __STATE_HPP__

	#include "Platform/Platform.hpp"
	#include "include/Position.hpp"
	#include "include/GameMap.hpp"
	#include "include/consts.hpp"
	#include <memory>
	#include <vector>
	#include <fstream>
	#include <sstream>
	#include "include/House.hpp"
	#include "include/Soldier.hpp"
	#include "include/Collider.hpp"
	#include "include/Player.hpp"
	#include "include/Personage.hpp"
	#include <stack>
	#include <map>

class State;

struct StateData
{
	float gridSize;
	sf::RenderWindow* window;
	// GraphicsSettings* gfxSettings;
	// std::map<std::string, int>* supportedKeys;
	std::stack<State*>* states;
};

class State
{
public:
	// Constructeurs/Destructeur
	State(StateData* stateData);
	virtual ~State();
	// Fonctions/Méthodes
	const bool& getQuit() const;

	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void updateMousePositions();
	virtual void updateInput(const float& deltaTime) = 0;
	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

protected:
	// Variables
	StateData* stateData;
	std::stack<State*>* states;
	sf::RenderWindow* window;

	bool quit;
	bool paused;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	std::vector<sf::Texture> textures;

	// Fonctions d'initialisation
};

#endif // __STATE_HPP__
