#include "include/Player.hpp"
#include "include/GameObject.hpp"
#include "include/Item.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Player::Player(Personage* personage) :
	personage(personage)
{
	this->lastSideIsRight = true;
	this->attackSateInformations.attacking = false;

	this->personage->setGameObjectName("Player");
}

Player::~Player()
{
	delete this->personage;
}

// Fonctions/Méthodes
sf::Vector2f Player::getPosition() const
{
	return this->personage->getPosition()->getPosition().toVector2f();
}

Personage* Player::getPersonage()
{
	return this->personage;
}

void Player::manageActionToOtherPersonage(/*game::ItemsCategories categorie*/)
{
	if (this->attackSateInformations.attacking && this->attackSateInformations.waitingForActionToOtherPersonageEnd <= 0)
	{
		// REVIEW - Fouiller les énemies qui sont dans le hall directement...
		for (auto&& value : Personage::getPersonages())
		{
			if (value.second->getGameObjectName().find("Enemy") != std::string::npos)
			{
				short& side = this->attackSateInformations.side;
				Item const* item = this->getFirstItemMatch(game::ItemsCategories::ATTACK_BODY_TO_BODY);

				std::cout << std::endl;
				std::cout << "Position du joueur " << this->personage->getGameObjectName() << (*this->personage->getPosition()) << std::endl;
				std::cout << "Position du joueur " << value.second->getGameObjectName() << (*value.second->getPosition()) << std::endl;
				std::cout << "Endroit de l'attaque : x=" << this->personage->getPosition()->getX() + side * item->getRangeOfAction() << " y=" << this->personage->getPosition()->getY() << std::endl;
				std::cout << "Distance entre les deux " << value.second->getPosition()->getDistanceWith(this->personage->getPosition()->getX() + side * item->getRangeOfAction(), this->personage->getPosition()->getY()) << std::endl;
				// Sur x on ajoute une valeur de décalage (négative pour gauche et positive pour droite) pour indiquer la zone d'action de l'item
				if (value.second->getPosition()->getDistanceWith(this->personage->getPosition()->getX() + side * item->getRangeOfAction(), this->personage->getPosition()->getY()) < item->getRangeOfAction())
				{
					// On gère l'attaque
					std::cout << "On le touche mal mal\n";
					value.second->receiveItemAction(item->getValue(), item->getCategorie());
				}
			}
		}

		this->attackSateInformations.attacking = false;
		this->attackSateInformations.waitingForActionToOtherPersonageEnd = 0.0f;
		this->attackSateInformations.itemCategorie = game::ItemsCategories::NONE;
		this->attackSateInformations.side = 0;
	}
}

void Player::manageMove(const float& deltaTime)
{
	// std::cout << "le deltatime " << deltaTime << std::endl;
	// On ne fait pas de mouvement quand on est mort...
	if (this->personage->isDied())
	{
		// REVIEW - Il faudrait animer ça mort jusqu'au bout
		return;
	}

	// bool& isAttaking = this->attackSateInformations.attacking;
	if (!this->attackSateInformations.attacking)
	{
		//* ATTACK_BOXING_GLOVES
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && this->haveThisItem(game::ItemsCategories::ATTACK_BODY_TO_BODY))
		{
			if (this->personage->getAnimationComponent()->canPlay("RIGHT_ATTACK_BOXING_GLOVES"))
			{
				this->attackSateInformations.attacking = true;
				this->attackSateInformations.waitingForActionToOtherPersonageEnd = this->getFirstItemMatch(game::ItemsCategories::ATTACK_BODY_TO_BODY)->getWaitingTimeForAction();
				this->attackSateInformations.itemCategorie = game::ItemsCategories::ATTACK_BODY_TO_BODY;
				this->attackSateInformations.side = this->lastSideIsRight ? 1 : -1;
				this->manageActionToOtherPersonage(); //

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->haveThisItem(game::ItemsCategories::ATTACK_SEMI_DISTANCE))
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->haveThisItem(game::ItemsCategories::DEFEND))
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
	}

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

void Player::updateMousePosWindow(sf::Vector2i mousePosWindow)
{
	this->personage->updateMousePosWindow(mousePosWindow);
}

void Player::update(const float& deltaTime)
{
	if (this->attackSateInformations.attacking)
	{
		// On met à jour le décompte pour l'attaque
		this->attackSateInformations.waitingForActionToOtherPersonageEnd -= deltaTime;

		this->manageActionToOtherPersonage();
	}

	this->manageMove(deltaTime);

	this->personage->update();
}

void Player::render(sf::RenderTarget& target)
{
	personage->show(target);
}

bool Player::haveThisItem(game::ItemsCategories const& categorie) const
{
	return this->personage->haveThisItem(categorie);
}

Item const* Player::getFirstItemMatch(game::ItemsCategories const& categorie) const
{
	return this->personage->getFirstItemMatch(categorie);
}
