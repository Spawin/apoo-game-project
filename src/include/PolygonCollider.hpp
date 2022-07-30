#ifndef __POLYGON_COLLIDER_HPP__
#define __POLYGON_COLLIDER_HPP__

#include "include/Collider.hpp"
#include "include/GameObject.hpp" // REVIEW -

class collider;
class GameObject;

class PolygonCollider : public Collider
{
public:
	explicit PolygonCollider(GameObject const& parent, std::vector<sf::Vector2f> contactPoints);
	~PolygonCollider();

	std::vector<sf::Vector2f> getContactPoints() const override;
	bool touchEachOther(Collider const& collider) const override;
	static const std::string getName();

private:
	static const std::string m_name;
	std::vector<sf::Vector2f> m_contactPoints;
};

#endif // __POLYGON_COLLIDER_HPP__
