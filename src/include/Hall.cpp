#include "include/Hall.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Hall::Hall(sf::Vector2i topLeftPoint, int width, int height) :
	topLeftPoint(topLeftPoint),
	width(width),
	height(height)
{
	// #if defined(_DEBUG)
	// std::cout << "Initialisation Hall x" << topLeftPoint.x << " y" << topLeftPoint.y << std::endl;
	this->debug_shape.setPosition(topLeftPoint.x, topLeftPoint.y);
	this->debug_shape.setSize(sf::Vector2f(width, height));
	this->debug_shape.setFillColor(sf::Color::Transparent);
	this->debug_shape.setOutlineThickness(-10.f);
	this->debug_shape.setOutlineColor(sf::Color::Red);
	// #endif
}

Hall::~Hall()
{
}

// Fonctions/Méthodes
bool Hall::isIn(MyVector const& coordinates)
{
	// Vérifions si le point se trouve à l'intérieur du rectangle/carré
	if (coordinates.x > this->topLeftPoint.x)
		if (coordinates.x < this->topLeftPoint.x + this->width)
			if (coordinates.y > this->topLeftPoint.y)
				if (coordinates.y < this->topLeftPoint.y + this->height)
					return true;

	return false;
}

bool Hall::isIn(sf::Vector2f const& coordinates)
{
	// std::cout << "this->topLeftPoint.x" << this->topLeftPoint.x << std::endl;
	// Vérifions si le point se trouve à l'intérieur du rectangle/carré
	if (coordinates.x > this->topLeftPoint.x)
		if (coordinates.x < this->topLeftPoint.x + this->width)
			if (coordinates.y > this->topLeftPoint.y)
				if (coordinates.y < this->topLeftPoint.y + this->height)
					return true;

	return false;
}

void Hall::render(sf::RenderTarget& target)
{
	target.draw(this->debug_shape);
}
