#include "include/GameState.hpp"

using namespace std;

// Fonction static

// Fonctions d'initialisation
void GameState::initPlayer()
{
	cout << "Initialisation du joueur\n";
	this->player = new Player(new Soldier(true));
}

// Constructeurs/Destructeur
GameState::GameState(StateData* stateData) :
	State(stateData)
{
	this->initPlayer();
}

GameState::~GameState()
{
	delete this->player;
}

// Fonctions/Méthodes
void GameState::endState()
{
	cout << "Fin du game state\n";
}

void GameState::updateInput(const float& deltaTime)
{
	cout << deltaTime << endl;
	this->checkForQuit();

	// TODO - Ramener le controle du personnge à ce niveau ou dans player
	//* on ora un truc du genre this->player.move(...)
	// move est virtuel et appartiens à personnage
}

void GameState::update(const float& deltaTime)
{
	this->updateMousePositions();
	this->updateInput(deltaTime);

	this->player->update(deltaTime);
}

void GameState::render(sf::RenderTarget* target)
{
	// REVIEW -
	if (!target)
		target = this->window;

	this->player->render((*target));
}