#include "include/Inventory.hpp"
#include "include/GameMaster.hpp"
#include "include/Vial.hpp"
#include <math.h>

// Fonction static
// Initialisation à vide de la liste des items n'apartenant pas à un objet inventaire
Inventory::ItemMap Inventory::notInventoriedItems = [] {
	ItemMap ret;
	return ret;
}();

// Fonctions d'initialisation
void Inventory::initLimitPerType(unsigned vial_capacity, unsigned armory_capacity, unsigned teleportKey_capacity, unsigned money_capacity)
{
	this->limitPerType[game::inventory_items_types::DEFAULT] = 0; // REVIEW -
	this->limitPerType[game::inventory_items_types::VIAL] = vial_capacity;
	this->limitPerType[game::inventory_items_types::ARMORY] = armory_capacity;
	this->limitPerType[game::inventory_items_types::TELEPORTKEY] = teleportKey_capacity;
	this->limitPerType[game::inventory_items_types::MONEY] = money_capacity;
}

void Inventory::initItemsMapStructure()
{
	// this->items[game::inventory_items_types::DEFAULT];
	// this->items[game::inventory_items_types::VIAL] = std::vector<Vial*, std::allocator<Item*>>();
	// this->items[game::inventory_items_types::ARMORY];
	// this->items[game::inventory_items_types::TELEPORTKEY];
	// this->items[game::inventory_items_types::MONEY];
}

void Inventory::iniInventorytGui()
{
	this->inventoryGui = new gui::Inventory(GameMaster::STATE_DATA()->defaultFont);
}

// Constructeurs/Destructeur
Inventory::Inventory(unsigned vial_capacity, unsigned armory_capacity, unsigned teleportKey_capacity, unsigned money_capacity) :
	defaultInventoryItemType(game::inventory_items_types::DEFAULT)
{
	this->initLimitPerType(vial_capacity, armory_capacity, teleportKey_capacity, money_capacity);
	this->initItemsMapStructure();
	this->iniInventorytGui();
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

	delete this->inventoryGui;
}

// Fonctions/Méthodes
bool Inventory::add(Item* item, game::inventory_items_types type, sf::Vector2f const& coordinates)
{
	// REVIEW - Cas des doublons (même pointeur ajouté..) (utiliser l'id du game object)

	if ((int)(this->items[type].size()) >= this->limitPerType[type])
	{
		return false;
	}

	// On met à jour la position de l'item (utile surtout si c'est l'inventaire d'un hall)
	item->setPosition(coordinates);

	this->items[type].push_back(item);

	return this->inventoryGui->addItem(item, type);
}

bool Inventory::move(Item* item, game::inventory_items_types type, Inventory* to_inventory, sf::Vector2f const& coordinates)
{
	// REVIEW - des vérification pour voir si l'object existe réelement

	// On ajoute l'objet à l'inventaire de destination
	if (to_inventory->add(item, type, coordinates))
	{
		// On retire de l'aperçu
		this->inventoryGui->removeItem(item, type);

		// On enlève l'objet de l'inventaire actuel
		this->items[type].erase(this->getItemIterator(item, type));
		return true;
	}

	// TODO - Cas du false
	return false;
}

bool Inventory::remove(Item* item, game::inventory_items_types type)
{
	// TODO - Vérifications et try catch

	// On retire de l'aperçu
	this->inventoryGui->removeItem(item, type);

	delete this->items[type][this->getItemIndex(item, type)];
	this->items[type].erase(this->getItemIterator(item, type));

	return true;
}

bool Inventory::drop(Item* item, game::inventory_items_types type, sf::Vector2f const& coordinates, bool directErase)
{
	// REVIEW - Cas des doublons (même pointeur ajouté..) (utiliser l'id du game object)

	// On met à jour la position de l'item
	item->setPosition(coordinates);

	// On met dans le générale
	Inventory::notInventoriedItems[type].push_back(item);

	// On retire de l'aperçu
	this->inventoryGui->removeItem(item, type);

	// On enlève l'objet de l'inventaire actuel si le directErase est à true
	if (directErase)
	{
		this->items[type].erase(this->getItemIterator(item, type));
	}
	return true;
}

bool Inventory::dropAll(sf::Vector2f const& coordinates)
{
	for (auto&& pair : this->items)
	{
		for (size_t i = 0; i < pair.second.size(); i++)
		{
			//
			this->drop(pair.second[i], pair.first, sf::Vector2f(coordinates.x + 80 * (i % 5), coordinates.y + 80 * floor((float)i / 5.f)), false);
		}

		// On netoie tout ce qui concerne ces types car déjà transférés
		pair.second.clear();
	}

	return true;
}

bool Inventory::haveThisItem(game::ItemsCategories const& categorie) const
{

	for (auto&& v : this->items)
	{
		for (size_t i = 0; i < v.second.size(); i++)
		{
			if (v.second[i]->getCategorie() == categorie)
			{
				return true;
			}
		}
	}

	return false;
}

game::inventory_items_types const& Inventory::getInventoryItemType(Item const* item) const
{
	for (auto&& v : this->items)
	{
		for (size_t i = 0; i < v.second.size(); i++)
		{
			if (v.second[i] == item)
			{
				return v.first;
			}
		}
	}

	return this->defaultInventoryItemType;
}

Item const* Inventory::getFirstItemMatch(game::ItemsCategories const& categorie) const
{
	for (auto&& v : this->items)
	{
		for (size_t i = 0; i < v.second.size(); i++)
		{
			if (v.second[i]->getCategorie() == categorie)
			{
				return v.second[i];
			}
		}
	}

	return nullptr; // REVIEW - !!!
}

Item* Inventory::getFirstItemMatchNonConst(game::ItemsCategories const& categorie)
{
	for (auto&& v : this->items)
	{
		for (size_t i = 0; i < v.second.size(); i++)
		{
			if (v.second[i]->getCategorie() == categorie)
			{
				return v.second[i];
			}
		}
	}

	return nullptr; // REVIEW - !!!
}

int Inventory::getTypeLimit(game::inventory_items_types type)
{
	return this->limitPerType[type];
}

int Inventory::getFreePlace(game::inventory_items_types type)
{
	return this->limitPerType[type] - this->items[type].size();
}

gui::Inventory* Inventory::getGui()
{
	return this->inventoryGui;
}

// std::map<game::inventory_items_types, std::vector<Item*>> const* Inventory::getItems()
// {
// 	return &items;
// }

std::map<game::inventory_items_types, std::vector<Item*>>& Inventory::getNotInventoriedItemsNonConst()
{
	return Inventory::notInventoriedItems;
}

unsigned Inventory::getItemIndex(Item* item, game::inventory_items_types type)
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

std::vector<Item*>::iterator Inventory::getItemIterator(Item* item, game::inventory_items_types type)
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
