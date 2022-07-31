#if !defined(__TELEPORT_DOOR_HPP__)
	#define __TELEPORT_DOOR_HPP__

	#include "include/Door.hpp"
	#include "include/Hall.hpp"

class Door;
class Hall;

class TeleportDoor : public Door
{
public:
	// Constructeurs/Destructeur
	TeleportDoor(sf::IntRect rect, std::vector<Hall*> halls);
	~TeleportDoor();

	// Fonctions/Méthodes
private:
	// Variables

	// Fonctions d'initialisation
	// virtual void initHalls(std::vector<Hall*> halls) override;
	virtual void initHallsNumber() override;
};

#endif // __TELEPORT_DOOR_HPP__
