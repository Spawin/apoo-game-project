#if !defined(__ARMORY_HPP__)
	#define __ARMORY_HPP__

	#include "include/Item.hpp"
	#include "include/consts.hpp"

class Item;

class Armory : public Item
{
public:
	// Constructeurs/Destructeur
	Armory(std::string_view const& imageSpritePath, game::ItemsCategories categorie);
	~Armory();

	// Fonctions/Méthodes
private:
	// Variables

	// Fonctions d'initialisation
};

#endif // __ARMORY_HPP__
