#if !defined(__INVENTORY_HPP__)
	#define __INVENTORY_HPP__

	#include "include/Item.hpp"
	#include <map>
	#include <vector>
	#include <string>

class Item;

enum inventory_items_types
{
	DEFAULT = -1,
	VIAL = 0,
	ARMORY,
	TELEPORTKEY,
	MONEY
};

class Inventory
{
public:
	// Constructeurs/Destructeur
	Inventory(unsigned vial_capacity = 6, unsigned armory_capacity = 4, unsigned teleportKey_capacity = 3, unsigned money_capacity = 9999999);
	~Inventory();

	// Fonctions/Méthodes
	bool add(Item* item, inventory_items_types type);
	bool move(Item* item, inventory_items_types type, Inventory* to_inventory);
	bool remove(Item* item, inventory_items_types type);

	int getTypeLimit(inventory_items_types type);
	int getFreePlace(inventory_items_types type);

private:
	using ItemMap = std::map<int, std::vector<Item*>>;
	// Variables
	ItemMap items;
	std::map<int, int> limitPerType;

	// Fonctions d'initialisation
	void initLimitPerType(unsigned vial_capacity, unsigned armory_capacity, unsigned teleportKey_capacity, unsigned money_capacity);
	void initItemsMapStructure();

	unsigned getItemIndex(Item* item, inventory_items_types type);
	std::vector<Item*>::iterator getItemIterator(Item* item, inventory_items_types type);
};

#endif // __INVENTORY_HPP__
