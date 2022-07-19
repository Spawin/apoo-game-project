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
	#include "include/Personage.hpp"

	#include <stack> // REVIEW -
	#include <map>

class State
{
public:
	// Constructeurs/Destructeur
	State(sf::RenderWindow* window);
	virtual ~State();
	// Fonctions/Méthodes
	const bool& getQuit() const;
	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void updateKeyBinds(const float& deltaTime) = 0;
	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

private:
	// Variables
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

	// Fonctions d'initialisation
};

#endif // __STATE_HPP__
