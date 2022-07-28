#include "include/Worker.hpp"

using namespace std;

// Fonction static

// Fonctions d'initialisation
void Worker::init()
{
	m_gameObjectName = "Worker";
	m_specialtyName = "Velocity"; // REVIEW -
}

// Constructeurs/Destructeur
Worker::Worker()
{
	this->init();
}

Worker::~Worker()
{
}

// Fonctions/Méthodes
void Worker::simpleAttack(Personage& target)
{
	cout << "Attaque sur " << target.getGameObjectName() << endl;
}

void Worker::specialAttack(Personage& target)
{
	cout << "Attaque spéciale sur " << target.getGameObjectName() << endl;
}

// unsigned Worker::receiveHealthDamage(int value)
// {}

// unsigned Worker::receiveExpDamage(int value)
// {}

// unsigned Worker::receiveHealthCare(int value)
// {}

// unsigned Worker::receiveExpCare(int value)
// {}

// void Worker::receiveShieldboost(int value)
// {}
