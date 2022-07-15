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
// map<string, shared_ptr<GameObject>> Collider::m_objects = {};

Collider::GameObjectMap Collider::m_objects = [] {
	GameObjectMap ret;
	return ret;
}();

Collider::Collider(GameObject const& parent) :
	parent(parent)
{
	// m_objects.insert({ to_string(parent.getGameObjectId()), (GameObject*)&parent }); // REVIEW -

	cout << "dans le constructeur du collider" << endl;
	// m_objects.insert({ to_string(parent.getGameObjectId()), make_shared<GameObject>(parent) });

	Collider::m_objects.insert({ to_string(parent.getGameObjectId()), &parent });
}

Collider::~Collider()
{}

void Collider::update()
{
	//
	GameObjectMap::iterator it1;
	// Pour lister les collider déjà testés
	vector<string> alreadyChecked = {};

	// cout << "nombre d'objet avec collider " << m_objects.size() << endl;
	for (it1 = m_objects.begin(); it1 != m_objects.end(); ++it1)
	{
		alreadyChecked.push_back(it1->first);
		GameObjectMap::iterator it2;
		for (it2 = m_objects.begin(); it2 != m_objects.end(); ++it2)
		{
			if (find(alreadyChecked.begin(), alreadyChecked.end(), it2->first) != alreadyChecked.end())
				continue;

			// if (it1->second->getPosition().getDistanceWith(it2->second->getPosition()) < (float)DISTANCE_MIN_BETWEEN_OBJECTS)
			// On va dabor tester la proximité des deux entité par rapport à une constante qui définit la distance minimale entre 2 object
			if (m_objects[it1->first]->getPosition().getDistanceWith(m_objects[it2->first]->getPosition()) < (float)DISTANCE_MIN_BETWEEN_OBJECTS)
			{
				// cout << "1 - " << m_objects[it1->first]->getGameObjectName() << " " << m_objects[it1->first]->getGameObjectId() << endl;
				// cout << "2 - " << m_objects[it2->first]->getGameObjectName() << " " << m_objects[it2->first]->getGameObjectId() << endl;

				// cout << "distance entre les deux " << it1->second->getPosition().getDistanceWith(it2->second->getPosition()) << endl;
				if (m_objects[it1->first]->getSprite().getLocalBounds().intersects(m_objects[it2->first]->getSprite().getLocalBounds()))
				{
					m_objects[it1->first]->onCollisionEnter(Collision(*m_objects[it2->first]));
					m_objects[it2->first]->onCollisionEnter(Collision(*m_objects[it1->first]));
				}
			}
		}
	}
}

// void Collider::update()
// {

// 	/**
// 	 * Ici on va juste vérifier la proximité de 2 objets
// 	 * pour les informer si ils sont en contact ou non
// 	 *
// 	 */
// 	map<string, shared_ptr<GameObject>>::iterator it;
// 	// Pour receillir les clés des object déjà parcourut
// 	vector<string> alreadyChecked = {};
// 	// for (auto&& gameObject : m_objects)
// 	// for (pair<string, GameObject*> gameObject_1 : m_objects)
// 	for (it = m_objects.begin(); it != m_objects.end(); ++it)
// 	{
// 		// const Position* gameObject_1_position = gameObject_1.second->getPosition();
// 		// const Position* gameObject_1_position = it->second->getPosition();
// 		// for (pair<string, GameObject*> gameObject_2 : m_objects)
// 		// map<string, GameObject*>::iterator it2;
// 		map<string, shared_ptr<GameObject>>::iterator it2;
// 		for (it2 = m_objects.begin(); it2 != m_objects.end(); ++it2)
// 		{
// 			if (find(alreadyChecked.begin(), alreadyChecked.end(), it->first) != alreadyChecked.end())
// 				continue;

// 			// const Position* gameObject_2_position = it2->second->getPosition();

// 			if (it->second->getPosition()->getDistanceWith((*(it2->second->getPosition()))) <= (float)DISTANCE_MIN_BETWEEN_OBJECTS)
// 			{
// 				it->second->onCollisionEnter(Collision(it2->second));
// 				it2->second->onCollisionEnter(Collision(it->second));
// 			}

// 			// delete gameObject_2_position;
// 		}
// 		alreadyChecked.push_back(it->first);

// 		// delete gameObject_1_position;
// 	}
// }
