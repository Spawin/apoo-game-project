#if !defined(__TRANSIT_DOOR_HPP__)
	#define __TRANSIT_DOOR_HPP__

	#include "include/Door.hpp"
	#include "include/Hall.hpp"

class Door;
class Hall;

class TransitDoor : public Door
{
public:
	// Constructeurs/Destructeur
	TransitDoor(sf::IntRect rect, std::vector<Hall*> halls);
	~TransitDoor();

	// Fonctions/Méthodes
private:
	// Variables

	// Fonctions d'initialisation
	// virtual void initHalls(std::vector<Hall*> halls) override;
	virtual void initHallsNumber() override;
};

#endif // __TRANSIT_DOOR_HPP__
