#include "include/Vial.hpp"

// Fonction static

// Fonctions d'initialisation

// Constructeurs/Destructeur
// Vial::Vial(VialCategorie vialCategoriel, std::string_view const& imageSpritePath):
Vial::Vial(/*std::string_view const& imageSpritePath, */ ItemsCategories categorie) :
	Item("content/gameObjects/health_vial.png", categorie)
{
	std::string_view texturePath("content/gameObjects/health_vial.png");
	switch (categorie)
	{
		case ItemsCategories::VIAL_EXP:
			m_gameObjectName = "Vial";

			texturePath = "content/gameObjects/exp_vial.png";
			break;
		case ItemsCategories::VIAL_HEALTH:
			m_gameObjectName = "Vial";

			texturePath = "content/gameObjects/health_vial.png";
			break;
		case ItemsCategories::VIAL_ATTACK_EXP:
			m_gameObjectName = "Vial";

			texturePath = "content/gameObjects/poison_vial.png";
			break;
		case ItemsCategories::VIAL_ATTACK_HEALTH:
			m_gameObjectName = "Vial";

			texturePath = "content/gameObjects/poison_vial.png";
			break;

		default:
			break;
	}

	if (!m_texture.loadFromFile(texturePath.data())) // TODO  - A changer; ces paramètre doivent venir du constructeur
	// if (!m_texture.create(200, 200))
	{
		std::cerr << "Image < " << texturePath << " > introuvable" << std::endl;
	}

	m_body.setTexture(m_texture);

	// m_gameObjectName = "Vial"; // REVIEW -
	m_body.setScale((float)game::INVENTORY_BLOCK_WIDTH / (float)m_texture.getSize().x, (float)game::INVENTORY_BLOCK_WIDTH / (float)m_texture.getSize().y);
}

Vial::~Vial()
{
}

// Fonctions/Méthodes
void Vial::onCollisionEnter(Collision const& collision) const
{
	collision.test(); // REVIEW -
}

void Vial::update()
{}

void Vial::useOn(Personage& personage)
{
	switch (this->categorie)
	{
		case ItemsCategories::VIAL_EXP:
			personage.receiveExpCare(this->value);
			break;
		case ItemsCategories::VIAL_HEALTH:
			personage.receiveHealthCare(this->value);
			break;
		case ItemsCategories::VIAL_ATTACK_EXP:
			personage.receiveExpDamage(this->value);
			break;
		case ItemsCategories::VIAL_ATTACK_HEALTH:
			personage.receiveHealthDamage(this->value);
			break;

		default:
			break;
	}
}

void Vial::updatePosition(float posX, float posY)
{
	m_position->setPosition(posX, posY);
	// On replace le body
	m_body.setPosition(m_position->getPosition().toVector2f());

	std::cout << "Position du " << m_gameObjectName << " : " << m_position << " => " << (*m_position) << std::endl;
}
