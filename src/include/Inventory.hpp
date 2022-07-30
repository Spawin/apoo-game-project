#if !defined(__INVENTORY_HPP__)
	#define __INVENTORY_HPP__

	#include <map>
	#include <vector>
	#include <string>
	#include "include/Gui.hpp"
	#include "include/Item.hpp"
	#include "include/consts.hpp"

class Item;
// enum class ItemsCategories;
namespace gui
{
class Inventory;
}

class Inventory
{
public:
	// Constructeurs/Destructeur
	Inventory(unsigned vial_capacity = 6, unsigned armory_capacity = 4, unsigned teleportKey_capacity = 3, unsigned money_capacity = 9999999);
	~Inventory();

	// Fonctions/Méthodes
	bool add(Item* item, game::inventory_items_types type, sf::Vector2f const& coordinates);
	bool move(Item* item, game::inventory_items_types type, Inventory* to_inventory, sf::Vector2f const& coordinates);
	bool remove(Item* item, game::inventory_items_types type);

	bool haveThisItem(game::ItemsCategories const& categorie) const;
	/**
	 * @brief Retourne le type de l'inventaire de l'item
	 *
	 * @param item
	 * @return game::inventory_items_types const&
	 */
	game::inventory_items_types const& getInventoryItemType(Item const* item) const;

	/**
	 * @brief Retourne le premier item qui vérifie le paramètre.
	 * NOTE - S'assurer d'appeler haveThisItem avant pour vérifier la disponibilité de l'objet recherché.
	 * Si l'item n'est pas trouvé un retour null_ptr est envoyé.
	 *
	 * @param categorie
	 * @return Item const*
	 */
	Item const* getFirstItemMatch(game::ItemsCategories const& categorie) const;
	Item* getFirstItemMatchNonConst(game::ItemsCategories const& categorie);

	int getTypeLimit(game::inventory_items_types type);
	int getFreePlace(game::inventory_items_types type);

	gui::Inventory* getGui();

	// std::map<game::inventory_items_types, std::vector<Item*>> const* getItems();

private:
	// using ItemMap = std::map<int, std::vector<Item*>>;
	using ItemMap = std::map<game::inventory_items_types, std::vector<Item*>>;
	// Variables
	ItemMap items;
	std::map<int, int> limitPerType;

	// Fonctions d'initialisation
	void initLimitPerType(unsigned vial_capacity, unsigned armory_capacity, unsigned teleportKey_capacity, unsigned money_capacity);
	void initItemsMapStructure();
	void iniInventorytGui();

	unsigned getItemIndex(Item* item, game::inventory_items_types type);
	std::vector<Item*>::iterator getItemIterator(Item* item, game::inventory_items_types type);

	gui::Inventory* inventoryGui;

	const game::inventory_items_types defaultInventoryItemType;
};

#endif // __INVENTORY_HPP__
