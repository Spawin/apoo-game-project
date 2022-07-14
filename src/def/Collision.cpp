#include "include/Collision.hpp"

Collision::Collision(GameObject const& gameObject) :
	m_gameObject((GameObject*)&gameObject)
{
}

Collision::~Collision()
{
	delete m_gameObject;
}