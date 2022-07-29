#if !defined(__HALL_HPP__)
	#define __HALL_HPP__

	#include "include/MyVector.hpp"
	#include "include/MovableGameObject.hpp"
	#include <map>
	#include <vector>

class MovableGameObject;

class Hall
{
public:
	// Constructeurs/Destructeur
	Hall(sf::Vector2i topLeftPoint, int width, int height);
	virtual ~Hall();

	// Fonctions/Méthodes
	virtual bool addMovableGameObject(MovableGameObject* movableGameObject);
	/**
	 * @brief Vérifier si les coordonnées de position données se trouve dans la pièce
	 *
	 * @param coordinates
	 * @return true
	 * @return false
	 */
	bool isIn(MyVector const& coordinates) const;
	/**
	 * @brief Vérifier si les coordonnées de position données se trouve dans la pièce
	 *
	 * @param coordinates
	 * @return true
	 * @return false
	 */
	bool isIn(sf::Vector2f const& coordinates) const;
	const sf::IntRect& getIntRect() const;

	virtual void render(sf::RenderTarget& target);

private:
	// Variables
	// Représente le quandrilatère qui représente les dimension de la salle
	sf::Vector2i topLeftPoint;
	int width;
	int height;
	sf::IntRect intRect;

	std::vector<const MovableGameObject*> hallMovablesGameObjects;

	// #if defined(_DEBUG)
	sf::RectangleShape debug_shape;
	// #endif

	// Fonctions d'initialisation
};

#endif // __HALL_HPP__
