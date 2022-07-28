#include "include/Religious.hpp"

using namespace std;

// Fonction static

// Fonctions d'initialisation
void Religious::init()
{
	m_gameObjectName = "Religious";
	m_specialtyName = "Blessing";
}

// Constructeurs/Destructeur
Religious::Religious()
{
	this->init();
}

Religious::~Religious()
{
}

// Fonctions/Méthodes
void Religious::simpleAttack(Personage& target)
{
	cout << "Attaque sur " << target.getGameObjectName() << endl;
}

void Religious::specialAttack(Personage& target)
{
	cout << "Attaque spéciale sur " << target.getGameObjectName() << endl;
}

// unsigned Religious::receiveHealthDamage(int value)
// {}

// unsigned Religious::receiveExpDamage(int value)
// {}

// unsigned Religious::receiveHealthCare(int value)
// {}

// unsigned Religious::receiveExpCare(int value)
// {}

// void Religious::receiveShieldboost(int value)
// {}
