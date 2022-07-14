#ifndef __COLLISION_HPP__
#define __COLLISION_HPP__

#include "include/GameObject.hpp"

class Collision
{
public:
	Collision(GameObject const& gameObject);
	~Collision();

private:
	GameObject* m_gameObject;
};

#endif // __COLLISION_HPP__
