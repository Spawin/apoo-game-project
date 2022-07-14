#ifndef __GameObject_HPP__
#define __GameObject_HPP__

#include "include/Collider.hpp"
#include "include/Collision.hpp"
#include "include/MyVector.hpp"
#include "include/Position.hpp"

class Collider;

class GameObject
{
public:
	GameObject();
	/**
	 * @brief Construct a new Game Oject object
	 *
	 * @param imageSpritePath le chemin de l'image de l'objet
	 */
	GameObject(std::string_view const& imageSpritePath);

	virtual ~GameObject();

	/**
	 * @brief Pour dessiner l'élement dans la fenêtre.
	 *
	 * @param window
	 */
	virtual void show(sf::RenderWindow& window) const;
	//Sera appelé à chaque frame...
	virtual void update() = 0;
	/**
	 * ! Depracted
	 *
	 * @brief Reçois l'évenement actuel
	 *
	 * @param event
	 */
	// void sendEvent(sf::Event const& event);

	/**
	 * @brief Set the Time object
	 *
	 * @param t
	 */
	inline static void SetTime(float t)
	{
		m_time = t;
	};
	// Retourne l'id du game object
	int getGameObjectId() const;

	inline const Position* getPosition()
	{
		return &m_position;
	};

	inline std::string getGameObjectName()
	{
		return m_gameObjectName;
	}

	/**
	 * @brief émit quand il entre en contacte avec un autre élément
	 *
	 * @param collider
	 */
	void
	onCollisionEnter(Collision const& Collision);

protected:
	// identifiant unique du game Object
	const int m_id { GameObject::m_count + 1 };
	// Nom du game object
	std::string m_gameObjectName { "" };
	// le nombre de gameObject créé au total (compte aussi ceux qui sont déjà détruit)
	static int m_count;
	// Incrémente le compteur
	inline static void incrementCount()
	{
		m_count++;
	}
	// REVIEW -
	sf::Texture m_texture {};
	// Le corps de l'objet
	sf::Sprite m_body {};
	// Représente la position de l'objet
	Position m_position {};
	// Vitesse de déplacement actuelle
	MyVector m_speed { 0.f, 0.f };

	// Temps pour calculer la vitesse de déplacement
	static float m_time;

	// sf::Vector2f m_speed2 { 0.f, 0.f };

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 * Cette position sera déterminé par l'évenement reçu au préalable.
	 * Aussi il s'agit dans ce cas d'une accélération uniforme.
	 */
	virtual void updatePosition() = 0;

	Collider* m_collider;
	int m_width { 100 };
	int m_height { 100 };
};

#endif // __GameObject_HPP__
