#include "include/Bag.hpp"

// Fonction static

// Fonctions d'initialisation
void Bag::initInventory()
{
	this->inventory = new Inventory();
}

// void Bag::initAnimations()
// {
// 	this->createAnimationComponent(m_texture);
// 	this->animationComponent->addAnimation(0, "NOPE", 10.f, 0, 0, 0, 0, 80, 80);
// }

// Constructeurs/Destructeur
Bag::Bag() :
	NotMovableGameObject("content/gameObjects/bag.png")
{
	this->initInventory();
	// m_gameObjectName = "Bag";
	this->setGameObjectName("Bag");
}

Bag::~Bag()
{
	delete this->inventory;
}

// Fonctions/Méthodes
bool Bag::addItem(Item* item, game::inventory_items_types type, sf::Vector2f const& coordinates)
{
	return this->inventory->add(item, type, coordinates);
}

bool Bag::moveItem(Item* item, game::inventory_items_types type, Inventory* to_inventory, sf::Vector2f const& coordinates)
{
	return this->inventory->move(item, type, to_inventory, coordinates);
}

bool Bag::removeItem(Item* item, game::inventory_items_types type)
{
	return this->inventory->remove(item, type);
}

bool Bag::drop(Item* item, game::inventory_items_types type, sf::Vector2f const& coordinates, bool directErase)
{
	return this->inventory->drop(item, type, coordinates, directErase);
}

bool Bag::dropAll(sf::Vector2f const& coordinates)
{
	return this->inventory->dropAll(coordinates);
}

bool Bag::haveThisItem(game::ItemsCategories const& categorie) const
{
	return this->inventory->haveThisItem(categorie);
}

game::inventory_items_types const& Bag::getInventoryItemType(Item const* item) const
{
	return this->inventory->getInventoryItemType(item);
}

Item const* Bag::getFirstItemMatch(game::ItemsCategories const& categorie) const
{
	return this->inventory->getFirstItemMatch(categorie);
}

Item* Bag::getFirstItemMatchNonConst(game::ItemsCategories const& categorie)
{
	return this->inventory->getFirstItemMatchNonConst(categorie);
}

Inventory* Bag::getInventory()
{
	return this->inventory;
}

void Bag::onCollisionEnter(Collision const& collision) const
{
	collision.test();
}

void Bag::update()
{
	// this->inventory-
}

void Bag::renderInventory(sf::RenderTarget& target)
{
	this->inventory->getGui()->render(target);
}

void Bag::updatePosition(float posX, float posY)
{
	m_position->setPosition(posX, posY);
	// On replace le body
	m_body.setPosition(m_position->getPosition().toVector2f());

	std::cout << "Position du " << m_gameObjectName << " : " << m_position << " => " << (*m_position) << std::endl;
}
