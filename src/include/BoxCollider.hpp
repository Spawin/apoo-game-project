#ifndef __BOX_COLLIDER_HPP__
#define __BOX_COLLIDER_HPP__

#include "include/Collider.hpp"

class BoxCollider : public Collider
{
public:
	BoxCollider(GameObject const& parent);
	~BoxCollider();

	void update();

private:
};

#endif // __BOX_COLLIDER_HPP__
