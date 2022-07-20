#include "include/GameObject.hpp"
#include "include/consts.hpp"
#include <iostream>

float GameObject::m_time = 0.f;
int GameObject::m_count = 0;

void GameObject::incrementCount()
{
	GameObject::m_count++;
}

void GameObject::init()
{
	// On incrémente le compteur
	GameObject::incrementCount();

	m_body.setColor(sf::Color::White);

	sf::Texture texture;
	if (!texture.create(PERSONNAGE_WIDTH, PERSONNAGE_WIDTH))
	{
		std::cerr << "Erreur lors de la mise en place d'une texture vide (GameObject)" << std::endl;
	}
	// REVIEW -
	sf::Uint8* pixels = new sf::Uint8[PERSONNAGE_WIDTH * PERSONNAGE_WIDTH * 4]; // * 4 car les pixels ont 4 composantes (RGBA)
	texture.update(pixels);
	m_body.setTexture(texture);

	// REVIEW -
	// On définit son centre de "gravité"
	// m_body.setOrigin(m_body.getLocalBounds().width / 2, m_body.getLocalBounds().height / 2);
	m_body.setOrigin(PERSONNAGE_WIDTH / 2, PERSONNAGE_WIDTH / 2);

	m_position = Position(32 * 4, 32 * 70); // REVIEW -
	m_body.setPosition(m_position.getX(), m_position.getY());
}

GameObject::GameObject()
{
	// initialisation
	init();
}

GameObject::GameObject(std::string_view const& imageSpritePath)
{
	// initialisation
	init();

	if (!imageSpritePath.empty())
	{

		if (!m_texture.loadFromFile(imageSpritePath.data()))
		{
			std::cerr << "Image < " << imageSpritePath << " > introuvable" << std::endl;
		}
		m_body.setTexture(m_texture);
	}
}

GameObject::GameObject(float posX, float posY, std::string_view const& imageSpritePath)
{
	// initialisation
	init();
	if (!imageSpritePath.empty())
	{
		if (!m_texture.loadFromFile(imageSpritePath.data()))
		{
			std::cerr << "Image < " << imageSpritePath << " > introuvable" << std::endl;
		}

		m_body.setTexture(m_texture);
	}

	m_position = Position(posX, posY);
	m_body.setPosition(m_position.getX(), m_position.getY());
}

GameObject::~GameObject()
{
	delete m_collider;
	m_collider = nullptr;
	delete m_rigidbody;
	m_rigidbody = nullptr;
}

void GameObject::show(sf::RenderTarget& window)
{
	window.draw(m_body);
}

// void GameObject::update()
// {}

void GameObject::SetTime(float t)
{
	m_time = t;
}

int GameObject::getGameObjectId() const
{
	return m_id;
}

Position const& GameObject::getPosition() const
{
	return m_position;
}

std::string GameObject::getGameObjectName() const
{
	return m_gameObjectName;
}

// void GameObject::onCollisionEnter(Collision const& collision) const
// {
// 	collision.test(); // REVIEW
// 					  // std::cout << "une collision avec" << collision.getGameObject;
// }

sf::Sprite const& GameObject::getSprite() const
{
	return m_body;
}

// void GameObject::updatePosition(Position m_position)
// {}

bool GameObject::isArigidBody() const
{
	return m_rigidbody != nullptr;
}

void GameObject::fromColliderToRigidBody() const
{
	if (isArigidBody())
	{
		m_rigidbody->onAnotherRigidBodyDetection();
	}
}

Collider const& GameObject::getCollider() const
{
	return *m_collider;
}

// void GameObject::sendEvent(sf::Event const& event)
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
