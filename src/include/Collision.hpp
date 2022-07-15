#ifndef __COLLISION_HPP__
#define __COLLISION_HPP__

#include "include/GameObject.hpp"
#include <memory>

class GameObject;

class Collision
{
public:
	explicit Collision(GameObject const& gameObject);
	// explicit Collision(std::shared_ptr<GameObject> gameObject);
	~Collision();

	/**
	 * @brief Get the Game Object object
	 *
	 * @return std::shared_ptr<GameObject>
	 */
	std::shared_ptr<GameObject> getGameObject() const;

	inline void test() const {}; // TODO - Remove this after

private:
	GameObject const& m_gameObject;
	// std::shared_ptr<GameObject> m_gameObject;
};

#endif // __COLLISION_HPP__
