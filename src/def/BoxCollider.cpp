#include "include/BoxCollider.hpp"

BoxCollider::BoxCollider(GameObject const& parent, std::vector<sf::Vector2f> contactPoints) :
	Collider(parent, contactPoints)
{
}

BoxCollider::~BoxCollider()
{
}

bool BoxCollider::touchEachOther(Collider const& collider) const
{

	for (size_t i = 0; i < (*this).m_contactPoints.size(); i++)
	{
		for (size_t j = 0; j < collider.getContactPoints().size(); j++)
		{
			// Comparaison de la proximité de tous les points
		}
	}
	return true;
}