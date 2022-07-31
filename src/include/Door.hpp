#if !defined(__DOOR_HPP__)
	#define __DOOR_HPP__

	#include "include/Hall.hpp"
	#include "include/NotMovableGameObject.hpp"
	#include <vector>

class NotMovableGameObject;
class Hall;

class Door : public NotMovableGameObject
{
	using DoorMap = std::map<int, Door*>;

public:
	// Constructeurs/Destructeur
	Door(sf::Vector2f coordinates);
	~Door();

	// Fonctions/Méthodes
	short const& getHallsNumber() const;

	/**
	 * @brief émit quand il entre en contacte avec un autre élément
	 *
	 * @param collision
	 */
	virtual void onCollisionEnter(Collision const& collision) const override;
	virtual void update() override;
	virtual void show(sf::RenderTarget& target) override;

	static DoorMap& getDoors();
	/**
	 * @brief Retourne les chambres auxquells la porte à accès
	 *
	 * @return std::vector<Hall*>&
	 */
	std::vector<Hall*>& getDoorHalls();

protected:
	// Variables
	static DoorMap doors;

	/**
	 * @brief Contour indiquant le type de port
	 *
	 */
	sf::RectangleShape rectShape;
	sf::IntRect intRect;

	/**
	 * @brief la liste de salle vers lesquels il mène.
	 *
	 */
	std::vector<Hall*> halls;
	/**
	 * @brief Le nombre de Hall.
	 * Note: -1 = pas de limites
	 *
	 */
	short hallsNumber;

	// Fonctions d'initialisation
	virtual void initHalls(std::vector<Hall*> halls);
	virtual void initHallsNumber() = 0;

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 *
	 */
	virtual void updatePosition(float posX, float posY) override;
};

#endif // __DOOR_HPP__
