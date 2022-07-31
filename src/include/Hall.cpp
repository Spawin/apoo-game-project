#include "include/Hall.hpp"

// Fonction static

// Fonctions d'initialisation
void Hall::initInventory()
{
	// this->inventory = new Inventory();
}

// Constructeurs/Destructeur
Hall::Hall(sf::Vector2i topLeftPoint, int width, int height, size_t index) :
	index(index),
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

	// FIXME - Les halls doivent avoir tourjours 4 portes pour Pour eviter des erreur; si cela venait à changer, modifier cette partie
	if (this->doors.size())
	{
		// On détruit toutes les porte si c'est la chambre spéciale
		if (this->index % 2 == 0)
		{

			// Cas du 2 spécial
			if (this->index == 2)
			{
				for (size_t i = 0; i < this->doors.size(); i++)
				{
					if (i != 2)
					{
						delete this->doors[i];
					}
					this->doors.clear();
				}
			}
			else
			{
				// On enlève toutes les porte
				for (size_t i = 0; i < this->doors.size(); i++)
				{
					delete this->doors[i];
				}
				this->doors.clear();
			}
		}

		// REVIEW - Un truc plus automatique
		if (this->index == 1 || this->index == 7 || this->index == 13)
		{
			// Gauche
			delete this->doors[3]; //!
			this->doors.clear();
		}

		if (this->index == 3 || this->index == 9 || this->index == 15)
		{
			// Droite
			delete this->doors[1]; //!
			this->doors.clear();
		}
	}
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

bool Hall::removeMovableGameObject(MovableGameObject* movableGameObject)
{
	for (size_t i = 0; i < this->hallMovablesGameObjects.size(); i++)
	{
		if (this->hallMovablesGameObjects[i]->getGameObjectId() == movableGameObject->getGameObjectId())
		{
			this->hallMovablesGameObjects.erase(this->hallMovablesGameObjects.begin() + i);
			return true;
		}
	}
	return false;
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

bool Hall::addDoor(Door* door)
{
	if (this->doors.size() >= game::DOORS_PER_HALL)
	{
		std::cerr << "Max de portes atteint!\n";
		return false;
	}

	this->doors.push_back(door);

	return true;
}

void Hall::render(sf::RenderTarget& target)
{
	// this->renderInventory(target);

#if defined(_DEBUG)
	// On affiche les bords des pièces
	target.draw(this->debug_shape);
#endif

	for (size_t i = 0; i < this->doors.size(); i++)
	{
		this->doors[i]->show(target);
	}
}

size_t const& Hall::getHallIndex() const
{
	return this->index;
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
