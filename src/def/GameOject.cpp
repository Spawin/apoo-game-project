#include "include/GameOject.hpp"

GameOject::GameOject()
{}
GameOject::~GameOject()
{}

void GameOject::show(sf::RenderWindow& window) const
{
	window.draw(m_body);
}

void GameOject::update(float time)
{
	m_time = time;
}

// void GameOject::sendEvent(sf::Event const& event)
// {
// 	if (event.type == sf::Event::KeyPressed)
// 	{
// 		if (event.key.code == sf::Keyboard::Right)
// 		{
// 			m_speed2.x = MOVE_SPEED * m_time;
// 			m_speed = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
// 		}
// 		if (event.key.code == sf::Keyboard::Left)
// 		{
// 			m_speed2.x = -MOVE_SPEED * m_time;
// 			m_speed = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
// 		}
// 		if (event.key.code == sf::Keyboard::Up)
// 		{
// 			m_speed2.y = -MOVE_SPEED * m_time;
// 			m_speed = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
// 		}
// 		if (event.key.code == sf::Keyboard::Down)
// 		{
// 			m_speed2.y = MOVE_SPEED * m_time;
// 			m_speed = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
// 		}
// 	}
// 	else if (event.type == sf::Event::KeyReleased)
// 	{
// 		m_speed.x = 0;
// 		m_speed.y = 0;
// 	}
// }
