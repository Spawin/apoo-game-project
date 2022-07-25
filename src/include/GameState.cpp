#include "include/GameState.hpp"
#include "include/Lounge.hpp"
#include "include/Room.hpp"
#include "include/consts.hpp"

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
	// cout << "init menu y=" << gui::p2pY(74.f, vm) << endl;
	this->pauseMenu->addButton("QUIT", gui::p2pY(74.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Quitter");
}

void GameState::initKeyTime()
{
	this->keyTimeMax = 0.5f;
	this->keyTimer.restart();
}

void GameState::initGameMap()
{
	// REVIEW - Charger les textures à partir d'ici
	this->gameMap = new House();

	if (!this->gameMap->load("content/house/house.png", sf::Vector2u(game::GAME_BLOCKS_WIDTH, game::GAME_BLOCKS_WIDTH), this->gameMap->getDisposition(), 40, 80))
	{
		std::cerr << "Erreur chargement < content/Tiles.png >" << std::endl;
		return exit(-1);
	}
}

void GameState::initPlayer()
{
	cout << "Initialisation du joueur\n";
	this->player = new Player(new Soldier(true));
}

void GameState::initHalls()
{
	// 0
	this->halls.push_back(new Lounge(sf::Vector2i(1 * game::GAME_BLOCKS_WIDTH / 2, 67 * game::GAME_BLOCKS_WIDTH), 38 * game::GAME_BLOCKS_WIDTH + game::GAME_BLOCKS_WIDTH, (12 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));

	// 1
	this->halls.push_back(new Room(sf::Vector2i(1 * game::GAME_BLOCKS_WIDTH / 2, 56 * game::GAME_BLOCKS_WIDTH), 13 * game::GAME_BLOCKS_WIDTH + game::GAME_BLOCKS_WIDTH / 2 + game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));
	this->halls.push_back(new Room(sf::Vector2i(15 * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT, 56 * game::GAME_BLOCKS_WIDTH), 10 * game::GAME_BLOCKS_WIDTH + 2 * game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));
	this->halls.push_back(new Room(sf::Vector2i(26 * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT, 56 * game::GAME_BLOCKS_WIDTH), 13 * game::GAME_BLOCKS_WIDTH + game::GAME_BLOCKS_WIDTH / 2 + game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));

	// 2
	this->halls.push_back(new Room(sf::Vector2i(1 * game::GAME_BLOCKS_WIDTH / 2, 45 * game::GAME_BLOCKS_WIDTH), 13 * game::GAME_BLOCKS_WIDTH + game::GAME_BLOCKS_WIDTH / 2 + game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));
	this->halls.push_back(new Room(sf::Vector2i(15 * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT, 45 * game::GAME_BLOCKS_WIDTH), 10 * game::GAME_BLOCKS_WIDTH + 2 * game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));
	this->halls.push_back(new Room(sf::Vector2i(26 * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT, 45 * game::GAME_BLOCKS_WIDTH), 13 * game::GAME_BLOCKS_WIDTH + game::GAME_BLOCKS_WIDTH / 2 + game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));

	// 3
	this->halls.push_back(new Room(sf::Vector2i(1 * game::GAME_BLOCKS_WIDTH / 2, 34 * game::GAME_BLOCKS_WIDTH), 13 * game::GAME_BLOCKS_WIDTH + game::GAME_BLOCKS_WIDTH / 2 + game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));
	this->halls.push_back(new Room(sf::Vector2i(15 * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT, 34 * game::GAME_BLOCKS_WIDTH), 10 * game::GAME_BLOCKS_WIDTH + 2 * game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));
	this->halls.push_back(new Room(sf::Vector2i(26 * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT, 34 * game::GAME_BLOCKS_WIDTH), 13 * game::GAME_BLOCKS_WIDTH + game::GAME_BLOCKS_WIDTH / 2 + game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));

	// 4
	this->halls.push_back(new Room(sf::Vector2i(1 * game::GAME_BLOCKS_WIDTH / 2, 23 * game::GAME_BLOCKS_WIDTH), 13 * game::GAME_BLOCKS_WIDTH + game::GAME_BLOCKS_WIDTH / 2 + game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));
	this->halls.push_back(new Room(sf::Vector2i(15 * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT, 23 * game::GAME_BLOCKS_WIDTH), 10 * game::GAME_BLOCKS_WIDTH + 2 * game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));
	this->halls.push_back(new Room(sf::Vector2i(26 * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT, 23 * game::GAME_BLOCKS_WIDTH), 13 * game::GAME_BLOCKS_WIDTH + game::GAME_BLOCKS_WIDTH / 2 + game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));

	// 5
	this->halls.push_back(new Room(sf::Vector2i(1 * game::GAME_BLOCKS_WIDTH / 2, 12 * game::GAME_BLOCKS_WIDTH), 13 * game::GAME_BLOCKS_WIDTH + game::GAME_BLOCKS_WIDTH / 2 + game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));
	this->halls.push_back(new Room(sf::Vector2i(15 * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT, 12 * game::GAME_BLOCKS_WIDTH), 10 * game::GAME_BLOCKS_WIDTH + 2 * game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));
	this->halls.push_back(new Room(sf::Vector2i(26 * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT, 12 * game::GAME_BLOCKS_WIDTH), 13 * game::GAME_BLOCKS_WIDTH + game::GAME_BLOCKS_WIDTH / 2 + game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));

	// 6
	this->halls.push_back(new Room(sf::Vector2i(1 * game::GAME_BLOCKS_WIDTH / 2, 1 * game::GAME_BLOCKS_WIDTH), 13 * game::GAME_BLOCKS_WIDTH + game::GAME_BLOCKS_WIDTH / 2 + game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));
	this->halls.push_back(new Room(sf::Vector2i(15 * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT, 1 * game::GAME_BLOCKS_WIDTH), 10 * game::GAME_BLOCKS_WIDTH + 2 * game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));
	this->halls.push_back(new Room(sf::Vector2i(26 * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT, 1 * game::GAME_BLOCKS_WIDTH), 13 * game::GAME_BLOCKS_WIDTH + game::GAME_BLOCKS_WIDTH / 2 + game::WALL_HEIGHT, (10 + 1) * game::GAME_BLOCKS_WIDTH - game::WALL_HEIGHT));
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

	this->initGameMap();
	this->initPlayer();
	// this->initPlayerGUI();
	// this->initEnemySystem();
	// this->initTileMap();
	// this->initSystems();

	this->initHalls();
}

GameState::~GameState()
{
	delete this->pauseMenu;
	delete this->player;
	delete this->gameMap;

	for (int i = this->halls.size() - 1; i >= 0; i--)
	{
		delete this->halls[i];
	}
	this->halls.clear();
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

	// Si le fenêtre perd le focus, on met en pause.
	if (sfEvent.type == sf::Event::LostFocus)
	{
		this->paused = true;
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
		// cout << "En pause\n";
		this->pauseMenu->update(this->mousePosWindow);
		this->updatePauseMenuButtons();
	}
}

void GameState::render(sf::RenderTarget* target)
{
	// REVIEW -
	if (!target)
		target = this->window;

	// On éfface
	this->renderTexture.clear();

	// On rend la maison
	// this->gameMap->render(this->renderTexture, this->player->getPosition());
	renderTexture.draw(*this->gameMap);

#if defined(_DEBUG)
	// On affiche les bords des pièces
	for (auto&& hall : this->halls)
	{
		if (hall->isIn(this->player->getPosition()))
		{
			hall->render(renderTexture);
		}
	}
#endif

	// this->player->render((*target));
	this->player->render(this->renderTexture);

	if (this->paused) //Pause menu render
	{
		//this->renderTexture.setView(this->renderTexture.getDefaultView());
		this->pauseMenu->render(this->renderTexture);

		// //FINAL RENDER
		// this->renderTexture.display();
		// this->renderSprite.setTexture(this->renderTexture.getTexture());
		// target->draw(this->renderSprite);
	}

	//FINAL RENDER
	this->renderTexture.display();
	this->renderSprite.setTexture(this->renderTexture.getTexture());
	target->draw(this->renderSprite);
}
