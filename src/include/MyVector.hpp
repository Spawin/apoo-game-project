#ifndef __MYVECTOR_HPP__
#define __MYVECTOR_HPP__

#include "include/consts.hpp"
#include <cmath>
#define M_PI 3.14159265358979323846

struct MyVector
{
	void operator+=(MyVector const& v);
	void operator-=(MyVector const& v);
	bool operator==(MyVector const& v);
	bool operator!=(sf::Vector2f const& v);
	MyVector operator*(float coefficient) const;
	/**
	 * @brief
	 *
	 * @param simpleSize taille
	 * @param angleInDegree angle en degrée
	 * @return MyVector
	 */
	static MyVector createFromAngle(float simpleSize, float angleInDegree);
	float m_x { 0.f };
	float m_y { 0.f };
	sf::Vector2f toVector2f();
};

#endif // __MYVECTOR_HPP__
