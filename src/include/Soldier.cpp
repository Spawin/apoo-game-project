#include "include/Soldier.hpp"

using namespace std;

void Soldier::init()
{
	m_specialtyName = "Rage";
}

Soldier::Soldier(bool isPlayer) :
	Personage(isPlayer)
{
	init();
}

Soldier::~Soldier()
{
}

// -----------------

void Soldier::simpleAttack(Personage& target)
{
	cout << "" << target.getHealthLevel();
}
void Soldier::specialAttack(Personage& target)
{
	cout << "" << target.getHealthLevel();
}

void Soldier::show(sf::RenderTarget& window)
{
	Personage::show(window);

	// NOTE -
	// Ici, on aura à présenter tout ce qui sera affiché.
	// On pouvait avoir plus sieur vue de l'utilisateur avec déjà les habits
	// Mais on peux faire le cas par cas et dessiner un truc par dessus.
	// Le seul soucis c'est qu'il faudrat tout bouger simultanément ou gérer cela directement dans la classe Mère.
}