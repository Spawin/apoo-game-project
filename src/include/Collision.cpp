#include "include/Collision.hpp"
#include <memory>

using namespace std;

Collision::Collision(GameObject const& gameObject) :
	// m_gameObject((GameObject*)&gameObject)
	m_gameObject(gameObject)
// Collision::Collision(shared_ptr<GameObject> gameObject) :
// 	m_gameObject((GameObject*)&gameObject)
{
}

Collision::~Collision()
{
	// delete m_gameObject;
}

GameObject const& Collision::getGameObject() const
{
	return m_gameObject;
}

void Collision::test() const
{}
