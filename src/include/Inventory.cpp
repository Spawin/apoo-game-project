#include "include/Inventory.hpp"
#include "include/Vial.hpp"

// Fonction static

// Fonctions d'initialisation
void Inventory::initLimitPerType(unsigned vial_capacity, unsigned armory_capacity, unsigned teleportKey_capacity, unsigned money_capacity)
{
	this->limitPerType[inventory_items_types::DEFAULT] = 0; // REVIEW -
	this->limitPerType[inventory_items_types::VIAL] = vial_capacity;
	this->limitPerType[inventory_items_types::ARMORY] = armory_capacity;
	this->limitPerType[inventory_items_types::TELEPORTKEY] = teleportKey_capacity;
	this->limitPerType[inventory_items_types::MONEY] = money_capacity;
}

void Inventory::initItemsMapStructure()
{
	// this->items[inventory_items_types::DEFAULT];
	// this->items[inventory_items_types::VIAL] = std::vector<Vial*, std::allocator<Item*>>();
	// this->items[inventory_items_types::ARMORY];
	// this->items[inventory_items_types::TELEPORTKEY];
	// this->items[inventory_items_types::MONEY];
}

// Constructeurs/Destructeur
Inventory::Inventory(unsigned vial_capacity, unsigned armory_capacity, unsigned teleportKey_capacity, unsigned money_capacity)
{
	this->initLimitPerType(vial_capacity, armory_capacity, teleportKey_capacity, money_capacity);
	this->initItemsMapStructure();
}

Inventory::~Inventory()
{
	for (ItemMap::iterator it1 = this->items.begin(); it1 != this->items.end(); it1++)
	{
		for (size_t i = 0; i < it1->second.size(); i++)
		{
			delete it1->second[i];
		}

		it1->second.clear();
	}
}

// Fonctions/Méthodes
bool Inventory::add(Item* item, inventory_items_types type)
{
	// REVIEW - Cas des doublons
	if ((int)(this->items[type].size()) >= this->limitPerType[type])
	{
		return false;
	}

	this->items[type].push_back(item);

	return true;
}

bool Inventory::move(Item* item, inventory_items_types type, Inventory* to_inventory)
{
	// REVIEW - des vérification pour voir si l'object existe réelement

	// On enlève l'objet de l'inventaire actuel
	this->items[type].erase(this->getItemIterator(item, type));
	// On ajoute l'objet à l'inventaire actuel
	to_inventory->add(item, type);

	return true;
}

bool Inventory::remove(Item* item, inventory_items_types type)
{
	// TODO - Vérifications et try catch
	delete this->items[type][this->getItemIndex(item, type)];
	this->items[type].erase(this->getItemIterator(item, type));

	return true;
}

int Inventory::getTypeLimit(inventory_items_types type)
{
	return this->limitPerType[type];
}

int Inventory::getFreePlace(inventory_items_types type)
{
	return this->limitPerType[type] - this->items[type].size();
}

unsigned Inventory::getItemIndex(Item* item, inventory_items_types type)
{
	for (size_t i = 0; i < this->items[type].size(); i++)
	{
		if (this->items[type][i] == item)
		{
			return i;
		}
	}

	return -1;
}

std::vector<Item*>::iterator Inventory::getItemIterator(Item* item, inventory_items_types type)
{
	for (auto it = this->items[type].begin(); it != this->items[type].end(); it++)
	{

		if ((*it) == item)
		{
			return it;
		}
	}

	return std::vector<Item*>::iterator(); // REVIEW -
}
