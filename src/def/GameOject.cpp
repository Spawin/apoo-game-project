#include "include/GameOject.hpp"

float GameOject::m_time = 0.f;

GameOject::GameOject()
{
	//* Chargement d'une image par defaut
	if (!m_texture.loadFromFile("content/sfml.png"))
	{
		std::cerr << "Image < content/sfml.png > introuvable" << std::endl;
	}
	m_body.setTexture(m_texture);

	m_body.setOrigin(m_body.getLocalBounds().width / 2, m_body.getLocalBounds().height / 2);
	m_body.setPosition(m_position.getX(), m_position.getY());
}

GameOject::GameOject(std::string_view const& imageSpritePath)
{

	if (!m_texture.loadFromFile(imageSpritePath.data()))
	{
		std::cerr << "Image < " << imageSpritePath << " > introuvable" << std::endl;
	}
	m_body.setTexture(m_texture);
	// m_body.setColor();
	// On définit son centre de "gravité"
	m_body.setOrigin(m_body.getLocalBounds().width / 2, m_body.getLocalBounds().height / 2);
	m_body.setPosition(m_position.getX(), m_position.getY());
}

GameOject::~GameOject()
{}

void GameOject::show(sf::RenderWindow& window) const
{
	window.draw(m_body);
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
