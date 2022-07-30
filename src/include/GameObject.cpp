#include "include/GameObject.hpp"
#include "include/consts.hpp"
#include <iostream>
#include <string>

float GameObject::m_time = 0.f;
int GameObject::m_count = 0;

// Initialisation à vide de la liste de game objects
GameObject::GameObjectMap GameObject::gameObjects = [] {
	GameObjectMap ret;
	return ret;
}();

void GameObject::incrementCount()
{
	GameObject::m_count++;
}

void GameObject::init()
{
	// On incrémente le compteur
	GameObject::incrementCount();

	GameObject::gameObjects.insert({ std::to_string(this->getGameObjectId()), this });
}

// GameObject::GameObject()
// {
// 	// initialisation
// 	init();
// }

// GameObject::GameObject(std::string_view const& imageSpritePath)
// {
// 	// initialisation
// 	init();
// 		if (!m_texture.loadFromFile(imageSpritePath.data()))
// 		{
// 			std::cerr << "Image < " << imageSpritePath << " > introuvable" << std::endl;
// 		}
// 		m_body.setTexture(m_texture);
// }

GameObject::GameObject(std::string_view const& imageSpritePath)
{
	// initialisation
	init();

	if (!m_texture.loadFromFile(imageSpritePath.data())) // TODO  - A changer; ces paramètre doivent venir du constructeur
	// if (!m_texture.create(200, 200))
	{
		std::cerr << "Image < " << imageSpritePath << " > introuvable" << std::endl;
	}

	m_body.setTexture(m_texture);
}

GameObject::~GameObject()
{
	delete m_collider;
	m_collider = nullptr;
	delete m_rigidbody;
	m_rigidbody = nullptr;

	Collider::removeObjects(this->m_id);

	// if(GameObject::)
	GameObject::gameObjects.erase(std::to_string(this->getGameObjectId()));
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

const Position* GameObject::getPosition() const
{
	return m_position;
}

Position* GameObject::getNonConstPosition()
{
	return m_position;
}

std::string GameObject::getGameObjectName() const
{
	return m_gameObjectName;
}

void GameObject::setGameObjectName(std::string name)
{
	m_gameObjectName = name + "_" + m_gameObjectName;
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
