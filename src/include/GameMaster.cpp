#include "include/GameMaster.hpp"

using namespace std;

//
const sf::Vector2i GameMaster::m_spriteBoxCenter(17, 16);
int GameMaster::m_countInstance = 0;
GameMaster* GameMaster::m_gameMaster = nullptr;

//
void GameMaster::initGraphicsSettings()
{
	//
	this->graphicsSettings.loadFromFile("Config/window.ini");
}

void GameMaster::initWindow()
{
	this->window = new sf::RenderWindow();

	util::Platform platform;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window->getSystemHandle());

	sf::VideoMode vm = this->graphicsSettings.resolution;
	// Use the screenScalingFactor
	vm.width *= screenScalingFactor;
	vm.height *= screenScalingFactor;

	// Create the main window
	if (this->graphicsSettings.fullscreen)
	{
		window->create(vm, this->graphicsSettings.title, sf::Style::Fullscreen);
		// this->window = new sf::RenderWindow(
		// 	vm,
		// 	// this->graphicsSettings.resolution, //? vm à la place
		// 	this->graphicsSettings.title,
		// 	sf::Style::Fullscreen /*,
		// 	this->graphicsSettings.contextSettings*/
		// );
	}
	else
	{

		window->create(vm, this->graphicsSettings.title, sf::Style::Close);
		// this->window = new sf::RenderWindow(
		// 	vm,
		// 	// this->graphicsSettings.resolution, //? vm à la place
		// 	this->graphicsSettings.title,
		// 	sf::Style::Titlebar | sf::Style::Close /*,
		// 	this->graphicsSettings.contextSettings*/
		// );
	}

	this->window->setFramerateLimit(this->graphicsSettings.frameRateLimit);
	this->window->setVerticalSyncEnabled(this->graphicsSettings.verticalSync);

	platform.setIcon(window->getSystemHandle());

	// Initialisations de l'espace pour tous les éléments du jeux
	Position::initSpace((int)GameMap::getGAME_MAP_WIDTH, (int)GameMap::getGAME_MAP_HEIGHT);

	// Construction de la maison
	House house;
	if (!house.load("content/house.png", sf::Vector2u(32, 32), house.getDisposition(), 40, 80))
	{
		std::cerr << "Erreur chargement < content/Tiles.png >" << std::endl;
		return exit(-1);
	}

	/* TODO - C'est pour la partie GameState
	// Mise en place des vues
	// sf::View player_view(sf::Vector2f(350.f, 300.f), sf::Vector2f(1000.f, 600.f));
	sf::View player_view;
	// player_view.setCenter(sf::Vector2f(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f));
	player_view.setCenter(sf::Vector2f(32.f * 4.f, 32.f * 78.f));
	player_view.setSize(sf::Vector2f(GameMap::getGAME_MAP_WIDTH() / 2, GameMap::getGAME_MAP_HEIGHT() / 8));
	sf::View minimap_view;
	minimap_view.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));

	// activation de la vue
	window->setView(player_view);
	// window->setView(minimap_view);
	//*/

	// Personage* spawin = new Soldier(true);
	// // Personage spawin = Personage(true);
	// spawin->setGameObjectName("spawin");

	// Personage* p2 = new Soldier();

	// auto chrono = sf::Clock();
	// sf::Event event;
}

void GameMaster::intiStateData()
{
	this->stateData.window = this->window;
	this->stateData.graphicsSettings = &this->graphicsSettings;
	// this->stateData.supportedKeys = &this->supportedKeys;
	this->stateData.states = &this->states;
	// this->stateData.gridSize = this->gridSize;
}

void GameMaster::intiStates()
{
	this->states.push(new MainMenuState(&this->stateData));
	// this->states.push(new GameState(this->window));
}
// ---------------------------------------

GameMaster::GameMaster(/*util::Platform& platform*/)
{
	m_countInstance++;
	if (m_countInstance > 1)
	{
		cerr << "LE game master ne doit pas etre instancié plus d'une fois" << endl;
		exit(-1);
	}

	this->initGraphicsSettings();
	this->initWindow();
	this->intiStateData();
	this->intiStates();

	GameMaster::m_gameMaster = this;
}

GameMaster::~GameMaster()
{
	delete this->window;
	// delete spawin;
	// delete p2;

	// REVIEW -
	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

// ------------------------------------

const sf::Vector2i GameMaster::getSPRITE_BOX_CENTER()
{
	return m_spriteBoxCenter;
}

const GameMaster* GameMaster::GAME_MASTER()
{
	return m_gameMaster;
}

// -----------------------------------
void GameMaster::endApplication()
{
	cout << "fin application" << endl;
}

void GameMaster::updateDeltatime()
{
	this->deltaTime = this->dtClock.restart().asSeconds();
	// initialisation du time du game object
	GameObject::SetTime(this->deltaTime);
}
void GameMaster::updateSFMLEvents()
{

	while (this->window->pollEvent(this->sfEvent))
	{
		// Close window: exit
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();

		if (this->sfEvent.type == sf::Event::Resized)
		{
			// TODO -
		}
	}
}
void GameMaster::update()
{
	this->updateSFMLEvents();

	// Update items
	if (!this->states.empty())
	{
		this->states.top()->update(this->deltaTime);

		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	// Application end
	else
	{
		this->endApplication();
		this->window->close();
	}
}
void GameMaster::render()
{

	//// initialisation du time du game object
	//// GameObject::SetTime(chrono.restart().asSeconds());

	// Appel pour tester la proximité de chaque collider
	Collider::update();

	//* ANCHOR - Appel des update
	// spawin->update();
	// p2->update();

	// Clear screen
	this->window->clear(); // NOTE -
	// ----------------------
	// Render items
	if (!this->states.empty())
		this->states.top()->render(this->window);

	// ----------------------
	//* Affichage de la maison
	// this->window->draw(house);

	//* ANCHOR - Affichage des gameObjects
	// spawin->show(this->window);
	// p2->show(this->window);

	// Update the window
	this->window->display(); // NOTE -
}
void GameMaster::run()
{

	// Start the game loop
	while (this->window->isOpen())
	{
		this->updateDeltatime();
		this->update();
		this->render();
	}
}
