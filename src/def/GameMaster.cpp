#include "include/GameMaster.hpp"

using namespace std;

//
const sf::Vector2i GameMaster::m_spriteBoxCenter(17, 16);
int GameMaster::m_countInstance = 0;
GameMaster* GameMaster::m_gameMaster = nullptr;

//
void GameMaster::initWindow()
{
	//
}

GameMaster::GameMaster()
{
	m_countInstance++;
	if (m_countInstance > 1)
	{
		cerr << "LE game master ne doit pas etre instancié plus d'une fois" << endl;
		exit(-1);
	}

	GameMaster::m_gameMaster = this;
}

GameMaster::~GameMaster()
{
}

//

const sf::Vector2i GameMaster::getSPRITE_BOX_CENTER()
{
	return m_spriteBoxCenter;
}

const GameMaster* GameMaster::GAME_MASTER()
{
	return m_gameMaster;
}

//

void GameMaster::updateSFMLEvents()
{}
void GameMaster::update()
{}
void GameMaster::render()
{}
void GameMaster::run()
{}
