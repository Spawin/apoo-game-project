#if !defined(__ITEM_HPP__)
	#define __ITEM_HPP__

	#include "include/NotMovableGameObject.hpp"

class NotMovableGameObject;

/**
 * @brief Représente éssentiellement les object que pourra manipuler les personnages
 *
 */
class Item : public NotMovableGameObject
{
public:
	Item(std::string_view const& imageSpritePath);
	~Item();
	// Constructeurs/Destructeur

	// Fonctions/Méthodes
	// sf::Texture const& get
	// bool use();

protected:
	// Variables

	// Fonctions d'initialisation
};

#endif // __ITEM_HPP__
