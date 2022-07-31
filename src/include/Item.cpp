#include "include/Item.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Item::Item(std::string_view const& imageSpritePath, game::ItemsCategories categorie) :
	NotMovableGameObject(imageSpritePath),
	categorie(categorie)
{
	this->value = 10;
	this->rangeOfAction = 30.f;
	this->waitingTimeForAction = 1.f;
	this->oneUse = false;
}

Item::~Item()
{}

// Fonctions/Méthodes
game::ItemsCategories const& Item::getCategorie() const
{
	return this->categorie;
}

void Item::updateMousePosWindow(sf::Vector2i mousePosWindow)
{
	if (this->m_body.getGlobalBounds().contains(mousePosWindow.x, mousePosWindow.y))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//
		}
	}
}

unsigned const& Item::getValue() const
{
	return this->value;
}

float const& Item::getRangeOfAction() const
{
	return this->rangeOfAction;
}

float const& Item::getWaitingTimeForAction() const
{
	return this->waitingTimeForAction;
}

bool const& Item::isOneUse() const
{
	return this->oneUse;
}
