#ifndef __MYVECTOR_HPP__
#define __MYVECTOR_HPP__

// TODO - Encapsulation....

struct MyVector
{
	void operator+=(MyVector const& v);
	void operator-=(MyVector const& v);
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
};

#endif // __MYVECTOR_HPP__
