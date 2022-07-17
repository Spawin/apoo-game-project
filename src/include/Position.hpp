#ifndef __POSITION_HPP__
#define __POSITION_HPP__

#include "include/MyVector.hpp"
#include "include/consts.hpp"

class Position
{
public:
	explicit Position(float detectabilityRadius = DEFAULT_DETECTABILITY_RADIUS);

	explicit Position(float px, float py, float detectabilityRadius = DEFAULT_DETECTABILITY_RADIUS);
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
		return m_x;
	};
	inline float getY() const
	{
		return m_y;
	};

	/**
	 * @brief Get the Distance With object
	 *
	 * @param autre
	 * @return float
	 */
	float getDistanceWith(Position const& autre) const;

	/**
	 * @brief Set the Position object
	 *
	 * @param posX
	 * @param posY
	 */
	void setPosition(float posX, float posY);

	void operator+=(MyVector const& v);
	void operator=(Position const& p);

private:
	// recalcule les coordonnées pour qu’elles soient dans les limites ; inutile d’y accéder de l’extérieur, donc privée
	void recalculate();
	float m_x { m_spaceWidth / 2.f };  // REVIEW -
	float m_y { m_spaceHeight / 2.f }; // REVIEW -

	// longueur et hauteur de l’espace sont static, partagés par tous les objets Coordonnees
	static int m_spaceWidth;
	static int m_spaceHeight;

	float const DETECTABILITY_RADIUS;

	/**
	 * @brief Vérifie si l'élément peut bouger
	 *
	 * @return true
	 * @return false
	 */
	bool canMove();
};

#endif // __POSITION_HPP__