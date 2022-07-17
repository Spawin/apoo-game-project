#ifndef __BOX_COLLIDER_HPP__
#define __BOX_COLLIDER_HPP__

#include "include/Collider.hpp"

class PolygonCollider : public Collider
{
public:
	explicit PolygonCollider(GameObject const& parent, std::vector<sf::Vector2f> contactPoints);
	~PolygonCollider();

	bool touchEachOther(Collider const& collider) const override;

private:
};

#endif // __BOX_COLLIDER_HPP__
