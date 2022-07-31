#if !defined(__BAG_HPP__)
	#define __BAG_HPP__

	#include "include/NotMovableGameObject.hpp"
	#include "include/Inventory.hpp"
	#include "include/Item.hpp"
	#include "include/consts.hpp"

class NotMovableGameObject;
class Inventory;
class Item;
// enum class ItemsCategories;
class Collision;

class Bag : public NotMovableGameObject
{
public:
	// Constructeurs/Destructeur
	Bag();
	~Bag();

	// Fonctions/Méthodes
	bool addItem(Item* item, game::inventory_items_types type, sf::Vector2f const& coordinates);
	bool moveItem(Item* item, game::inventory_items_types type, Inventory* to_inventory, sf::Vector2f const& coordinates);
	bool removeItem(Item* item, game::inventory_items_types type);
	bool drop(Item* item, game::inventory_items_types type, sf::Vector2f const& coordinates, bool directErase = true);
	bool dropAll(sf::Vector2f const& coordinates);

	bool haveThisItem(game::ItemsCategories const& categorie) const;
	game::inventory_items_types const& getInventoryItemType(Item const* item) const;
	Item const* getFirstItemMatch(game::ItemsCategories const& categorie) const;
	Item* getFirstItemMatchNonConst(game::ItemsCategories const& categorie);

	Inventory* getInventory();
	/**
	 * @brief émit quand il entre en contacte avec un autre élément
	 *
	 * @param collision
	 */
	virtual void onCollisionEnter(Collision const& collision) const override;
	virtual void update() override;

	void renderInventory(sf::RenderTarget& target);

private:
	// Variables
	Inventory* inventory;

	// Fonctions d'initialisation
	void initInventory();

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 *
	 */
	virtual void updatePosition(float posX, float posY) override;
};

#endif // __BAG_HPP__
