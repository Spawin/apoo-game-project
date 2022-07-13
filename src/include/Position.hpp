#ifndef __POSITION_HPP__
#define __POSITION_HPP__

#include "include/MyVector.hpp"

class Position
{
public:
	Position();
	Position(float px, float py);
	~Position();

	static void initSpace(int width, int height); // méthode static car l’espace sera le même pour tous les objets Coordonnees
	static inline int getSpaceWidth()
	{
		return m_spaceWidth;
	};
	static inline int getSpaceHeight()
	{
		return m_spaceHeight;
	};

	// inline pour plus de performance, revient en terme de performance à un accès direct à l’attribut
	inline float getX() const
	{
		return x;
	};
	inline float getY() const
	{
		return y;
	};

	float getDistanceWith(Position const& autre) const;
	void operator+=(MyVector const& v);

private:
	void recalculate(); // recalcule les coordonnées pour qu’elles soient dans les limites ; inutile d’y accéder de l’extérieur, donc privée
	float x { m_spaceWidth / 2.f };
	float y { m_spaceHeight / 2.f };

	// longueur et hauteur de l’espace sont static, partagés par tous les objets Coordonnees
	static int m_spaceWidth;
	static int m_spaceHeight;
};

#endif // __POSITION_HPP__