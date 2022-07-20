#include "include/Player.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
Player::Player(Personage* personage) :
	m_personnage(personage)
{
}

Player::~Player()
{
}

// Fonctions/Méthodes
void Player::update(const float& deltaTime)
{
	std::cout << "Player " << deltaTime << std::endl;
	this->m_personnage->update();
}

void Player::render(sf::RenderTarget& target)
{
	m_personnage->show(target);
}