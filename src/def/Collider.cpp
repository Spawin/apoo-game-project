#include "include/Collider.hpp"
#include "include/Position.hpp"
#include "include/consts.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility> // std::pair
#include <vector>

#include "include/Personage.hpp"

using namespace std;

// map<string, GameObject*> Collider::m_objects = map::
map<string, GameObject*> Collider::m_objects = {};

Collider::Collider(GameObject const& parent) :
	parent(parent)
{
	m_objects.insert({ to_string(parent.getGameObjectId()), (GameObject*)&parent }); // REVIEW -
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
	map<string, GameObject*>::iterator it = m_objects.begin();
	// Pour receillir les clés des object déjà parcourut
	vector<string> already = {};
	// for (auto&& gameObject : m_objects)
	for (pair<string, GameObject*> gameObject_1 : m_objects)
	{
		const Position* gameObject_1_position = gameObject_1.second->getPosition();
		for (pair<string, GameObject*> gameObject_2 : m_objects)
		{
			if (find(already.begin(), already.end(), gameObject_1.first) != already.end())
				continue;

			const Position* gameObject_2_position = gameObject_2.second->getPosition();

			if (gameObject_1_position->getDistanceWith((*gameObject_2_position)) <= (float)DISTANCE_MIN_BETWEEN_OBJECTS)
			{
				Personage p = Personage();
				Personage p2 = *(*m_objects[gameObject_1.first]);

				gameObject_1.second->onCollisionEnter(Collision(p));
				gameObject_2.second->onCollisionEnter(Collision(m_objects[gameObject_1.first]));
			}
		}
		already.push_back(gameObject_1.first);
	}
}