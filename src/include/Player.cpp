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
sf::Vector2f Player::getPosition() const
{
	return this->personage->getPosition().getPosition().toVector2f();
}

void Player::manageMove(const float& deltaTime)
{
	// On ne fait pas de mouvement quand on est mort...
	if (this->personage->isDied())
	{
		// REVIEW - Il faudrait animer ça mort jusqu'au bout
		return;
	}

	//* ATTACK_BOXING_GLOVES
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		if (this->personage->getAnimationComponent()->canPlay("RIGHT_ATTACK_BOXING_GLOVES"))
		{
			std::string animationName = "ATTACK_BOXING_GLOVES";
			if (this->lastSideIsRight)
			{
				animationName = "RIGHT_" + animationName;
			}
			else
			{
				animationName = "LEFT_" + animationName;
			}
			this->personage->getAnimationComponent()->play(animationName, deltaTime);
			return;
		}
	}
	//* ATTACK_SWORD
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (this->personage->getAnimationComponent()->canPlay("RIGHT_ATTACK_SWORD"))
		{
			std::string animationName = "ATTACK_SWORD";
			if (this->lastSideIsRight)
			{
				animationName = "RIGHT_" + animationName;
			}
			else
			{
				animationName = "LEFT_" + animationName;
			}
			this->personage->getAnimationComponent()->play(animationName, deltaTime);
			return;
		}
	}
	//* DEFEND_SHIELD
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (this->personage->getAnimationComponent()->canPlay("RIGHT_DEFEND_SHIELD"))
		{
			std::string animationName = "DEFEND_SHIELD";
			if (this->lastSideIsRight)
			{
				animationName = "RIGHT_" + animationName;
			}
			else
			{
				animationName = "LEFT_" + animationName;
			}
			this->personage->getAnimationComponent()->play(animationName, deltaTime);
			return;
		}
	}

	// Mouvement de déplacement: marche
	if (this->personage->getAnimationComponent()->canPlay("RIGHT_WALK", true) || this->personage->getAnimationComponent()->canPlay("LEFT_WALK", true))
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
			if (speed.x < 0.0f)
			{
				// Vérifie que l'animation précedente de la marche est terminée
				if (this->personage->getAnimationComponent()->isDone("RIGHT_WALK") || this->personage->getAnimationComponent()->isDone("LEFT_WALK"))
				{
					this->personage->getAnimationComponent()->play("LEFT_WALK", deltaTime);
				}

				this->lastSideIsRight = false;
			}
			else
			{
				// Vérifie que l'animation précedente de la marche est terminée
				if (this->personage->getAnimationComponent()->isDone("RIGHT_WALK") || this->personage->getAnimationComponent()->isDone("LEFT_WALK"))
				{
					this->personage->getAnimationComponent()->play("RIGHT_WALK", deltaTime);
				}

				this->lastSideIsRight = true;
			}

			speed.x *= deltaTime * game::PERSONAGE_MOVE_VELOCITY;
			speed.y *= deltaTime * game::PERSONAGE_MOVE_VELOCITY;
			this->personage->move(speed);
			return;
		}
	} // End => if (canWalk)

	// Mouvement par défaut (souvent de faible priorité)
	if (this->lastSideIsRight)
	{
		this->personage->getAnimationComponent()->play("RIGHT_IDLE", deltaTime);
	}
	else
	{
		this->personage->getAnimationComponent()->play("LEFT_IDLE", deltaTime);
	}
}

/*

void Player::updateAnimation(const float& deltaTime)
{
	//! A enlever. Juste pour les tests
	// HURT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		std::string animationName = "HURT";
		if (this->lastSideIsRight)
		{
			animationName = "RIGHT_" + animationName;
		}
		else
		{
			animationName = "LEFT_" + animationName;
		}
		this->personage->getAnimationComponent()->play(animationName, deltaTime);
	}
	// DIE
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		std::string animationName = "DIE";
		if (this->lastSideIsRight)
		{
			animationName = "RIGHT_" + animationName;
		}
		else
		{
			animationName = "LEFT_" + animationName;
		}
		this->personage->getAnimationComponent()->play(animationName, deltaTime);
	}
}
// */

void Player::update(const float& deltaTime)
{
	this->manageMove(deltaTime);

	this->personage->update();
}

void Player::render(sf::RenderTarget& target)
{
	personage->show(target);
}