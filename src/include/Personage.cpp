#include "include/Personage.hpp"
#include "include/MyVector.hpp"
#include "include/PolygonCollider.hpp"
#include "include/Rigidbody.hpp"

#include <iostream>
#include <string>

#include "include/GameMaster.hpp"
#include "include/consts.hpp"

using namespace std;

void Personage::init()
{
	// m_width = 32;
	// m_height = 50;

	m_gameObjectName = "Personage";

	// m_texture.setSmooth(true);

	// m_body.setScale(0.3f, 0.3f);
	// m_body.setColor(sf::Color::White);

	// On définit son centre de "gravité"
	// m_body.setOrigin(m_body.getLocalBounds().width / 2, m_body.getLocalBounds().height / 2);
	// m_body.setOrigin(PERSONNAGE_WIDTH / 2, PERSONNAGE_WIDTH / 2);

	// m_collider = new PolygonCollider((*this), { sf::Vector2f(18.f - GameMaster::getSPRITE_BOX_CENTER().x, 5.f - GameMaster::getSPRITE_BOX_CENTER().y), sf::Vector2f(22.f - GameMaster::getSPRITE_BOX_CENTER().x, 12.f - GameMaster::getSPRITE_BOX_CENTER().y), sf::Vector2f(22.f - GameMaster::getSPRITE_BOX_CENTER().x, 20.f - GameMaster::getSPRITE_BOX_CENTER().y), sf::Vector2f(18.f - GameMaster::getSPRITE_BOX_CENTER().x, 27.f - GameMaster::getSPRITE_BOX_CENTER().y), sf::Vector2f(11.f - GameMaster::getSPRITE_BOX_CENTER().x, 22.f - GameMaster::getSPRITE_BOX_CENTER().y), sf::Vector2f(11.f - GameMaster::getSPRITE_BOX_CENTER().x, 12.f - GameMaster::getSPRITE_BOX_CENTER().y) });
	// m_collider = new PolygonCollider((*this), { sf::Vector2f(18.f - m_body.getOrigin().x, 5.f - m_body.getOrigin().y), sf::Vector2f(22.f - m_body.getOrigin().x, 12.f - m_body.getOrigin().y), sf::Vector2f(22.f - m_body.getOrigin().x, 20.f - m_body.getOrigin().y), sf::Vector2f(18.f - m_body.getOrigin().x, 27.f - m_body.getOrigin().y), sf::Vector2f(11.f - m_body.getOrigin().x, 22.f - m_body.getOrigin().y), sf::Vector2f(11.f - m_body.getOrigin().x, 12.f - m_body.getOrigin().y) });

	m_rigidbody = new Rigidbody((*this));

	// int w(32);
	// int h(32);
	// m_body.setTextureRect(sf::IntRect(0, 0, w, h)); // REVIEW - Un personnage par défaut plus stylé

	// m_body.setScale((float)PERSONNAGE_WIDTH / (float)w, (float)PERSONNAGE_WIDTH / (float)h);

	// Initialisation de la position en temps que joeurs
	if (m_isPlayer)
	{
		// m_position = Position(32 * 4, 32 * 78); // REVIEW -
		m_position = Position(32 * 4, 32 * 4);
		m_body.setPosition(m_position.getX(), m_position.getY());
	}
	else
	{
		// TODO -
		m_position = Position(32 * 20 + 16, 32 * 70); // REVIEW -
		m_body.setPosition(m_position.getX(), m_position.getY());
	}

	// m_body.setScale(.3f, .3f);
}

void Personage::initAnimations()
{
	// Création du gestionnaire d'animation
	this->createAnimationComponent(m_texture);
	// Ajout des animations
	this->animationComponent->addAnimation(4, "RIGHT_IDLE", 10.f, 0, 0, 0, 0, 150, 150);
	this->animationComponent->addAnimation(3, "RIGHT_WALK", 10.f, 0, 0, 3, 0, 150, 150);				//
	this->animationComponent->addAnimation(2, "RIGHT_ATTACK_BOXING_GLOVES", 5.f, 0, 2, 8, 2, 150, 150); // Une fois
	this->animationComponent->addAnimation(2, "RIGHT_ATTACK_SWORD", 7.f, 0, 4, 4, 4, 150, 150);			// Une fois
	this->animationComponent->addAnimation(2, "RIGHT_DEFEND_SHIELD", 6.f, 0, 6, 3, 6, 150, 150, true);	// Une fois et reste maintenu
	this->animationComponent->addAnimation(1, "RIGHT_HURT", 5.f, 0, 8, 1, 8, 150, 150);					// Une fois
	this->animationComponent->addAnimation(0, "RIGHT_DIE", 10.f, 0, 10, 7, 10, 150, 150);				// Une fois et reste maintenu

	this->animationComponent->addAnimation(4, "LEFT_IDLE", 10.f, 0, 1, 0, 1, 150, 150);
	this->animationComponent->addAnimation(3, "LEFT_WALK", 10.f, 0, 1, 3, 1, 150, 150);				   //
	this->animationComponent->addAnimation(2, "LEFT_ATTACK_BOXING_GLOVES", 5.f, 0, 3, 8, 3, 150, 150); // Une fois
	this->animationComponent->addAnimation(2, "LEFT_ATTACK_SWORD", 7.f, 0, 5, 4, 5, 150, 150);		   // Une fois
	this->animationComponent->addAnimation(2, "LEFT_DEFEND_SHIELD", 6.f, 0, 7, 3, 7, 150, 150, true);  // Une fois et reste maintenu
	this->animationComponent->addAnimation(1, "LEFT_HURT", 5.f, 0, 9, 1, 9, 150, 150);				   // Une fois
	this->animationComponent->addAnimation(0, "LEFT_DIE", 10.f, 0, 11, 7, 11, 150, 150);			   // Une fois et reste maintenu
}

Personage::Personage(bool isPlayer) :
	MovableGameObject("content/personage/personage.png", 0, 0), // REVIEW -
	m_isPlayer(isPlayer)
{
	init();
	initAnimations();
}

// Personage::Personage(std::string_view const& imageSpritePath, bool isPlayer) :
// 	GameObject(imageSpritePath),
// 	m_isPlayer(isPlayer)
// {
// 	init();
// }

// Personage::Personage(float posX, float posY, bool isPlayer) :
// 	GameObject(posX, posY),
// 	m_isPlayer(isPlayer)
// {
// 	init();
// }

Personage::~Personage()
{
	// delete m_collider; // Déjà fait au niveau du GameObject.
	m_window = nullptr;
}

//
bool Personage::isDied() const
{
	return m_healthLevel == 0; // REVIEW -
}

void Personage::show(sf::RenderTarget& target)
{
	m_window = &target; // REVIEW -
	// GameObject::show(window);
	target.draw(m_body);
}

void Personage::update()
{
	//
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
		// cout << "Collision de " << m_gameObjectName << " avec "
		// 	 << "collision.getGameObject()->getGameObjectName()" << endl;
	}
}

void Personage::updatePosition(Position& position)
{
	/*
	if (m_isPlayer)
	{
		// Gestion du déplacement du joueur.
		bool anyDirectionalKeyIsPressed(false);
		// TODO - Additionner les angles avant de l'associer à la vitesse; on enlevera le temps
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// m_speed.x = MOVE_SPEED * m_time;
			// m_speed2 = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
			m_speed = MyVector::createFromAngle(m_MOVE_SPEED * m_time, 0.f);
			anyDirectionalKeyIsPressed = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// m_speed.x = -MOVE_SPEED * m_time;
			// m_speed2 = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
			m_speed = MyVector::createFromAngle(m_MOVE_SPEED * m_time, 180.f);
			anyDirectionalKeyIsPressed = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// m_speed.y = -MOVE_SPEED * m_time;
			// m_speed2 = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
			m_speed = MyVector::createFromAngle(m_MOVE_SPEED * m_time, 270.f);
			anyDirectionalKeyIsPressed = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// m_speed.y = MOVE_SPEED * m_time;
			// m_speed2 = MyVector::createFromAngle(MOVE_SPEED * m_time, m_body.getRotation());
			m_speed = MyVector::createFromAngle(m_MOVE_SPEED * m_time, 90.f);
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

		// On applique des modification si la position à changé
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
	//*/

	m_position = position;
	// On replace le body
	m_body.setPosition(m_position.getX(), m_position.getY());
	cout << "Position du joueur " << m_gameObjectName << " : " << m_position << endl;
	// On replace la vue si c'est le joueur
	if (m_isPlayer)
		if (m_window != 0)
		{
			// cout << "On replace la vue" << endl;
			sf::View player_view(m_window->getView());
			player_view.setCenter(m_position.getX(), m_position.getY());
			m_window->setView(player_view);
		}
}

void Personage::move(MyVector& speed)
{
	Position p(getPosition().getX() + speed.x, getPosition().getY() + speed.y);
	updatePosition(p);
}
