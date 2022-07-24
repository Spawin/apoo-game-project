#include "include/PauseMenu.hpp"
// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
PauseMenu::PauseMenu(sf::VideoMode& vm, sf::Font& font) :
	font(font)
{
	std::cout << "Pause menu : w=" << vm.width << " h=" << vm.height << std::endl;

	//Init background
	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(vm.width),
			static_cast<float>(vm.height)));
	this->background.setFillColor(sf::Color(20, 20, 20, 100));
	// this->background.setFillColor(sf::Color(255, 255, 255, 100));

	//Init container
	this->container.setSize(
		sf::Vector2f(
			static_cast<float>(vm.width) / 4.f,
			static_cast<float>(vm.height) - gui::p2pY(9.3f, vm)));
	this->container.setFillColor(sf::Color(20, 20, 20, 200));
	this->container.setPosition(
		static_cast<float>(vm.width) / 2.f - this->container.getSize().x / 2.f,
		30.f);

	//Init text
	this->menuText.setFont(font);
	this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
	this->menuText.setCharacterSize(gui::calcCharSize(vm));
	this->menuText.setString("PAUSED");
	this->menuText.setPosition(
		this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		this->container.getPosition().y + gui::p2pY(4.f, vm));
}

PauseMenu::~PauseMenu()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

// Fonctions/Méthodes

std::map<std::string, gui::Button*>& PauseMenu::getButtons()
{
	return this->buttons;
}

bool PauseMenu::isButtonPressed(const std::string key)
{
	return this->buttons[key]->isPressed();
}

void PauseMenu::addButton(
	const std::string key,
	const float y,
	const float width,
	const float height,
	const unsigned char_size,
	const std::string text)
{
	float x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;

	this->buttons[key] = new gui::Button(
		x, y, width, height, &this->font, text, char_size, sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50), sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void PauseMenu::update(const sf::Vector2i& mousePosView)
{
	for (auto& i : this->buttons)
	{
		i.second->update(mousePosView);
	}
}

void PauseMenu::render(sf::RenderTarget& target)
{
	this->setGraphicsElementPosition(target.getView());
	// std::cout << "view center : x=" << target.getView().getCenter().x << " y=" << target.getView().getCenter().y << std::endl;
	// std::cout << "view size : x=" << target.getView().getSize().x << " y=" << target.getView().getSize().y << std::endl;
	// std::cout << "background center : x=" << this->background.getPosition().x << " y=" << this->background.getPosition().y << std::endl;
	// std::cout << "container center : x=" << this->container.getPosition().x << " y=" << this->container.getPosition().y << std::endl;

	target.draw(this->background);
	target.draw(this->container);

	for (auto& i : this->buttons)
	{
		i.second->render(target);
	}

	target.draw(this->menuText);
}

void PauseMenu::setGraphicsElementPosition(sf::View const& view)
{
	sf::Vector2f v(view.getCenter());
	sf::Vector2f s(view.getSize());

	// On calcul le décallage du centre de la vue
	float addX(v.x - s.x / 2.f);
	float addY(v.y - s.y / 2.f);

	// On ajoute aux positions initiales (quand le centre de la vue est0:0) anciennement calculé dans le constructeur
	this->background.setPosition(0.f + addX, 0.f + addY);
	this->container.setPosition(s.x * 3.f / 8.f + addX, 30.f + addY);
	this->menuText.setPosition(
		this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		this->container.getPosition().y + std::floor(s.y * (4.f / 100.f)));

	for (auto& i : this->buttons)
	{
		// i.second->setPosition(i.second->getPosition().x + addX, i.second->getPosition().y + addY);
		i.second->setPosition((this->container.getPosition().x + this->container.getSize().x / 2.f - std::floor(s.x * (13.f / 100.f)) / 2.f), std::floor(s.y * (74.f / 100.f)) + addY, addX, addY);
	}
}
