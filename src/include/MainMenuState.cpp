#include "include/MainMenuState.hpp"

using namespace std;

// Fonction static

// Fonctions d'initialisation
// void MainMenuState::initFonts(){}
void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("content/fonts/Dosis-Light.ttf"))
	{
		throw("ERROR::MAIN_MENU_STATE::COULD_NOT_LOAD_FONT");
	}
}

// void MainMenuState::initFonts(){}

void MainMenuState::initGui()
{
	const sf::VideoMode& vm = sf::VideoMode::getDesktopMode(); // REVIEW -

	//* Background
	this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	if (!this->backgroundTexture.loadFromFile("content/backgrounds/bg1.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);
	// this->background.setScale();
	// this->background.setFillColor(sf::Color::Magenta);
	// this->background.setPosition(this->window->getView().getCenter().x - this->window->getSize().x / 2, this->window->getView().getCenter().y - this->window->getSize().y / 2);

	//* Buttons
	this->buttons["GAME_STATE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(30.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), &this->font,
		"Nouvelle partie", //
		gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200),
		sf::Color(255, 255, 255, 255),
		sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0),
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0));

	this->buttons["SETTINGS_STATE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(40.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), &this->font,
		"Param", //
		gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200),
		sf::Color(255, 255, 255, 255),
		sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0),
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0));

	//*
	this->buttons["EDITOR_STATE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(50.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), &this->font,
		"...", //
		gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200),
		sf::Color(255, 255, 255, 255),
		sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0),
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0));
	//*/

	this->buttons["EXIT_STATE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(65.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), &this->font,
		"Quitter", //
		gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200),
		sf::Color(255, 255, 255, 255),
		sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0),
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0));
}

void MainMenuState::resetGui()
{}

// Constructeurs/Destructeur
MainMenuState::MainMenuState(StateData* stateData) :
	State(stateData)
{
	// this->initVariables();
	this->initFonts();
	// this->initKeybinds();
	this->initGui();
	// this->resetGui();
}

MainMenuState::~MainMenuState()
{
	// auto it = this->buttons.begin();
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

// Fonctions/Méthodes
// void MainMenuState::endState()
// {
// 	cout << "Fin du Main menu state\n";
// }

void MainMenuState::updateInput(const float& deltaTime)
{
	cout << deltaTime << endl;
	// this->checkForQuit();
}

void MainMenuState::updateButtons()
{
	/*Updates all the buttons in the state and handles their functionlaity.*/

	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosWindow);
	}

	//New game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->stateData));
	}

	//Settings
	if (this->buttons["SETTINGS_STATE"]->isPressed())
	{
		// this->states->push(new SettingsState(this->stateData));
	}

	//Editor
	if (this->buttons["EDITOR_STATE"]->isPressed())
	{
		// this->states->push(new EditorState(this->stateData));
	}

	//Quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
	}
}

void MainMenuState::update(const float& deltaTime)
{
	this->updateMousePositions();
	this->updateInput(deltaTime);

	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	// REVIEW -
	if (!target)
		target = this->window;

	cout << "Ecran : x" << this->window->getView().getCenter().x << " y" << this->window->getView().getCenter().y;

	target->draw(this->background);

	this->renderButtons(*target);
}
