#include "include/GameState.hpp"
#include "include/Gui.hpp"
#include "include/House.hpp"
#include "include/Inventory.hpp"
#include "include/Lounge.hpp"
#include "include/MovableGameObject.hpp"
#include "include/Room.hpp"
#include "include/Soldier.hpp"
#include "include/consts.hpp"

using namespace std;

class House;
class Lounge;
class MovableGameObject;
class Room;
class Soldier;
class Inventory;

// REVIEW -
namespace gui
{
// float p2pX(const float perc, const sf::VideoMode& vm);
// float p2pY(const float perc, const sf::VideoMode& vm);
} // namespace gui

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
	this->pauseMenu->addButton("QUIT", gui::p2pY(84.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Quitter");
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

void GameState::initPlayer()
{
	cout << "Initialisation du joueur\n";
	this->player = new Player(new Soldier(true)); // REVIEW -

	// On ajoute le joueur dans la salle de départ
	this->halls[0]->addMovableGameObject(this->player->getPersonage());

	// On informe le joueur qu'il se trouve dans la salle de départ
	this->player->getPersonage()->addToHall(this->halls[0]);

	// On place le joueur dans la salle de départ!
	this->player->getPersonage()->getNonConstPosition()->setPosition(game::GAME_BLOCKS_WIDTH * 4, game::GAME_BLOCKS_WIDTH * 78);

	// this->testEnemy = new Enemy(new Soldier());
	// this->halls[0]->addMovableGameObject(this->testEnemy->getPersonage());
	// this->testEnemy->getPersonage()->addToHall(this->halls[0]);
	// // this->testEnemy->getNonConstPosition()->setPosition(game::GAME_BLOCKS_WIDTH * 4, game::GAME_BLOCKS_WIDTH * 78); // REVIEW -
	// MyVector v { game::GAME_BLOCKS_WIDTH * 4, game::GAME_BLOCKS_WIDTH * 76 };
	// this->testEnemy->getPersonage()->move(v); // REVIEW -
}

void GameState::initEnemyManager()
{
	this->enemyManager = new EnemyManager(this->halls);
	this->enemyManager->createEnemy();
}

void GameState::initDoors()
{
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
	this->initHalls();
	this->initPlayer();
	// this->initPlayerGUI();
	this->initEnemyManager();
	// this->initTileMap();
	// this->initSystems();
	this->initDoors();
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

	// delete this->testEnemy;
	delete this->enemyManager;
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

		// this->testEnemy->update(deltaTime);
		this->enemyManager->updateEnemiesState(this->player->getPosition());
		this->enemyManager->update(deltaTime);
	}
	else
	{
		//* Le jeu est en pause
		// cout << "En pause\n";
		this->pauseMenu->update(this->mousePosWindow);
		this->updatePauseMenuButtons();
		this->player->updateMousePosWindow(this->mousePosWindow);
	}

	// gui::Inventory::updateMousePosWindow(this->mousePosWindow);
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

	// On dessine la piece actuelle ou le joueur se trouve ( ici c'est juste les élément à l'intérieur et autre )
	for (auto&& hall : this->halls)
	{
		if (hall->isIn(this->player->getPosition()))
		{
			hall->render(renderTexture);

			for (auto&& pair : Inventory::getNotInventoriedItemsNonConst())
			{
				for (auto&& pair2 : pair.second)
				{
					if (hall->isIn(pair2.second->getPosition()->getPosition()))
					{
						// On recupère la vue pour calculer le décalage par rapport à la souri
						this->renderTexture.getView();
						// REVIEW - Remplacer cesv valeurs crées
						sf::Vector2f v(this->renderTexture.getView().getCenter());
						sf::Vector2f s(this->renderTexture.getView().getSize());

						// On affiche et  on met à jour les évène ment de clique
						if (!this->paused)
							pair2.second->updateMousePosWindow(sf::Vector2i(this->mousePosWindow.x + v.x - s.x / 2.f, this->mousePosWindow.y + v.y - s.y / 2.f));
						pair2.second->show(renderTexture);

						// True indique que le joeur à cliqué sur l'item
						if (pair2.second->playerMustTake())
						{
							// On ajoute l'item à l'inventaire du joueur
							if (this->player->getPersonage()->addItem(pair2.second, pair.first, sf::Vector2f()))
							{
								pair2.second->resetMustTake();

								// On retire l'item de la liste globale
								Inventory::getNotInventoriedItemsNonConst()[pair.first].erase(pair2.second->getGameObjectId());

								// On casse la boucle pour éviter des soucis car on a modifier la map...
								break;
							}
						}
					}
				}
			}

			// On casse la boucle car il ne peut se trouver que dans une piece à la fois...
			break;
		}
	}

	// this->player->render((*target));
	this->player->render(this->renderTexture);

	// this->testEnemy->render(this->renderTexture);
	this->enemyManager->render(this->renderTexture);

	if (this->paused) //Pause menu render
	{
		//this->renderTexture.setView(this->renderTexture.getDefaultView());
		this->pauseMenu->render(this->renderTexture);

		// //FINAL RENDER
		// this->renderTexture.display();
		// this->renderSprite.setTexture(this->renderTexture.getTexture());
		// target->draw(this->renderSprite);

		this->player->getPersonage()->renderBagInventory(this->renderTexture);
	}

	//FINAL RENDER
	this->renderTexture.display();
	this->renderSprite.setTexture(this->renderTexture.getTexture());
	target->draw(this->renderSprite);
}
