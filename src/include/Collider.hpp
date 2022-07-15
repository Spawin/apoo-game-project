#ifndef __COLLIDER_HPP_
#define __COLLIDER_HPP_

#include "include/GameObject.hpp"
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

class GameObject;

class Collider
{
	using GameObjectMap = std::map<std::string, const GameObject*>;

public:
	explicit Collider(GameObject const& parent);
	virtual ~Collider();

	/**
	 * @brief C'est à ce niveau qu'on gère la détection de collisions.
	 *
	 */
	static void update();

protected:
	// Il s'agit de l'object auquel appartient le game object
	// GameObject const& parent;
	GameObject const& parent;
	static GameObjectMap m_objects;
	// static std::vector<const GameObject*> m_vectors;
	// static std::map<std::string, std::shared_ptr<GameObject>> m_objects;
};

#endif // __COLLIDER_HPP_
