#include "include/State.hpp"
// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
State::State(StateData* stateData)
{
	this->stateData = stateData;
	this->window = stateData->window;
	this->states = stateData->states;
	this->quit = false;
	this->paused = false;
}

State::~State()
{}

// Fonctions/Méthodes
void State::endState()
{
	this->quit = true;
}

const bool& State::getQuit() const
{
	return this->quit;
}

// void State::checkForQuit()
// {
// 	// TODO -
// 	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
// 	{
// 		this->quit = true;
// 	}
// }

void State::updateMousePositions()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}