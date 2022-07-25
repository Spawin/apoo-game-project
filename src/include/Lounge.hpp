#if !defined(__LOUNGE_HPP__)
	#define __LOUNGE_HPP__

	#include "include/Hall.hpp"

class Lounge : public Hall
{
public:
	Lounge(sf::Vector2i topLeftPoint, int width, int height);
	~Lounge();

private:
};

#endif // __LOUNGE_HPP__
