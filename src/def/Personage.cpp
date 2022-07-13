#include "include/Personage.hpp"
#include "include/MyVector.hpp"

Personage::Personage()
{
	if (!m_texture.loadFromFile("content/sfml.png"))
	{
		std::cerr << "Image introuvable" << std::endl;
	}
	m_body.setTexture(m_texture);
	// m_body.setColor();
	// On place le personnage au milieu de l'
	m_body.setOrigin(m_body.getLocalBounds().width / 2, m_body.getLocalBounds().height / 2);
	m_body.setPosition(m_position.getX(), m_position.getY());
}

void Personage::update(float time)
{
	updatePosition();
	m_time = time;
}

void Personage::updatePosition()
{
	bool anyKeyIsPressed(true);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		// m_speed.x = MOVE_SPEED * m_time;
		// m_speed2 = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
		m_speed = MyVector::createFromAngle(MOVE_SPEED * m_time, 0.f);
		anyKeyIsPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		// m_speed.x = -MOVE_SPEED * m_time;
		// m_speed2 = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
		m_speed = MyVector::createFromAngle(MOVE_SPEED * m_time, 180.f);
		anyKeyIsPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		// m_speed.y = -MOVE_SPEED * m_time;
		// m_speed2 = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
		m_speed = MyVector::createFromAngle(MOVE_SPEED * m_time, 270.f);
		anyKeyIsPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		// m_speed.y = MOVE_SPEED * m_time;
		// m_speed2 = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
		m_speed = MyVector::createFromAngle(MOVE_SPEED * m_time, 90.f);
		anyKeyIsPressed = false;
	}

	// if (event.type == sf::Event::KeyReleased)
	if (anyKeyIsPressed)
	{
		// m_speed.x = 0;
		// m_speed.y = 0;

		m_speed.m_x = 0;
		m_speed.m_y = 0;
	}

	// m_body.move(m_speed);
	// m_body.move(m_speed2.m_x, m_speed2.m_y);
	m_position += m_speed; // * m_time;
	m_body.setPosition(m_position.getX(), m_position.getY());
}