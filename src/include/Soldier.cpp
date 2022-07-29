#include "include/Soldier.hpp"

using namespace std;

void Soldier::init()
{
	// m_gameObjectName = "";
	this->setGameObjectName("Soldier");
	m_specialtyName = "Rage";
}

Soldier::Soldier(bool isPlayer) :
	Personage(isPlayer)
{
	this->init();
}

Soldier::~Soldier()
{
}

// -----------------

void Soldier::simpleAttack(Personage& target)
{
	cout << "Attaque sur " << target.getGameObjectName() << endl;
}
void Soldier::specialAttack(Personage& target)
{
	cout << "Attaque spéciale sur " << target.getGameObjectName() << endl;
}

// void Soldier::show(sf::RenderTarget& window)
// {
// 	Personage::show(window);

// 	// NOTE -
// 	// Ici, on aura à présenter tout ce qui sera affiché.
// 	// On pouvait avoir plus sieur vue de l'utilisateur avec déjà les habits
// 	// Mais on peux faire le cas par cas et dessiner un truc par dessus.
// 	// Le seul soucis c'est qu'il faudrat tout bouger simultanément ou gérer cela directement dans la classe Mère.
// }

// unsigned Soldier::receiveHealthDamage(int value)
// {}

// unsigned Soldier::receiveExpDamage(int value)
// {}

// unsigned Soldier::receiveHealthCare(int value)
// {}

// unsigned Soldier::receiveExpCare(int value)
// {}

// void Soldier::receiveShieldboost(int value)
// {}
