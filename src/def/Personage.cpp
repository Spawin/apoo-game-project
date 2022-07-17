#include "include/Personage.hpp"
#include "include/BoxCollider.hpp"
#include "include/MyVector.hpp"

#include <iostream>
#include <string>

#include "include/consts.hpp"

using namespace std;

void Personage::init()
{
	m_width = 32;
	m_height = 50;

	m_gameObjectName = "Personage";

	m_collider = new BoxCollider((*this));

	int w(32);
	int h(32);
	m_body.setTextureRect(sf::IntRect(0, 0, w, h));
	m_body.setScale((float)PERSONNAGE_WIDTH / (float)w, (float)PERSONNAGE_WIDTH / (float)h);
	if (m_isPlayer)
	{
		m_position = Position(32 * 4, 32 * 78); // REVIEW -
		m_body.setPosition(m_position.getX(), m_position.getY());
	}
}

Personage::Personage(bool isPlayer) :
	m_isPlayer(isPlayer)
{
	init();
}

Personage::Personage(std::string_view const& imageSpritePath, bool isPlayer) :
	GameObject(imageSpritePath),
	m_isPlayer(isPlayer)
{
	init();
}

Personage::Personage(float posX, float posY, bool isPlayer) :
	GameObject(posX, posY),
	m_isPlayer(isPlayer)
{
	init();
}

Personage::~Personage()
{
	// delete m_collider; // Déjà fait au niveau du GameObject.
	m_window = 0;
}

void Personage::show(sf::RenderWindow& window)
{
	GameObject::show(window);
	m_window = &window;
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
			 << "collision.getGameObject()->getGameObjectName()" << endl;
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
		// MyVector mv{0.f,0.f};
		// mv += m_position.getPosition();
		// mv += m_speed

		//* On applique des modification si la position à changé
		// REVIEW - (ceci n'est pas encore fait) Ou si le centre de la vue est différent de la position du joueur
		// if ( m_position.getPosition() != m_body.getPosition())
		// || m_body.getPosition() != m_window->getView().getCenter()
		if (m_speed != sf::Vector2f(0.f, 0.f))
		{
			m_position += m_speed; // * m_time;
			// On replace le body
			m_body.setPosition(m_position.getX(), m_position.getY());
			cout << "Position du joueur " << m_position << endl;

			// On replace la vue
			if (m_window != 0)
			{
				// cout << "On replace la vue" << endl;
				sf::View player_view(m_window->getView());
				player_view.setCenter(m_position.getX(), m_position.getY());
				m_window->setView(player_view);
			}
		}
		// cout << "pose x=" << m_position.getX() << " y=" << m_position.getY() << endl;
	}
}