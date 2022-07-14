#ifndef __COLLIDER_HPP_
#define __COLLIDER_HPP_

#include "include/GameObject.hpp"
#include <iostream>
#include <map>
#include <memory>
#include <string>

class GameObject;

class Collider
{
public:
	Collider(GameObject const& parent);
	virtual ~Collider();

	static void update();

protected:
	// Il s'agit de l'object auquel appartient le game object
	// GameObject const& parent;
	GameObject const& parent;
	// static std::map<std::string, GameObject*> m_objects;
	static std::map<std::string, std::shared_ptr<GameObject>> m_objects;
};

#endif // __COLLIDER_HPP_
