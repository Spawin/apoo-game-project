#include "include/Personage.hpp"
#include "include/MyVector.hpp"
#include "include/PolygonCollider.hpp"
#include "include/Rigidbody.hpp"

#include <iostream>
#include <string>

#include "include/GameMaster.hpp"
#include "include/Money.hpp"
#include "include/Shield.hpp"
#include "include/Sword.hpp"
#include "include/Vial.hpp"
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

	// On définit l'origine du sprite (c'est a partir de cette dernière qu'on calcul la position du joueur.)
	m_body.setOrigin(75.f, 115.f);

	// Initialisation de la position en temps que joueurs
	// REVIEW - Cela se fera après l'ajout dans une salle
	// if (m_isPlayer)
	// {
	// 	cout << "Placement du joueur sur le lieu de départ\n";

	// 	m_position->setPosition(game::GAME_BLOCKS_WIDTH * 4, game::GAME_BLOCKS_WIDTH * 78); // REVIEW -
	// 	// m_position = Position(game::GAME_BLOCKS_WIDTH * 4, game::GAME_BLOCKS_WIDTH * 4);
	// 	m_body.setPosition(m_position->getX(), m_position->getY());
	// }
	// else
	// {
	// 	// TODO - Sera un énémi donc on devra avoir une classe spéciale pour lui
	// 	m_position->setPosition(game::GAME_BLOCKS_WIDTH * 20, game::GAME_BLOCKS_WIDTH * 70); // REVIEW -
	// 	m_body.setPosition(m_position->getX(), m_position->getY());
	// }

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

void Personage::initEXPBar()
{
	this->expBar = new gui::ProgressBar(
		this->calculateProgressBarsPosition().x - 10.4f * 5.5f, this->calculateProgressBarsPosition().y + 5.6f * 5, 10.4f, 1.9f, sf::Color::Blue, 220, GameMaster::STATE_DATA()->graphicsSettings->resolution, &GameMaster::STATE_DATA()->defaultFont);
}

void Personage::initHPBar()
{
	this->hpBar = new gui::ProgressBar(
		this->calculateProgressBarsPosition().x - 10.4f * 5.5f, this->calculateProgressBarsPosition().y + 8.3f, 10.4f, 2.8f, sf::Color::Red, 180, GameMaster::STATE_DATA()->graphicsSettings->resolution, &GameMaster::STATE_DATA()->defaultFont);
}

void Personage::initBag()
{
	this->bag = new Bag();

	// Satrt Vials
	this->bag->addItem(new Vial(ItemsCategories::VIAL_HEALTH), game::inventory_items_types::VIAL);
	this->bag->addItem(new Vial(ItemsCategories::VIAL_EXP), game::inventory_items_types::VIAL);
	this->bag->addItem(new Vial(ItemsCategories::VIAL_ATTACK_HEALTH), game::inventory_items_types::VIAL);
	this->bag->addItem(new Vial(ItemsCategories::VIAL_ATTACK_EXP), game::inventory_items_types::VIAL);

	// Start Armoies
	this->bag->addItem(new Shield(), game::inventory_items_types::ARMORY);
	this->bag->addItem(new Sword(), game::inventory_items_types::ARMORY);

	// Start money "3"
	this->bag->addItem(new Money(), game::inventory_items_types::MONEY);
	this->bag->addItem(new Money(), game::inventory_items_types::MONEY);
	this->bag->addItem(new Money(), game::inventory_items_types::MONEY);
}

Personage::Personage(bool isPlayer) :
	MovableGameObject("content/personage/personage.png"), // REVIEW -
	m_isPlayer(isPlayer)
{
	this->init();
	this->initAnimations();
	this->initEXPBar();
	this->initHPBar();
	this->initBag();
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
	delete this->hpBar;
	delete this->expBar;
	delete this->bag;
}

//
sf::Vector2f Personage::calculateProgressBarsPosition()
{
	return sf::Vector2f(this->getPosition()->getPosition().x, this->getPosition()->getPosition().y - 150.f);
}

bool Personage::isDied() const
{
	return m_healthLevel == 0; // REVIEW -
}

void Personage::show(sf::RenderTarget& target)
{
	m_window = &target; // REVIEW -
	// GameObject::show(window);
	target.draw(m_body);

	this->renderEXPBar(target);
	this->renderHPBar(target);
}

void Personage::update()
{
	this->updateEXPBar();
	this->updateHPBar();

	this->bag->getInventory()->getGui()->update();
}

void Personage::updateMousePosWindow(sf::Vector2i mousePosWindow)
{
	this->bag->getInventory()->getGui()->updateMousePosWindow(mousePosWindow);
}

void Personage::setGameObjectName(string name)
{
	m_gameObjectName = name;
}

void Personage::onCollisionEnter(Collision const& collision) const
{
	collision.test(); // REVIEW
	if (m_isPlayer)
	{
		// cout << "Collision de " << m_gameObjectName << " avec "
		// 	 << "collision.getGameObject()->getGameObjectName()" << endl;
	}
}

void Personage::updatePosition(float posX, float posY)
{
	m_position->setPosition(posX, posY);
	// On replace le body
	m_body.setPosition(m_position->getPosition().toVector2f());

	// On déplace les progresses
	this->hpBar->setPosition(sf::Vector2f(this->calculateProgressBarsPosition().x - 10.4f * 5.5f, this->calculateProgressBarsPosition().y + 8.3f), GameMaster::STATE_DATA()->graphicsSettings->resolution);
	this->expBar->setPosition(sf::Vector2f(this->calculateProgressBarsPosition().x - 10.4f * 5.5f, this->calculateProgressBarsPosition().y + 5.6f * 5), GameMaster::STATE_DATA()->graphicsSettings->resolution);

	// On replace la vue si c'est le joueur
	if (m_isPlayer)
		if (m_window != 0)
		{
			// cout << "On replace la vue" << endl;
			sf::View player_view(m_window->getView());
			// player_view.setCenter(m_position.getX(), m_position.getY());
			player_view.setCenter(this->m_position->getPosition().toVector2f());
			m_window->setView(player_view);
		}

	cout << "Position du joueur " << m_gameObjectName << " : " << m_position << " => " << (*m_position) << endl;
}

void Personage::move(MyVector& speed)
{
	updatePosition(this->getPosition()->getX() + speed.x, this->getPosition()->getY() + speed.y);
}

void Personage::renderBagInventory(sf::RenderTarget& target)
{
	this->bag->renderInventory(target);
}

void Personage::updateEXPBar()
{
	this->expBar->update(this->m_specialityLevel, game::PERSONNAGE_MAX_SPECIALITY);
}

void Personage::updateHPBar()
{
	this->hpBar->update(this->m_healthLevel, game::PERSONNAGE_MAX_HEALTH);
}

void Personage::renderEXPBar(sf::RenderTarget& target)
{
	this->expBar->render(target);
}

void Personage::renderHPBar(sf::RenderTarget& target)
{
	this->hpBar->render(target);
}
