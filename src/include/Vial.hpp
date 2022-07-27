#if !defined(__VIAL_HPP__)
	#define __VIAL_HPP__

	#include "include/Item.hpp"

class Item;

class Vial : public Item
{
public:
	// Constructeurs/Destructeur
	Vial(std::string_view const& imageSpritePath);
	~Vial();

	// Fonctions/Méthodes
private:
	// Variables

	// Fonctions d'initialisation
};

#endif // __VIAL_HPP__
