#if !defined(__RIGID_BODY_HPP__)
	#define __RIGID_BODY_HPP__

	#include "include/Position.hpp"
	#include "include/GameObject.hpp"

class GameObject;

class Rigidbody
{
public:
	Rigidbody(GameObject& parent);
	~Rigidbody();

	void onAnotherRigidBodyDetection();

protected:
	GameObject& m_parent;
};

#endif // __RIGID_BODY_HPP__
