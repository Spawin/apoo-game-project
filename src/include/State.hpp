#if !defined(__STATE_HPP__)
	#define __STATE_HPP__

	#include "Platform/Platform.hpp"
	#include <memory>
	#include <vector>
	#include <fstream>
	#include <sstream>
	#include "include/GraphicsSettings.hpp"
	#include <stack>
	#include <map>
// #include "include/Position.hpp"
// #include "include/GameMap.hpp"
// #include "include/consts.hpp"
// #include "include/MyVector.hpp"
// #include "include/House.hpp"
// #include "include/Soldier.hpp"
// #include "include/Collider.hpp"
// #include "include/Player.hpp"
// #include "include/Personage.hpp"

class State;
class GraphicsSettings;

struct StateData
{
	float gridSize;
	sf::RenderWindow* window;
	GraphicsSettings* graphicsSettings;
	// std::map<std::string, int>* supportedKeys;
	std::stack<State*>* states;
	// Dosis-Light.ttf
	sf::Font defaultFont;
};

class State
{
public:
	// Constructeurs/Destructeur
	State(StateData* stateData);
	virtual ~State();
	// Fonctions/Méthodes
	const bool& getQuit() const;
	virtual bool getKeyTime();
	/**
	 * @brief Retourne le <screenScalingFactor>
	 * fournit par le stateData...
	 *
	 * @return float const&
	 */
	float const& scScF();

	// virtual void checkForQuit();
	virtual void updateSFMLEvents(const sf::Event& sfEvent) = 0;

	virtual void endState();
	virtual void updateMousePositions();
	virtual void updateKeytime(const float& deltaTime);
	virtual void updateInput(const float& deltaTime) = 0;
	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

protected:
	// Variables
	StateData* stateData;
	std::stack<State*>* states;
	sf::RenderWindow* window;

	// sf::Event sfEvent;

	bool quit;
	bool paused;
	float keytime;
	float keytimeMax;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	std::map<std::string, sf::Texture> textures;

	// Fonctions d'initialisation
};

#endif // __STATE_HPP__
