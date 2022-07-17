#include "include/PolygonCollider.hpp"
#include "include/GameMap.hpp"
#include "include/MyVector.hpp"
#include "include/consts.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

PolygonCollider::PolygonCollider(GameObject const& parent, std::vector<sf::Vector2f> contactPoints) :
	Collider(parent, contactPoints)
{
}

PolygonCollider::~PolygonCollider()
{
}

bool PolygonCollider::touchEachOther(Collider const& collider) const
{

	// Comparaison de la proximité de tous les points
	for (size_t i = 0; i < (*this).m_contactPoints.size(); i++)
	{
		sf::Vector2f v1 = (*this).m_contactPoints[i];
		MyVector c1 = (*this).parent.getPosition().getPosition();
		v1.x += c1.m_x;
		v1.y += c1.m_y;
		for (size_t j = 0; j < collider.getContactPoints().size(); j++)
		{
			sf::Vector2f v2 = collider.getContactPoints()[j];
			MyVector c2 = collider.getParent().getPosition().getPosition();
			v2.x += c2.m_x;
			v2.y += c2.m_y;

			// auto delta = MyVector { min({ abs(v1.x - v2.x), abs(v1.x - v2.x - (int)GameMap::getGAME_MAP_WIDTH), abs(v1.x - v2.x + (int)GameMap::getGAME_MAP_WIDTH) }), min({ abs(v1.y - v2.y), abs(v1.y - v2.y - (int)GameMap::getGAME_MAP_HEIGHT), abs(v1.y - v2.y + (int)GameMap::getGAME_MAP_HEIGHT) }) };
			// return 0 < sqrt(delta.m_x * delta.m_x + delta.m_y * delta.m_y);
			float deltat = sqrt(pow((v1.x - v2.x), 2) + pow((v1.y - v2.y), 2));
			// cout << "distance entre A(" << v1.x << ";" << v1.y;
			// cout << ") et B(" << v2.x << ";" << v2.y << ") est : " << deltat << endl;
			return deltat < (float)DISTANCE_MIN_BETWEEN_OBJECTS;
		}
	}
	return false;
}