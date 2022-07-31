#include "include/Item.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Item::Item(std::string_view const& imageSpritePath, game::ItemsCategories categorie) :
	NotMovableGameObject(imageSpritePath),
	categorie(categorie)
{
	this->resetMustTake();

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
	std::cout << "mousePosWindow x=" << mousePosWindow.x << " y=" << mousePosWindow.y << std::endl;

	if (this->m_body.getGlobalBounds().contains(mousePosWindow.x, mousePosWindow.y))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->mustTake = true;
			std::cout << "on prens l'item\n";
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

bool const& Item::playerMustTake() const
{
	return this->mustTake;
}

void Item::resetMustTake()
{
	this->mustTake = false;
}
