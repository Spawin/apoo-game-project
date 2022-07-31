#if !defined(__HALL_HPP__)
	#define __HALL_HPP__

	#include <map>
	#include <vector>
	// #include "include/Inventory.hpp"
	// #include "include/Item.hpp"
	#include "include/consts.hpp"
	#include "include/MyVector.hpp"
	#include "include/MovableGameObject.hpp"
	#include "include/Door.hpp"
// #include "include/NotMovableGameObject.hpp"

class MovableGameObject;
class NotMovableGameObject;
class Door;
// class Inventory;
// class Item;

class Hall
{
public:
	// Constructeurs/Destructeur
	Hall(sf::Vector2i topLeftPoint, int width, int height);
	virtual ~Hall();

	// Fonctions/Méthodes
	// bool addItem(Item* item, game::inventory_items_types type, sf::Vector2f const& coordinates);
	// bool moveItem(Item* item, game::inventory_items_types type, Inventory* to_inventory, sf::Vector2f const& coordinates);
	// bool removeItem(Item* item, game::inventory_items_types type);

	virtual bool addMovableGameObject(MovableGameObject* movableGameObject);
	/**
	 * @brief Vérifier si les coordonnées de position données se trouve dans la pièce
	 *
	 * @param coordinates
	 * @return true
	 * @return false
	 */
	bool isIn(MyVector const& coordinates) const;
	/**
	 * @brief Vérifier si les coordonnées de position données se trouve dans la pièce
	 *
	 * @param coordinates
	 * @return true
	 * @return false
	 */
	bool isIn(sf::Vector2f const& coordinates) const;
	const sf::IntRect& getIntRect() const;
	bool addDoor(Door* door);

	virtual void render(sf::RenderTarget& target);

private:
	// Variables
	// Inventory* inventory;
	// Représente le quandrilatère qui représente les dimension de la salle
	sf::Vector2i topLeftPoint;
	int width;
	int height;
	sf::IntRect intRect;

	std::vector<const MovableGameObject*> hallMovablesGameObjects;

	std::vector<Door*> doors;

	// #if defined(_DEBUG)
	sf::RectangleShape debug_shape;
	// #endif

	// Fonctions d'initialisation
	void initInventory();

	// void renderInventory(sf::RenderTarget& target);
};

#endif // __HALL_HPP__
