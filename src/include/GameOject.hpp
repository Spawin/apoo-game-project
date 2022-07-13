#ifndef __GameOject_HPP__
#define __GameOject_HPP__

#include "include/MyVector.hpp"
#include "include/Position.hpp"

class GameOject
{
public:
	GameOject();
	/**
	 * @brief Construct a new Game Oject object
	 *
	 * @param imageSpritePath le chemin de l'image de l'objet
	 */
	GameOject(std::string_view const& imageSpritePath);

	virtual ~GameOject();

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

protected:
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
};

#endif // __GameOject_HPP__
