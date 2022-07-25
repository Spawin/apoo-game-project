#if !defined(__HALL_HPP__)
	#define __HALL_HPP__

	#include "include/MyVector.hpp"

class Hall
{
public:
	// Constructeurs/Destructeur
	Hall(sf::Vector2i topLeftPoint, int width, int height);
	~Hall();

	// Fonctions/Méthodes
	bool isIn(MyVector const& coordinates);
	bool isIn(sf::Vector2f const& coordinates);

	void render(sf::RenderTarget& target);

private:
	// Variables
	sf::Vector2i topLeftPoint;
	int width;
	int height;

	// #if defined(_DEBUG)
	sf::RectangleShape debug_shape;
	// #endif

	// Fonctions d'initialisation
};

#endif // __HALL_HPP__
