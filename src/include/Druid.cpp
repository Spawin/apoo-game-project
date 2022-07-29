#include "include/Druid.hpp"
using namespace std;

// Fonction static

// Fonctions d'initialisation
void Druid::init()
{
	// m_gameObjectName = "Druid";
	this->setGameObjectName("Druid");
	m_specialtyName = "Mana";
}

// Constructeurs/Destructeur
Druid::Druid()
{
	this->init();
}

Druid::~Druid()
{
}

// Fonctions/Méthodes
void Druid::simpleAttack(Personage& target)
{
	cout << "Attaque sur " << target.getGameObjectName() << endl;
}

void Druid::specialAttack(Personage& target)
{
	cout << "Attaque spéciale sur " << target.getGameObjectName() << endl;
}

// unsigned Druid::receiveHealthDamage(int value)
// {}

// unsigned Druid::receiveExpDamage(int value)
// {}

// unsigned Druid::receiveHealthCare(int value)
// {}

// unsigned Druid::receiveExpCare(int value)
// {}

// void Druid::receiveShieldboost(int value)
// {}
