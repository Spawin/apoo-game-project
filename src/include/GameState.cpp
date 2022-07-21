#include "include/GameState.hpp"

using namespace std;

// Fonction static

// -------------------------- Fonctions d'initialisation ---------------------
void GameState::initDeferredRender()
{
	this->renderTexture.create(
		this->stateData->graphicsSettings->resolution.width,
		this->stateData->graphicsSettings->resolution.height);

	this->renderSprite.setTexture(this->renderTexture.getTexture());
	this->renderSprite.setTextureRect(
		sf::IntRect(
			0,
			0,
			this->stateData->graphicsSettings->resolution.width,
			this->stateData->graphicsSettings->resolution.height));
}

void GameState::initFonts()
{
	if (!this->font.loadFromFile("content/fonts/Dosis-Light.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD_NOT_LOAD_FONT");
	}
}

void GameState::initPauseMenu()
{
	const sf::VideoMode& vm = this->stateData->graphicsSettings->resolution;
	this->pauseMenu = new PauseMenu(this->stateData->graphicsSettings->resolution, this->font);

	this->pauseMenu->addButton("QUIT", gui::p2pY(74.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Quitter");
}

void GameState::initKeyTime()
{
	this->keyTimeMax = 0.5f;
	this->keyTimer.restart();
}

void GameState::initPlayer()
{
	cout << "Initialisation du joueur\n";
	this->player = new Player(new Soldier(true));
}

// Constructeurs/Destructeur
GameState::GameState(StateData* stateData) :
	State(stateData)
{
	this->initDeferredRender();
	// this->initView();
	// this->initKeybinds();
	this->initFonts();
	// this->initTextures();
	this->initPauseMenu();
	// this->initShaders();
	this->initKeyTime();
	// this->initDebugText();

	this->initPlayer();
	// this->initPlayerGUI();
	// this->initEnemySystem();
	// this->initTileMap();
	// this->initSystems();
}

GameState::~GameState()
{
	delete this->pauseMenu;
	delete this->player;
}

// Fonctions/Méthodes
// void GameState::endState()
// {
// 	cout << "Fin du game state\n";
// }

bool GameState::getKeyTime()
{
	if (this->keyTimer.getElapsedTime().asSeconds() >= this->keyTimeMax)
	{
		this->keyTimer.restart();
		return true;
	}

	return false;
}

void GameState::updateSFMLEvents(const sf::Event& sfEvent)
{
	if (sfEvent.type == sf::Event::KeyReleased)
	{
		if (sfEvent.key.code == sf::Keyboard::Escape)
		{
			// On switch l'état de la pause
			this->paused = !this->paused;
		}
	}
}

void GameState::updateInput(const float& deltaTime)
{
	if (deltaTime > 100.f)
	{
		// REVIEW -
	}
	// C'est ici on voit vraiment l'utilité du getKeyTime
	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->getKeyTime())
	// {
	// 	// On switch l'état de la pause
	// 	this->paused = !this->paused;
	// }

	// TODO - Ramener le controle du personnge à ce niveau ou dans player
	//* on ora un truc du genre this->player.move(...)
	// move est virtuel et appartiens à personnage
}

void GameState::updatePauseMenuButtons()
{
	if (this->pauseMenu->isButtonPressed("QUIT"))
		this->endState();
}

void GameState::update(const float& deltaTime)
{
	// this->updateSFMLEvents();
	this->updateMousePositions();
	this->updateKeytime(deltaTime);
	this->updateInput(deltaTime);

	if (!this->paused)
	{
		//* Le jeu n'est pas en pause
		this->player->update(deltaTime);
	}
	else
	{
		//* Le jeu est en pause
		cout << "En pause\n";
		this->pauseMenu->update(this->mousePosWindow);
		this->updatePauseMenuButtons();
	}
}

void GameState::render(sf::RenderTarget* target)
{
	// REVIEW -
	if (!target)
		target = this->window;

	this->player->render((*target));

	if (this->paused) //Pause menu render
	{
		//this->renderTexture.setView(this->renderTexture.getDefaultView());
		this->pauseMenu->render(this->renderTexture);

		//FINAL RENDER
		this->renderTexture.display();
		this->renderSprite.setTexture(this->renderTexture.getTexture());
		target->draw(this->renderSprite);
	}

	// //FINAL RENDER
	// this->renderTexture.display();
	// this->renderSprite.setTexture(this->renderTexture.getTexture());
	// target->draw(this->renderSprite);
}