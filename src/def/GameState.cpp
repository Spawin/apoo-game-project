#include "include/GameState.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
GameState::GameState(sf::RenderWindow* window) :
	State(window)
{
}

GameState::~GameState()
{
}

// Fonctions/Méthodes
void GameState::endState()
{
	//
}
void GameState::updateKeyBinds(const float& deltaTime)
{
	std::cout << deltaTime << std::endl;
	this->checkForQuit();
}
void GameState::update(const float& deltaTime)
{
	this->updateKeyBinds(deltaTime);
}
void GameState::render(sf::RenderTarget* target)
{
	std::cout << target->getSize().x << std::endl;
}