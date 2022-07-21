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
	float angle(0.f);

	// Gestion du déplacement du joueur.
	// TODO - Additionner les angles avant de l'associer à la vitesse; on enlevera le temps
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		angle += 0.f;
		speed += { game::PERSONAGE_MOVE_VELOCITY, 0.f };
		// speed += MyVector::createFromAngle(game::PERSONAGE_MOVE_VELOCITY, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		angle += 180.f;
		speed += { -game::PERSONAGE_MOVE_VELOCITY, 0.f };
		// speed += MyVector::createFromAngle(game::PERSONAGE_MOVE_VELOCITY, 180.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		angle += 270.f;
		speed += { 0.f, -game::PERSONAGE_MOVE_VELOCITY };
		// speed += MyVector::createFromAngle(game::PERSONAGE_MOVE_VELOCITY, 270.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		angle += 90.f;
		speed += { 0.f, game::PERSONAGE_MOVE_VELOCITY };
		// speed += MyVector::createFromAngle(game::PERSONAGE_MOVE_VELOCITY, 90.f);
	}

	// if(angle <=  90.f ) {

	// }

	//* On applique des modification si la position à changé
	// REVIEW - (ceci n'est pas encore fait) Ou si le centre de la vue est différent de la position du joueur
	// if ( m_position.getPosition() != m_body.getPosition())
	// || m_body.getPosition() != m_window->getView().getCenter()
	if (speed != sf::Vector2f(0.f, 0.f))
	{
		std::cout << "\t X" << speed.m_x << " Y" << speed.m_y << std::endl;

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

		speed.m_x *= deltaTime;
		speed.m_y *= deltaTime;
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