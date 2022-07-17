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
	explicit Collider(GameObject const& parent, std::vector<sf::Vector2f> contactPoints);
	virtual ~Collider();

	/**
	 * @brief C'est à ce niveau qu'on gère la détection de collisions.
	 *
	 */
	static void update();

    GameObject const& getParent() const;

	std::vector<sf::Vector2f> const& getContactPoints() const;
	virtual bool touchEachOther(Collider const& collider) const = 0;

protected:
	// Il s'agit de l'object auquel appartient le game object
	GameObject const& parent;
	static GameObjectMap m_objects;

	std::vector<sf::Vector2f> m_contactPoints;
	// static std::vector<const GameObject*> m_vectors;
	// static std::map<std::string, std::shared_ptr<GameObject>> m_objects;
};

#endif // __COLLIDER_HPP_
