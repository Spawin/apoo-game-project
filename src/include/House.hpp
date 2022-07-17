#if !defined(__HOUSE_HPP__)
	#define __HOUSE_HPP__

	#include "include/GameMap.hpp"

class House : public GameMap
{
public:
	House();
	~House();

	const int* getDisposition() const;

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	const int m_disposition[3200]; // REVIEW -
};

#endif // __HOUSE_HPP__
