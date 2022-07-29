#ifndef __GameObject_HPP__
#define __GameObject_HPP__

#include "include/Collider.hpp"
#include "include/Collision.hpp"
#include "include/MyVector.hpp"
#include "include/Position.hpp"
#include "include/Rigidbody.hpp"
#include <string>

class Collision;
class Collider;
class Rigidbody;
class Position;

class GameObject
{
public:
	// explicit GameObject();
	// /**
	//  * @brief Construct a new Game Oject object
	//  *
	//  * @param imageSpritePath le chemin de l'image de l'objet
	//  */
	// explicit GameObject(std::string_view const& imageSpritePath);

	/**
	 * @brief Construct a new Game Object object
	 *
	 * @param posX la position x de l'objet
	 * @param posY la position y de l'objet
	 */
	explicit GameObject(std::string_view const& imageSpritePath); // REVIEW -

	virtual ~GameObject();

	/**
	 * @brief Pour dessiner l'élement dans la fenêtre.
	 *
	 * @param window
	 */
	virtual void show(sf::RenderTarget& window);
	//Sera appelé à chaque frame...
	// virtual void update() = 0;
	virtual void update() = 0;

	/**
	 * @brief Set the Time object
	 *
	 * @param t
	 */
	static void SetTime(float t);

	// Retourne l'id du game object
	int getGameObjectId() const;

	const Position* getPosition() const;
	Position* getNonConstPosition();

	std::string getGameObjectName() const;
	void setGameObjectName(std::string name);

	/**
	 * @brief émit quand il entre en contacte avec un autre élément
	 *
	 * @param collision
	 */
	virtual void onCollisionEnter(Collision const& collision) const = 0;

	sf::Sprite const& getSprite() const;

	/**
	 * @brief Vérifie si 'objet est un corps rigid.
	 * (On ne peut pas passer à travers un corps rigid)
	 *
	 * @return true
	 * @return false
	 */
	bool isArigidBody() const;

	/**
	 * @brief Quand un collider détect une collision,
	 * il envoi l'information au rigidBody
	 *
	 */
	void fromColliderToRigidBody() const;

	Collider const& getCollider() const;

protected:
	/**
	 * @brief Pour initialiser les valeur par défaut du GameObject
	 *
	 */
	void init();
	virtual void initPosition(float posX, float posY) = 0;
	// identifiant unique du game Object
	const int m_id { GameObject::m_count + 1 };
	// Nom du game object
	std::string m_gameObjectName { "GameObject" };
	// le nombre de gameObject créé au total (compte aussi ceux qui sont déjà détruit)
	static int m_count;
	// Incrémente le compteur
	static void incrementCount();
	// REVIEW -
	sf::Texture m_texture {};
	// Sprite du corps de l'objet
	sf::Sprite m_body {};
	// Représente la position de l'objet
	Position* m_position;
	// Vitesse de déplacement actuelle
	MyVector m_speed { 0.f, 0.f };

	// Temps pour calculer la vitesse de déplacement
	static float m_time;

	friend class Rigidbody; // REVIEW -

	// sf::Vector2f m_speed2 { 0.f, 0.f };

	/**
	 * REVIEW
	 * @brief Permet de mettre à jour la position actuelle.
	 */
	// virtual void updatePosition() = 0;
	// virtual void updatePosition(Position& position) = 0;

	Collider* m_collider { nullptr };
	Rigidbody* m_rigidbody { nullptr };

	// int m_width { 100 };
	// int m_height { 100 };
};

#endif // __GameObject_HPP__
