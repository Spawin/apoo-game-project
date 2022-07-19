#include "include/State.hpp"
// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
State::State(sf::RenderWindow* window) :
	window(window),
	quit(false)
{}
State::~State()
{}

// Fonctions/Méthodes
const bool& State::getQuit() const
{
	return this->quit;
}
void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}