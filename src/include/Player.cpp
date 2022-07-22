#include "include/Player.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Player::Player(Personage* personage) :
	personage(personage)
{
	this->lastSideIsRight = true;
}

Player::~Player()
{
}

// Fonctions/Méthodes
void Player::manageMove(const float& deltaTime)
{
	MyVector speed { 0.f, 0.f };

	// Gestion du déplacement du joueur.
	// TODO - Additionner les angles avant de l'associer à la vitesse; on enlevera le temps
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		speed += { 1.f, 0.f };
		// speed += MyVector::createFromAngle(game::PERSONAGE_MOVE_VELOCITY, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		speed += { -1.f, 0.f };
		// speed += MyVector::createFromAngle(game::PERSONAGE_MOVE_VELOCITY, 180.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		speed += { 0.f, -1.f };
		// speed += MyVector::createFromAngle(game::PERSONAGE_MOVE_VELOCITY, 270.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		speed += { 0.f, 1.f };
		// speed += MyVector::createFromAngle(game::PERSONAGE_MOVE_VELOCITY, 90.f);
	}

	//* On applique des modification si la vitesse à changé
	if (speed != sf::Vector2f(0.f, 0.f))
	{
		// std::cout << "\t X" << speed.m_x << " Y" << speed.m_y << std::endl;

		// Animation
		if (speed.m_x < 0.0f)
		{
			this->personage->getAnimationComponent()->play("LEFT_WALK", deltaTime);

			this->lastSideIsRight = false;
		}
		else
		{
			this->personage->getAnimationComponent()->play("RIGHT_WALK", deltaTime);

			this->lastSideIsRight = true;
		}

		speed.m_x *= deltaTime * game::PERSONAGE_MOVE_VELOCITY;
		speed.m_y *= deltaTime * game::PERSONAGE_MOVE_VELOCITY;
		this->personage->move(speed);
	}
	else
	{
		if (this->lastSideIsRight)
		{
			this->personage->getAnimationComponent()->play("RIGHT_IDLE", deltaTime);
		}
		else
		{
			this->personage->getAnimationComponent()->play("LEFT_IDLE", deltaTime);
		}
	}
}

void Player::update(const float& deltaTime)
{
	this->manageMove(deltaTime);

	this->personage->update();
}

void Player::render(sf::RenderTarget& target)
{
	personage->show(target);
}