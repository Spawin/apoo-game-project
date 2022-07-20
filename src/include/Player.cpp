#include "include/Player.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Player::Player(Personage* personage) :
	personage(personage)
{
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
		speed += MyVector::createFromAngle(game::PERSONAGE_MOVE_VELOCITY, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		speed += MyVector::createFromAngle(game::PERSONAGE_MOVE_VELOCITY, 180.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		speed += MyVector::createFromAngle(game::PERSONAGE_MOVE_VELOCITY, 270.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		speed += MyVector::createFromAngle(game::PERSONAGE_MOVE_VELOCITY, 90.f);
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
	if (speed != sf::Vector2f(0.f, 0.f))
	{
		speed.m_x *= deltaTime;
		speed.m_y *= deltaTime;
		this->personage->move(speed);
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