#include "include/MyVector.hpp"

void MyVector::operator+=(MyVector const& v)
{
	m_x += v.m_x;
	m_y += v.m_y;
}

void MyVector::operator-=(MyVector const& v)
{
	m_x -= v.m_x;
	m_y -= v.m_y;
}

bool MyVector::operator==(MyVector const& v)
{
	return m_x == v.m_x && m_y == v.m_y;
}

bool MyVector::operator!=(sf::Vector2f const& v)
{
	return m_x != v.x || m_y != v.y;
}

MyVector MyVector::operator*(float coefficient) const
{
	return { m_x * coefficient, m_y * coefficient };
}

MyVector MyVector::createFromAngle(float simpleSize, float angleInDegree)
{
	// return { simpleSize * static_cast<float>(cos(angleInDegree / 180.0000f * static_cast<float>(M_PI))), simpleSize * static_cast<float>(sin(angleInDegree / 180.0000f * M_PI)) };
	return { simpleSize * static_cast<float>(cos(angleInDegree / 180.0000f * M_PI)), simpleSize * static_cast<float>(sin(angleInDegree / 180.0000f * M_PI)) };
}

sf::Vector2f MyVector::toVector2f()
{
	return sf::Vector2f(m_x, m_y);
}
