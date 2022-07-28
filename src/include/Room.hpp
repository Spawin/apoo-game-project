#if !defined(__ROOM_HPP__)
	#define __ROOM_HPP__

	#include "include/Hall.hpp"

class Hall;

class Room : public Hall
{
public:
	Room(sf::Vector2i topLeftPoint, int width, int height);
	~Room();

private:
};

#endif // __ROOM_HPP__
