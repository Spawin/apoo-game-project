#include "include/Gui.hpp"
#include "consts.hpp"
#include <algorithm>
#include <math.h>

// REVIEW -
float gui::p2pX(const float perc, const sf::VideoMode& vm)
{
	/*
	 * Converts a percentage value to pixels relative to the current resolution in the x-axis.
	 *
	 * @param		float perc				The percentage value.
	 * @param		sf::VideoMode& vm		The current videomode of the window (resolution).
	 *
	 * @return		float					The calculated pixel value.
	 */

	return std::floor(static_cast<float>(vm.width) * (perc / 100.f));
}

float gui::p2pY(const float perc, const sf::VideoMode& vm)
{
	/*
	 * Converts a percentage value to pixels relative to the current resolution in the y-axis.
	 *
	 * @param		float perc				The percentage value.
	 * @param		sf::VideoMode& vm		The current videomode of the window (resolution).
	 *
	 * @return		float					The calculated pixel value.
	 */

	return std::floor(static_cast<float>(vm.height) * (perc / 100.f));
}

unsigned gui::calcCharSize(const sf::VideoMode& vm, const unsigned modifier)
{
	/*
	 * Calculates the character size for text using the current resolution and a constant.
	 *
	 * @param		sf::VideoMode& vm		The current videomode of the window (resolution).
	 * @param		unsigned modifier		Used to modify the character size in a more custom way.
	 *
	 * @return		unsigned				The calculated character size value.
	 */

	return static_cast<unsigned>((vm.width + vm.height) / modifier);
}

// ********************************* Button

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
gui::Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, unsigned characterSize,
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor,
	sf::Color outline_idle_color, sf::Color outline_hover_color, sf::Color outline_active_color, short unsigned id)
{
	this->buttonState = BTN_IDLE;
	this->id = id;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(idleColor);
	this->shape.setOutlineThickness(1.f);
	this->shape.setOutlineColor(outline_idle_color);

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(text_idle_color);
	this->text.setCharacterSize(characterSize);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		// this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f);
		this->shape.getPosition().y);

	this->textIdleColor = text_idle_color;
	this->textHoverColor = text_hover_color;
	this->textActiveColor = text_active_color;

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->outlineIdleColor = outline_idle_color;
	this->outlineHoverColor = outline_hover_color;
	this->outlineActiveColor = outline_active_color;

	this->offset = sf::Vector2f(0.f, 0.f);
}

gui::Button::~Button()
{
}

// Fonctions/Méthodes
bool gui::Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
		return true;

	return false;
}

const std::string gui::Button::getText() const
{
	return this->text.getString();
}

const short unsigned& gui::Button::getId() const
{
	return this->id;
}

void gui::Button::setText(const std::string text)
{
	this->text.setString(text);
}

void gui::Button::setId(const short unsigned id)
{
	this->id = id;
}

const sf::Vector2f& gui::Button::getPosition() const
{
	return this->shape.getPosition();
}

void gui::Button::setPosition(float x, float y, float addX, float addY)
{
	// std::cout << "Param Pos : x=" << x << " y=" << y << std::endl;
	this->shape.setPosition(x, y);
	// std::cout << "Shape Pos : x=" << this->shape.getPosition().x << " y=" << this->shape.getPosition().y << std::endl;
	// std::cout << "Shape getGlobalBounds : x=" << this->shape.getPosition().x << " y=" << this->shape.getPosition().y << std::endl;
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y);

	this->offset = sf::Vector2f(addX, addY);
}

void gui::Button::update(const sf::Vector2i& mousePosWindow)
{

	// std::cout << "Position de la souris " << mousePosWindow.x << " " << mousePosWindow.y << std::endl;
	// std::cout << "Position du shape " << this->shape.getPosition().x << " " << this->shape.getPosition().y << std::endl;
	// Idle
	this->buttonState = BTN_IDLE;

	// Hover
	if (this->shape.getGlobalBounds().contains(mousePosWindow.x + this->offset.x, mousePosWindow.y + this->offset.y)) // NOTE - On a ajouter la position du shape pour tenir compte des décalage lors de l'affichage du menu dans certaines vues
	{
		this->buttonState = BTN_HOVER;

		// Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
		case BTN_IDLE:
			this->shape.setFillColor(this->idleColor);
			this->text.setFillColor(this->textIdleColor);
			this->shape.setOutlineColor(this->outlineIdleColor);
			break;

		case BTN_HOVER:
			this->shape.setFillColor(this->hoverColor);
			this->text.setFillColor(this->textHoverColor);
			this->shape.setOutlineColor(this->outlineHoverColor);
			break;

		case BTN_ACTIVE:
			this->shape.setFillColor(this->activeColor);
			this->text.setFillColor(this->textActiveColor);
			this->shape.setOutlineColor(this->outlineActiveColor);
			break;

		default:
			this->shape.setFillColor(sf::Color::Red);
			this->text.setFillColor(sf::Color::Blue);
			this->shape.setOutlineColor(sf::Color::Green);
			break;
	}
}

void gui::Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}

// ********************************* End Button

// ********************************* ProgressBar
gui::ProgressBar::ProgressBar(float _x, float _y, float _width, float _height,
	sf::Color inner_color, unsigned character_size,
	sf::VideoMode& vm, sf::Font* font, bool text_bold) :
	vm(vm)
{
	float width = gui::p2pX(_width, vm);
	float height = gui::p2pY(_height, vm);
	float x = gui::p2pX(_x, vm);
	float y = gui::p2pY(_y, vm);

	this->maxWidth = width;

	this->back.setSize(sf::Vector2f(width, height));
	this->back.setFillColor(sf::Color(50, 50, 50, 200));
	this->back.setPosition(x, y);

	this->inner.setSize(sf::Vector2f(width, height));
	this->inner.setFillColor(inner_color);
	// this->inner.setPosition(this->back.getPosition());
	this->inner.setPosition(x, y);

	if (font)
	{
		if (text_bold)
		{
			this->text.setStyle(sf::Text::Bold);
		}
		this->text.setFont(*font);
		this->text.setCharacterSize(gui::calcCharSize(vm, character_size));
		this->text.setPosition(
			this->inner.getPosition().x + gui::p2pX(0.53f, vm),
			this->inner.getPosition().y + gui::p2pY(0.5f, vm));
	}
}

gui::ProgressBar::~ProgressBar()
{
}

// Fonctions
void gui::ProgressBar::setPosition(sf::Vector2f const& position, sf::VideoMode& vm)
{
	this->vm = vm;

	// EN principe on recalcul x et y
	this->back.setPosition(position.x, position.y);
	this->inner.setPosition(position.x, position.y);
	this->text.setPosition(
		this->inner.getPosition().x + gui::p2pX(0.53f, vm),
		this->inner.getPosition().y + gui::p2pY(0.5f, vm));
}

void gui::ProgressBar::update(int current_value, int max_value)
{
	// On met d'abord à jour le text dans la bar
	this->barString = std::to_string(current_value) + " / " + std::to_string(max_value);

	current_value = current_value * this->maxWidth / max_value;

	float percent = static_cast<float>(current_value) / static_cast<float>(this->maxWidth);

	this->inner.setSize(
		sf::Vector2f(
			static_cast<float>(std::floor(this->maxWidth * percent)),
			this->inner.getSize().y));

	this->text.setString(this->barString);
}

void gui::ProgressBar::render(sf::RenderTarget& target)
{
	target.draw(this->back);
	target.draw(this->inner);
	target.draw(this->text);
}
// ********************************* End ProgressBar

// ********************************* InventoryButton
// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
gui::InventoryButton::InventoryButton(float x, float y, sf::Sprite const& sprite,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor,
	sf::Color outline_idle_color, sf::Color outline_hover_color, sf::Color outline_active_color, short unsigned id) :
	sprite(sprite)
{
	this->buttonState = BTN_IDLE;
	this->id = id;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(this->sprite.getTexture()->getSize().x, this->sprite.getTexture()->getSize().y));
	this->shape.setFillColor(idleColor);
	this->shape.setOutlineThickness(1.f);
	this->shape.setOutlineColor(outline_idle_color);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->outlineIdleColor = outline_idle_color;
	this->outlineHoverColor = outline_hover_color;
	this->outlineActiveColor = outline_active_color;

	this->offset = sf::Vector2f(0.f, 0.f);
}

gui::InventoryButton::~InventoryButton()
{}

// Fonctions/Méthodes
bool gui::InventoryButton::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
		return true;

	return false;
}

const sf::Vector2f& gui::InventoryButton::getPosition() const
{
	return this->shape.getPosition();
}

void gui::InventoryButton::setPosition(float x, float y, float addX, float addY)
{
	// std::cout << "Param Pos : x=" << x << " y=" << y << std::endl;
	this->shape.setPosition(x, y);
	// std::cout << "Shape Pos : x=" << this->shape.getPosition().x << " y=" << this->shape.getPosition().y << std::endl;
	// std::cout << "Shape getGlobalBounds : x=" << this->shape.getPosition().x << " y=" << this->shape.getPosition().y << std::endl;

	// this->sprite REVIEW -

	this->offset = sf::Vector2f(addX, addY);
}

void gui::InventoryButton::update(const sf::Vector2i& mousePosWindow)
{

	// std::cout << "Position de la souris " << mousePosWindow.x << " " << mousePosWindow.y << std::endl;
	// std::cout << "Position du shape " << this->shape.getPosition().x << " " << this->shape.getPosition().y << std::endl;
	// Idle
	this->buttonState = BTN_IDLE;

	// Hover
	if (this->shape.getGlobalBounds().contains(mousePosWindow.x + this->offset.x, mousePosWindow.y + this->offset.y)) // NOTE - On a ajouter la position du shape pour tenir compte des décalage lors de l'affichage du menu dans certaines vues
	{
		this->buttonState = BTN_HOVER;

		// Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
		case BTN_IDLE:
			this->shape.setFillColor(this->idleColor);
			// this->text.setFillColor(this->textIdleColor);
			this->shape.setOutlineColor(this->outlineIdleColor);
			break;

		case BTN_HOVER:
			this->shape.setFillColor(this->hoverColor);
			// this->text.setFillColor(this->textHoverColor);
			this->shape.setOutlineColor(this->outlineHoverColor);
			break;

		case BTN_ACTIVE:
			this->shape.setFillColor(this->activeColor);
			// this->text.setFillColor(this->textActiveColor);
			this->shape.setOutlineColor(this->outlineActiveColor);
			break;

		default:
			this->shape.setFillColor(sf::Color::Red);
			// this->text.setFillColor(sf::Color::Blue);
			this->shape.setOutlineColor(sf::Color::Green);
			break;
	}
}

void gui::InventoryButton::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	target.draw(this->shape);
}

// ********************************* End InventoryButton

// ********************************* Inventory
// Fonction static

// Fonctions d'initialisation
void gui::Inventory::initBackground()
{
	this->background.setSize(sf::Vector2f(game::INVENTORY_BLOCK_WIDTH * 13, game::INVENTORY_BLOCK_WIDTH * 5));
	this->background.setFillColor(sf::Color::Magenta);
	// this->background.setPosition(5 * 200, 70 * 200);
}

void gui::Inventory::initInventoryItemSprites()
{
	// sf::Sprite sp = sf::Sprite();

	// this->inventoryItemSprites[game::inventory_items_types::DEFAULT]= sf::Sprite(sf::Texture());
	// this->inventoryItemSprites[game::inventory_items_types::ARMORY]= sf::Sprite();
	// this->inventoryItemSprites[game::inventory_items_types::MONEY]= sf::Sprite();
	// this->inventoryItemSprites[game::inventory_items_types::TELEPORTKEY]= sf::Sprite();
	// this->inventoryItemSprites[game::inventory_items_types::VIAL]= sf::Sprite();
}

void gui::Inventory::initInventoryButtons()
{
	// sf::Sprite sp = sf::Sprite();

	this->inventoryButtons[game::inventory_items_types::DEFAULT] = {};
	this->inventoryButtons[game::inventory_items_types::ARMORY] = {};
	this->inventoryButtons[game::inventory_items_types::MONEY] = {};
	this->inventoryButtons[game::inventory_items_types::TELEPORTKEY] = {};
	this->inventoryButtons[game::inventory_items_types::VIAL] = {};
}

// Constructeurs/Destructeur
gui::Inventory::Inventory(sf::Font const& font) :
	font(font)
{
	this->initBackground();
	this->initInventoryItemSprites();
	this->initInventoryButtons();
}

gui::Inventory::~Inventory()
{
	if (this->inventoryButtons.size() > 0) // REVIEW - On peut enlever
	{
		for (auto it = this->inventoryButtons.begin(); it != this->inventoryButtons.end(); it++)
		{
			for (size_t i = 0; i < it->second.size(); i++)
			{
				delete it->second[i];
			}
		}
	}
}

// Fonctions/Méthodes
bool gui::Inventory::addItem(const Item* item, game::inventory_items_types type)
{
	// this->inventoryItemSprites[type].push_back(item->getSprite());
	switch (type)
	{
		case game::inventory_items_types::DEFAULT: {
		}
		break;
		case game::inventory_items_types::ARMORY: {
			float x = 80.f + 80.f * 4.f + 80.f * (this->inventoryButtons[type].size() % 2);
			float y = 130.f + 80.f + 80 * (floor((float)this->inventoryButtons[type].size() / 2.f));
			this->inventoryButtons[type].push_back(new InventoryButton(x, y, item->getSprite(), sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50)));
			return true;
		}
		break;
		case game::inventory_items_types::MONEY: {
		}
		break;
		case game::inventory_items_types::TELEPORTKEY: {
		}
		break;
		case game::inventory_items_types::VIAL: {
			float x = 80.f + 80.f + 80.f * (this->inventoryButtons[type].size() % 2);
			float y = 130.f + 80.f + 80 * (floor((float)this->inventoryButtons[type].size() / 2.f));
			this->inventoryButtons[type].push_back(new InventoryButton(x, y, item->getSprite(), sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50)));
			return true;
		}
		break;
		default: {
			return false;
		}
		break;
	}
	return false;
}

bool gui::Inventory::removeItem(int index /*, sf::Sprite const& itemSprite*/, game::inventory_items_types type)
{
	// REVIEW -
	// vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
	// this->inventoryItemSprites[type].erase(std::remove(this->inventoryItemSprites[type].begin(), this->inventoryItemSprites[type].end(), itemSprite), this->inventoryItemSprites[type].end());
	delete this->inventoryButtons[type][index];
	this->inventoryButtons[type].erase(std::remove(this->inventoryButtons[type].begin(), this->inventoryButtons[type].end(), this->inventoryButtons[type][index]), this->inventoryButtons[type].end());
	//

	return true;
}

void gui::Inventory::update(const sf::Vector2i& mousePosView)
{
	// Hover
	for (auto&& inventoryButtonVectorPair : this->inventoryButtons)
	{
		for (size_t i = 0; i < inventoryButtonVectorPair.second.size(); i++)
		{
			inventoryButtonVectorPair.second[i]->update(mousePosView);
		}
	}
}

void gui::Inventory::render(sf::RenderTarget& target)
{
	this->setGraphicsElementPosition(target.getView());
	// sf::CircleShape shape(200.f);

	// shape.setFillColor(sf::Color(100, 250, 50));

	// target.draw(shape); // REVIEW -

	target.draw(this->background);

	for (auto it = this->inventoryButtons.begin(); it != this->inventoryButtons.end(); it++)
	{
		for (size_t i = 0; i < it->second.size(); i++)
		{
			it->second[i]->render(target);
		}
	}
}

void gui::Inventory::setGraphicsElementPosition(sf::View const& view)
{

	sf::Vector2f v(view.getCenter());
	sf::Vector2f s(view.getSize());

	// On calcul le décallage du centre de la vue
	float addX(v.x - s.x / 2.f);
	float addY(v.y - s.y / 2.f);

	this->background.setPosition(80.f + addX, 130.f + addY);

	for (auto it = this->inventoryButtons.begin(); it != this->inventoryButtons.end(); it++)
	{
		for (size_t i = 0; i < it->second.size(); i++)
		{
			float x = 80.f + 80.f * 4.f + 80.f * (i % 2) + addX;
			float y = 130.f + 80.f + 80 * (floor((float)i / 2.f)) + addY;
			it->second[i]->setPosition(x, y, addX, addY);
		}
	}
}

// std::vector<sf::Sprite const&>::iterator gui::Inventory::getItemSpriteIterator(sf::Sprite const& itemSprite, game::inventory_items_types type)
// {
// 	for (auto it = this->inventoryItemSprites[type].begin(); it != this->inventoryItemSprites[type].end(); it++)
// 	{
// 		if ((*it) == itemSprite)
// 		{
// 			return it;
// 		}
// 	}
// 	return std::vector<sf::Sprite const&>::iterator(); // REVIEW -
// }

// ********************************* End Inventory
