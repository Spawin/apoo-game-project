#if !defined(__HOUSE_HPP__)
	#define __HOUSE_HPP__

	#include "include/GameMap.hpp"
	#include "include/consts.hpp"

class House : public GameMap
{
public:
	House();
	~House();

	const int* getDisposition() const;

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	const int m_disposition[game::HOUSE_TILES_NUMBER]; // REVIEW -
};

#endif // __HOUSE_HPP__
