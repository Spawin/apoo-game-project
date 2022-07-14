#include "include/Collider.hpp"
#include "include/Collision.hpp"
#include "include/Position.hpp"
#include "include/consts.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <utility> // std::pair
#include <vector>

#include "include/Personage.hpp"

using namespace std;

// map<string, GameObject*> Collider::m_objects = map::
// map<string, GameObject*> Collider::m_objects = {};
map<string, shared_ptr<GameObject>> Collider::m_objects = {};

Collider::Collider(GameObject const& parent) :
	parent(parent)
{
	// m_objects.insert({ to_string(parent.getGameObjectId()), (GameObject*)&parent }); // REVIEW -
	// m_objects.insert({ to_string(parent.getGameObjectId()), parent }); // REVIEW -
	// m_objects[to_string(parent.getGameObjectId())] = shared_ptr<GameObject>((GameObject*)&parent);

	// m_objects[to_string(parent.getGameObjectId())] = make_shared<GameObject>((GameObject*)&parent);
	// m_objects.insert({ to_string(parent.getGameObjectId()), make_shared<GameObject>(parent) });

	cout << "dans le constructeur du collider" << endl;
	m_objects.insert({ to_string(parent.getGameObjectId()), make_shared<GameObject>(parent) });
}

Collider::~Collider()
{}

void Collider::update()
{

	/**
	 * Ici on va juste vérifier la proximité de 2 objets
	 * pour les informer si ils sont en contact ou non
	 *
	 */
	map<string, shared_ptr<GameObject>>::iterator it;
	// Pour receillir les clés des object déjà parcourut
	vector<string> already = {};
	// for (auto&& gameObject : m_objects)
	// for (pair<string, GameObject*> gameObject_1 : m_objects)
	for (it = m_objects.begin(); it != m_objects.end(); ++it)
	{
		// const Position* gameObject_1_position = gameObject_1.second->getPosition();
		// const Position* gameObject_1_position = it->second->getPosition();
		// for (pair<string, GameObject*> gameObject_2 : m_objects)
		// map<string, GameObject*>::iterator it2;
		map<string, shared_ptr<GameObject>>::iterator it2;
		for (it2 = m_objects.begin(); it2 != m_objects.end(); ++it2)
		{
			if (find(already.begin(), already.end(), it->first) != already.end())
				continue;

			// const Position* gameObject_2_position = it2->second->getPosition();

			if (it->second->getPosition()->getDistanceWith((*(it2->second->getPosition()))) <= (float)DISTANCE_MIN_BETWEEN_OBJECTS)
			{
				it->second->onCollisionEnter(Collision(it2->second));
				it2->second->onCollisionEnter(Collision(it->second));
			}

			// delete gameObject_2_position;
		}
		already.push_back(it->first);

		// delete gameObject_1_position;
	}
}