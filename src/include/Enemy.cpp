#include "include/Enemy.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Enemy::Enemy(Personage* personage) :
	personage(personage)
{
	this->lastSideIsRight = true;

	this->personage->setGameObjectName("Enemy");
}

Enemy::~Enemy()
{
	delete this->personage;
}

// Fonctions/Méthodes
sf::Vector2f Enemy::getPosition() const
{
	return this->personage->getPosition()->getPosition().toVector2f();
}

Personage* Enemy::getPersonage()
{
	return this->personage;
}

void Enemy::manageMove(const float& deltaTime)
{
	this->personage->getAnimationComponent()->play("LEFT_IDLE", deltaTime);
	return; // TODO - Sera géré par une ia

	// On ne fait pas de mouvement quand on est mort...
	if (this->personage->isDied())
	{
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
			// Animation
			if (speed.x < 0.0f)
			{
				// Vérifie que l'animation précedente de la marche est terminée
				if (!this->personage->getAnimationComponent()->isDone("RIGHT_WALK") || this->personage->getAnimationComponent()->isDone("LEFT_WALK"))
				{
					this->personage->getAnimationComponent()->play("LEFT_WALK", deltaTime);
				}

				this->lastSideIsRight = false;
			}
			else
			{
				// Vérifie que l'animation précedente de la marche est terminée
				if (this->personage->getAnimationComponent()->isDone("RIGHT_WALK") || !this->personage->getAnimationComponent()->isDone("LEFT_WALK"))
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

// void Enemy::updateMousePosWindow(sf::Vector2i mousePosWindow)
// {
// 	this->personage->updateMousePosWindow(mousePosWindow);
// }

void Enemy::update(const float& deltaTime)
{
	this->manageMove(deltaTime);

	this->personage->update();
}

void Enemy::render(sf::RenderTarget& target)
{
	personage->show(target);
}
