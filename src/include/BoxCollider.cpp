#include "include/BoxCollider.hpp"

const std::string BoxCollider::m_name("BoxCollider");

/*
BoxCollider::BoxCollider(GameObject const& parent, std::vector<sf::Vector2f> contactPoints) :
	Collider(parent, contactPoints)
{
	if(contactPoints.size() > 4) {
		//
	}
}
//*/
BoxCollider::BoxCollider(GameObject const& parent, float width, float height, sf::Vector2f leftTopPoint) :
	Collider(parent, "BoxCollider"),
	m_width(width),
	m_height(height),
	m_leftTopPoint(leftTopPoint)
{}

BoxCollider::~BoxCollider()
{
}

// -------------

const std::string BoxCollider::getName()
{
	return m_name;
}

std::vector<sf::Vector2f> BoxCollider::getContactPoints() const
{
	return {
		sf::Vector2f(m_leftTopPoint),
		sf::Vector2f(m_leftTopPoint.x + m_width, m_leftTopPoint.y),
		sf::Vector2f(m_leftTopPoint.x + m_width, m_leftTopPoint.y - m_height),
		sf::Vector2f(m_leftTopPoint.x, m_leftTopPoint.y - m_height),
	};
}

bool BoxCollider::touchEachOther(Collider const& collider) const
{
	// REVIEW -  On va considérer que c'est un box collider

	// Comparaison de la proximité de tous les points
	MyVector c1 = (*this).parent.getPosition().getPosition();
	MyVector c2 = collider.getParent().getPosition().getPosition();
	for (size_t j = 0; j < collider.getContactPoints().size(); j++)
	{
		sf::Vector2f p2 = collider.getContactPoints()[j];
		p2.x += c2.m_x;
		p2.y += c2.m_y;

		// sf::Vector2f point = collider.getContactPoints()[j];
		if ((m_leftTopPoint.x + c1.m_x) < p2.x && p2.x < (m_leftTopPoint.x + c1.m_x + m_width))
		{
			if ((m_leftTopPoint.y + c1.m_y - m_height) < p2.y && p2.y < (m_leftTopPoint.y + c1.m_y))
			{
				return true;
			}
		}
	}

	/*
	for (size_t i = 0; i < (*this).m_contactPoints.size(); i++)
	{
		for (size_t j = 0; j < collider.getContactPoints().size(); j++)
		{
			// Comparaison de la proximité de tous les points
		}
	}
	//*/
	return false;
}