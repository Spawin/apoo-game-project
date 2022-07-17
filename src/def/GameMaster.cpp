#include "include/GameMaster.hpp"

const sf::Vector2i GameMaster::m_spriteBoxCenter(17, 16);

GameMaster::GameMaster()
{
}

GameMaster::~GameMaster()
{
}

//

const sf::Vector2i GameMaster::getSPRITE_BOX_CENTER()
{
	return m_spriteBoxCenter;
}
