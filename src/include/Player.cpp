#include "include/Player.hpp"
#include "include/Door.hpp"
#include "include/GameObject.hpp"
#include <string>

class GameObject;

// Fonction static

// Fonctions d'initialisation
void Player::initPlayerStats()
{
	this->playerStats.score = 0;
	this->playerStats.enemyKilled = 0;
}

// Constructeurs/Destructeur
Player::Player(Personage* personage) :
	personage(personage)
{
	// this->lastSideIsRight = true;
	this->personage->setLastAnimationSide(game::AnimationSide::RIGHT);
	this->attackSateInformations.attacking = false;

	this->resetHallChangeStateInformations();

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

void Player::manageActionToOtherPersonage()
{
	if (this->attackSateInformations.attacking && this->attackSateInformations.waitingForActionToOtherPersonageEnd <= 0)
	{
		// REVIEW - Fouiller les énemies qui sont dans le hall directement...
		for (auto&& value : Personage::getPersonages())
		{
			if (value.second->getGameObjectName().find("Enemy") != std::string::npos)
			{
				short& side = this->attackSateInformations.side;
				Item const* item = this->getFirstItemMatch(this->attackSateInformations.itemCategorie);

				std::cout << std::endl;
				std::cout << "Position du joueur " << this->personage->getGameObjectName() << (*this->personage->getPosition()) << std::endl;
				std::cout << "Position du joueur " << value.second->getGameObjectName() << (*value.second->getPosition()) << std::endl;
				std::cout << "Endroit de l'attaque : x=" << this->personage->getPosition()->getX() + side * item->getRangeOfAction() << " y=" << this->personage->getPosition()->getY() << std::endl;
				std::cout << "Distance entre les deux " << value.second->getPosition()->getDistanceWith(this->personage->getPosition()->getX() + side * item->getRangeOfAction(), this->personage->getPosition()->getY()) << std::endl;
				// Sur x on ajoute une valeur de décalage (négative pour gauche et positive pour droite) pour indiquer la zone d'action de l'item
				if (value.second->getPosition()->getDistanceWith(this->personage->getPosition()->getX() + side * item->getRangeOfAction(), this->personage->getPosition()->getY()) < item->getRangeOfAction())
				{
					// On gère l'attaque
					this->lastItemActionResult = value.second->receiveItemAction(item->getValue(), item->getCategorie());

					// Si l'énemi meurt après l'attaque
					if (this->lastItemActionResult.isDied)
					{
						this->playerStats.score += game::SCORE_ADD_AFTER_ENEMY_KILLED;
						this->playerStats.enemyKilled++;
					}

					// On supprime l'item de l'inventaire s'il est à usage unique
					if (item->isOneUse())
					{
						if (this->getPersonage()->removeItem(this->getFirstItemMatchNonConst(this->attackSateInformations.itemCategorie), this->personage->getInventoryItemType(item)))
						{
							// REVIEW -
						}
					}

					// On réitialise le résultat d'attaque
					this->resetLastItemActionResult();
				}
			}
		}

		// On réitnitialise les informations de l'attaque
		this->resetAttackSateInformations();
	}
}

void Player::manageActionWithDoors()
{
	if (this->hallChangeStateInformations.changeHall)
	{
		for (auto&& pDoor : Door::getDoors())
		{
			if (pDoor.second->getPosition()->getDistanceWith(this->personage->getPosition()->getX(), this->personage->getPosition()->getY()) < 50.f)
			{
				// REVIEW - Un signale visuel au niveau de la porte

				// Si la porte est une porte de téléportation, on vérifie si on a une clé de téléportation et on l'en lève
				if (pDoor.second->getGameObjectName().find("TeleportDoor") != std::string::npos)
				{
					if (!this->hallChangeStateInformations.haveTeleportKey)
					{
						this->resetHallChangeStateInformations();
						return;
					}
					else
					{
						if (this->getPersonage()->removeItem(this->getFirstItemMatchNonConst(game::ItemsCategories::TELEPORTKEY), game::inventory_items_types::TELEPORTKEY))
						{
							// TODO - On gère la téléportation -
							std::cout << "\n\n\tChangement de salle zvec téléportation\n\n";
						}
					}
				}
				else
				{
					// Porte simple
					std::cout << "\n\n\tChangement de salle\n\n";

					for (size_t i = 0; i < pDoor.second->getDoorHalls().size(); i++)
					{
						// Car pour les porte simple on a juste 2 salles
						if (this->personage->getActualHall() != pDoor.second->getDoorHalls()[i])
						{
							if (this->personage->getActualHall()->getIntRect().left == pDoor.second->getDoorHalls()[i]->getIntRect().left)
							{
								float upOrDwn = this->personage->getActualHall()->getIntRect().top < pDoor.second->getDoorHalls()[i]->getIntRect().top ? 1.f : -1.f;

								pDoor.second->getDoorHalls()[i]->addMovableGameObject(this->personage);
								this->personage->addToHall(pDoor.second->getDoorHalls()[i]);
								this->personage->getNonConstPosition()->setPosition(this->getPosition().x, this->getPosition().y + game::GAME_BLOCKS_WIDTH * upOrDwn);
							}
						}
						else
						{
							// On enlève le joueur de ce hall
							pDoor.second->getDoorHalls()[i]->removeMovableGameObject(this->personage);
						}
					}
				}

				// On arrète la boucle car on a trouvé la bonne porte
				break;
			}
		}
	}

	this->resetHallChangeStateInformations();
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

	// Pour le changement de salle
	if (!this->hallChangeStateInformations.changeHall)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			this->hallChangeStateInformations.changeHall = true;
			this->hallChangeStateInformations.haveTeleportKey = this->haveThisItem(game::ItemsCategories::TELEPORTKEY);

			this->manageActionWithDoors();
		}
	}

	// bool& isAttaking = this->attackSateInformations.attacking;
	if (!this->attackSateInformations.attacking)
	{
		//* VIAL
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		{
			// TODO - SE soigner!!!

			//* SOINS SANTE
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) && this->haveThisItem(game::ItemsCategories::VIAL_HEALTH))
			{
				this->attackSateInformations.attacking = true; //
				this->attackSateInformations.waitingForActionToOtherPersonageEnd = this->getFirstItemMatch(game::ItemsCategories::VIAL_HEALTH)->getWaitingTimeForAction();
				this->attackSateInformations.itemCategorie = game::ItemsCategories::VIAL_HEALTH;
				this->attackSateInformations.side = this->isLastAnimationSideRight() ? 1 : -1;
				this->manageActionToOtherPersonage(); //

				return;
			}
			//* SOINS EXP
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) && this->haveThisItem(game::ItemsCategories::VIAL_EXP))
			{
				this->attackSateInformations.attacking = true; //
				this->attackSateInformations.waitingForActionToOtherPersonageEnd = this->getFirstItemMatch(game::ItemsCategories::VIAL_EXP)->getWaitingTimeForAction();
				this->attackSateInformations.itemCategorie = game::ItemsCategories::VIAL_EXP;
				this->attackSateInformations.side = this->isLastAnimationSideRight() ? 1 : -1;
				this->manageActionToOtherPersonage(); //

				return;
			}
			//* DIMINUE SANTE
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)) && this->haveThisItem(game::ItemsCategories::VIAL_ATTACK_HEALTH))
			{
				this->attackSateInformations.attacking = true; //
				this->attackSateInformations.waitingForActionToOtherPersonageEnd = this->getFirstItemMatch(game::ItemsCategories::VIAL_ATTACK_HEALTH)->getWaitingTimeForAction();
				this->attackSateInformations.itemCategorie = game::ItemsCategories::VIAL_ATTACK_HEALTH;
				this->attackSateInformations.side = this->isLastAnimationSideRight() ? 1 : -1;
				this->manageActionToOtherPersonage(); //

				return;
			}
			//* DIMINUE EXP
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) && this->haveThisItem(game::ItemsCategories::VIAL_ATTACK_EXP))
			{
				this->attackSateInformations.attacking = true; //
				this->attackSateInformations.waitingForActionToOtherPersonageEnd = this->getFirstItemMatch(game::ItemsCategories::VIAL_ATTACK_EXP)->getWaitingTimeForAction();
				this->attackSateInformations.itemCategorie = game::ItemsCategories::VIAL_ATTACK_EXP;
				this->attackSateInformations.side = this->isLastAnimationSideRight() ? 1 : -1;
				this->manageActionToOtherPersonage(); //

				return;
			}
		}

		//* ATTACK_BOXING_GLOVES
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && this->haveThisItem(game::ItemsCategories::ATTACK_BODY_TO_BODY))
		{
			if (this->personage->getAnimationComponent()->canPlay("RIGHT_ATTACK_BOXING_GLOVES"))
			{
				this->attackSateInformations.attacking = true;
				this->attackSateInformations.waitingForActionToOtherPersonageEnd = this->getFirstItemMatch(game::ItemsCategories::ATTACK_BODY_TO_BODY)->getWaitingTimeForAction();
				this->attackSateInformations.itemCategorie = game::ItemsCategories::ATTACK_BODY_TO_BODY;
				this->attackSateInformations.side = this->isLastAnimationSideRight() ? 1 : -1;
				this->manageActionToOtherPersonage(); //

				std::string animationName = "ATTACK_BOXING_GLOVES";
				if (this->isLastAnimationSideRight())
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
				this->attackSateInformations.attacking = true;
				this->attackSateInformations.waitingForActionToOtherPersonageEnd = this->getFirstItemMatch(game::ItemsCategories::ATTACK_SEMI_DISTANCE)->getWaitingTimeForAction();
				this->attackSateInformations.itemCategorie = game::ItemsCategories::ATTACK_SEMI_DISTANCE;
				this->attackSateInformations.side = this->isLastAnimationSideRight() ? 1 : -1;
				this->manageActionToOtherPersonage(); //

				std::string animationName = "ATTACK_SWORD";
				// if (this->lastSideIsRight)
				if (this->isLastAnimationSideRight())
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
				this->attackSateInformations.attacking = true; // REVIEW - ET renommer en itemActionstateInformation
				this->attackSateInformations.waitingForActionToOtherPersonageEnd = this->getFirstItemMatch(game::ItemsCategories::DEFEND)->getWaitingTimeForAction();
				this->attackSateInformations.itemCategorie = game::ItemsCategories::DEFEND;
				this->attackSateInformations.side = this->isLastAnimationSideRight() ? 1 : -1;
				this->manageActionToOtherPersonage(); //

				std::string animationName = "DEFEND_SHIELD";
				// if (this->lastSideIsRight)
				if (this->isLastAnimationSideRight())
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

					// this->lastSideIsRight = false;
					this->personage->setLastAnimationSide(game::AnimationSide::LEFT);
				}
				else
				{
					// Vérifie que l'animation précedente de la marche est terminée
					if (this->personage->getAnimationComponent()->isDone("RIGHT_WALK") || !this->personage->getAnimationComponent()->isDone("LEFT_WALK"))
					{
						this->personage->getAnimationComponent()->play("RIGHT_WALK", deltaTime);
					}

					// this->lastSideIsRight = true;
					this->personage->setLastAnimationSide(game::AnimationSide::RIGHT);
				}

				speed.x *= deltaTime * game::PERSONAGE_MOVE_VELOCITY;
				speed.y *= deltaTime * game::PERSONAGE_MOVE_VELOCITY;
				this->personage->move(speed);
				return;
			}
		} // End => if (canWalk)
	}

	// Mouvement par défaut (souvent de faible priorité)
	// if (this->lastSideIsRight)
	if (this->isLastAnimationSideRight())
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

		this->manageActionWithDoors();
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

Item* Player::getFirstItemMatchNonConst(game::ItemsCategories const& categorie)
{
	return this->personage->getFirstItemMatchNonConst(categorie);
}

game::AnimationSide Player::getLastAnimationSide()
{
	return this->personage->getLastAnimationSide();
}

bool Player::isLastAnimationSideRight()
{
	return this->getLastAnimationSide() == game::AnimationSide::RIGHT;
}

void Player::resetLastItemActionResult()
{
	this->lastItemActionResult.healthDecrease = 0;
	this->lastItemActionResult.healthIncrease = 0;
	this->lastItemActionResult.experienceDecrease = 0;
	this->lastItemActionResult.experienceincrease = 0;
	this->lastItemActionResult.isDied = false;
}

void Player::resetAttackSateInformations()
{
	this->attackSateInformations.attacking = false;
	this->attackSateInformations.waitingForActionToOtherPersonageEnd = 0.0f;
	this->attackSateInformations.itemCategorie = game::ItemsCategories::NONE;
	this->attackSateInformations.side = 0;
}

void Player::resetHallChangeStateInformations()
{
	this->hallChangeStateInformations.changeHall = false;
	this->hallChangeStateInformations.haveTeleportKey = false;
}
