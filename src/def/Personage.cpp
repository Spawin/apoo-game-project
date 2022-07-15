#include "include/Personage.hpp"
#include "include/BoxCollider.hpp"
#include "include/MyVector.hpp"

#include <iostream>
#include <string>

using namespace std;

Personage::Personage(bool isPlayer) :
	m_isPlayer(isPlayer)
{
	m_width = 50;
	m_height = 150;

	m_gameObjectName = "Personage";

	m_collider = new BoxCollider((*this));
}

Personage::Personage(std::string_view const& imageSpritePath, bool isPlayer) :
	GameObject(imageSpritePath),
	m_isPlayer(isPlayer)
{
	m_width = 50;
	m_height = 150;

	m_gameObjectName = "Personage";

	m_collider = new BoxCollider((*this));
}

Personage::Personage(float posX, float posY, bool isPlayer) :
	GameObject(posX, posY),
	m_isPlayer(isPlayer)
{
	m_width = 50;
	m_height = 150;

	m_gameObjectName = "Personage";

	m_collider = new BoxCollider((*this));
}

Personage::~Personage()
{
	// delete m_collider; // Déjà fait au niveau du GameObject.
}

void Personage::update()
{
	updatePosition();
}

void Personage::setGameObjectName(string name)
{
	m_gameObjectName = name;
}

void Personage::onCollisionEnter(Collision const& collision) const
{
	collision.test();
	if (m_isPlayer)
	{
		cout << "Collision de " << m_gameObjectName << " avec "
			 << "*(collision.getGameObject())->getGameObjectName()" << endl;
	}
}

void Personage::updatePosition()
{
	if (m_isPlayer)
	{
		// Gestion du déplacement du joueur.
		bool anyDirectionalKeyIsPressed(false);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// m_speed.x = MOVE_SPEED * m_time;
			// m_speed2 = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
			m_speed = MyVector::createFromAngle(MOVE_SPEED * m_time, 0.f);
			anyDirectionalKeyIsPressed = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// m_speed.x = -MOVE_SPEED * m_time;
			// m_speed2 = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
			m_speed = MyVector::createFromAngle(MOVE_SPEED * m_time, 180.f);
			anyDirectionalKeyIsPressed = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// m_speed.y = -MOVE_SPEED * m_time;
			// m_speed2 = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
			m_speed = MyVector::createFromAngle(MOVE_SPEED * m_time, 270.f);
			anyDirectionalKeyIsPressed = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// m_speed.y = MOVE_SPEED * m_time;
			// m_speed2 = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
			m_speed = MyVector::createFromAngle(MOVE_SPEED * m_time, 90.f);
			anyDirectionalKeyIsPressed = true;
		}

		// if (event.type == sf::Event::KeyReleased)
		if (!anyDirectionalKeyIsPressed)
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
}