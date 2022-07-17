#include "include/Rigidbody.hpp"

using namespace std;

Rigidbody::Rigidbody(GameObject& parent) :
	m_parent(parent)
{
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::onAnotherRigidBodyDetection()
{
	// m_parent.m_position.m_thereIsARigidBody = true;
}
