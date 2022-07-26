#ifndef __POSITION_HPP__
#define __POSITION_HPP__

#include "include/MyVector.hpp"
// #include "include/Rigidbody.hpp"
#include "include/consts.hpp"

class RigidRigidbody;

class Position
{
public:
	// explicit Position(float detectabilityRadius = game::DEFAULT_DETECTABILITY_RADIUS);

	explicit Position(float px, float py, float detectabilityRadius = game::DEFAULT_DETECTABILITY_RADIUS);
	virtual ~Position();

	static void initSpace(int width, int height); // méthode static car l’espace sera le même pour tous les objets Coordonnees

	int getSpaceWidth() const;

	int getSpaceHeight() const;

	float getX() const;
	float getY() const;

	/**
	 * @brief Get the Distance With object
	 *
	 * @param autre
	 * @return float
	 */
	float getDistanceWith(Position const& autre) const;

	/**
	 * @brief Set the Position object
	 *
	 * @param posX
	 * @param posY
	 */
	void setPosition(float posX, float posY);

	/**
	 * @brief Get the Position object
	 *
	 * @return MyVector
	 */
	MyVector getPosition() const;

	/**
	 * @brief Met à jour les nouvelle limite de déplacement.
	 *
	 * @param hall
	 */
	virtual void setPositionMovementLimit(sf::IntRect const& hall);

	void operator+=(MyVector const& v);
	void operator=(Position const& p);
	friend std::ostream& operator<<(std::ostream& out, Position const& p);

private:
	void init();
	// recalcule les coordonnées pour qu’elles soient dans les limites ; inutile d’y accéder de l’extérieur, donc privée
	void recalculate();
	float m_x; // REVIEW -
	float m_y; // REVIEW -

	MyVector m_previousPosition;
	void setPreviousPosition(float x, float y);
	void setPreviousPosition(MyVector v);

	// longueur et hauteur de l’espace sont static, partagés par tous les objets Coordonnees
	static int m_spaceWidth;
	static int m_spaceHeight;

	float const DETECTABILITY_RADIUS;

	bool m_thereIsARigidBody;

	friend class Rigidbody;

	// Represente la salle dans laquelle la position peut occupée des coordonnées.
	sf::IntRect hall;

	/**
	 * @brief Vérifie si l'élément à le droit de se déplacer.
	 * Ici on concidère les limite de l'epace fixé (Hall)
	 *
	 * @return true
	 * @return false
	 */
	bool canMove();
};

#endif // __POSITION_HPP__