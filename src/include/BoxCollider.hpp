#ifndef __BOX_COLLIDER_HPP__
#define __BOX_COLLIDER_HPP__

#include "include/Collider.hpp"
#include "include/PolygonCollider.hpp"

class BoxCollider : public Collider
{
public:
	/**
	 * @brief Construct a new Box Collider object
	 *
	 * @param parent
	 * @param contactPoints Ne doit pas dépasser
	 */
	// explicit BoxCollider(GameObject const& parent, std::vector<sf::Vector2f> contactPoints);
	/**
	 * @brief Construct a new Box Collider object
	 * ! Les cordonnée du leftTopPoint sont données en fonction du centre de l'objet
	 * @param parent
	 * @param width
	 * @param height
	 * @param leftTopPoint
	 */
	explicit BoxCollider(GameObject const& parent, float width, float height, sf::Vector2f leftTopPoint);
	~BoxCollider();

	std::vector<sf::Vector2f> getContactPoints() const override;
	bool touchEachOther(Collider const& collider) const override;
	static const std::string getName();

private:
	static const std::string m_name;
	float m_width;
	float m_height;
	sf::Vector2f m_leftTopPoint;
};

#endif // __BOX_COLLIDER_HPP__
