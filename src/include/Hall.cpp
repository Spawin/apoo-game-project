#include "include/Hall.hpp"

// Fonction static

// Fonctions d'initialisation
void Hall::initInventory()
{
	// this->inventory = new Inventory();
}

// Constructeurs/Destructeur
Hall::Hall(sf::Vector2i topLeftPoint, int width, int height) :
	topLeftPoint(topLeftPoint),
	width(width),
	height(height),
	intRect(topLeftPoint, sf::Vector2i(width, height))
{
	this->initInventory();
	// #if defined(_DEBUG)
	// std::cout << "Initialisation Hall x" << topLeftPoint.x << " y" << topLeftPoint.y << std::endl;
	this->debug_shape.setPosition(topLeftPoint.x, topLeftPoint.y);
	this->debug_shape.setSize(sf::Vector2f(width, height));
	this->debug_shape.setFillColor(sf::Color::Transparent);
	this->debug_shape.setOutlineThickness(-10.f);
	this->debug_shape.setOutlineColor(sf::Color::Red);
	// #endif
}

Hall::~Hall()
{
	// delete this->inventory;
}

// Fonctions/Méthodes
// bool Hall::addItem(Item* item, game::inventory_items_types type, sf::Vector2f const& coordinates)
// {
// 	return this->inventory->add(item, type, coordinates);
// }

// bool Hall::moveItem(Item* item, game::inventory_items_types type, Inventory* to_inventory, sf::Vector2f const& coordinates)
// {
// 	return this->inventory->move(item, type, to_inventory, coordinates);
// }

// bool Hall::removeItem(Item* item, game::inventory_items_types type)
// {
// 	return this->inventory->remove(item, type);
// }

bool Hall::addMovableGameObject(MovableGameObject* movableGameObject)
{
	this->hallMovablesGameObjects.push_back(movableGameObject);
	return true;
}

bool Hall::isIn(MyVector const& coordinates) const
{
	// Vérifions si le point se trouve à l'intérieur du rectangle/carré
	if (coordinates.x > this->topLeftPoint.x)
		if (coordinates.x < this->topLeftPoint.x + this->width)
			if (coordinates.y > this->topLeftPoint.y)
				if (coordinates.y < this->topLeftPoint.y + this->height)
					return true;

	return false;
}

bool Hall::isIn(sf::Vector2f const& coordinates) const
{
	// std::cout << "this->topLeftPoint.x" << this->topLeftPoint.x << std::endl;
	// Vérifions si le point se trouve à l'intérieur du rectangle/carré
	if (coordinates.x > this->topLeftPoint.x)
		if (coordinates.x < this->topLeftPoint.x + this->width)
			if (coordinates.y > this->topLeftPoint.y)
				if (coordinates.y < this->topLeftPoint.y + this->height)
					return true;

	return false;
}

const sf::IntRect& Hall::getIntRect() const
{
	return this->intRect;
}

void Hall::render(sf::RenderTarget& target)
{
	// this->renderInventory(target);

#if defined(_DEBUG)
	// On affiche les bords des pièces
	target.draw(this->debug_shape);
#endif
}

// void Hall::renderInventory(sf::RenderTarget& target)
// {
// 	// std::map<game::inventory_items_types, std::vector<Item*>> const* items = this->inventory->getItems();
// 	// for (auto&& item : (*items))
// 	// {
// 	// 	for (size_t i = 0; i < item.second.size(); i++)
// 	// 	{
// 	// 		item.second[i]->show(target);
// 	// 	}
// 	// }
// }
