#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "include/Personage.hpp"

class Player
{
public:
	Player();
	~Player();

private:
	Personage* m_personnage;
};

#endif // __PLAYER_HPP__
