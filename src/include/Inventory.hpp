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

// enum inventory_items_types
// {
// 	DEFAULT = -1,
// 	VIAL = 0,
// 	ARMORY,
// 	TELEPORTKEY,
// 	MONEY
// };

class Inventory
{
public:
	// Constructeurs/Destructeur
	Inventory(unsigned vial_capacity = 6, unsigned armory_capacity = 4, unsigned teleportKey_capacity = 3, unsigned money_capacity = 9999999);
	~Inventory();

	// Fonctions/Méthodes
	bool add(Item* item, game::inventory_items_types type);
	bool move(Item* item, game::inventory_items_types type, Inventory* to_inventory);
	bool remove(Item* item, game::inventory_items_types type);

	bool haveThisItem(game::ItemsCategories const& categorie) const;

	/**
	 * @brief Retourne le premier item qui vérifie le paramètre.
	 * NOTE - S'assurer d'appeler haveThisItem avant pour vérifier la disponibilité de l'objet recherché.
	 * Si l'item n'est pas trouvé un retour null_ptr est envoyé.
	 *
	 * @param categorie
	 * @return Item const*
	 */
	Item const* getFirstItemMatch(game::ItemsCategories const& categorie) const;

	int getTypeLimit(game::inventory_items_types type);
	int getFreePlace(game::inventory_items_types type);

	gui::Inventory* getGui();

private:
	using ItemMap = std::map<int, std::vector<Item*>>;
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
};

#endif // __INVENTORY_HPP__
