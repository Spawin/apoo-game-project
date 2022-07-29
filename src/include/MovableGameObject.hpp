#if !defined(__MOVABLE_GAME_OBJECT_HPP__)
	#define __MOVABLE_GAME_OBJECT_HPP__

	#include "include/GameObject.hpp"
	#include "include/AnimationComponent.hpp"
	#include "include/Hall.hpp"
	#include "include/Position.hpp"
	#include "include/MyVector.hpp"
	#include "include/Collision.hpp"

class Collision;
class Hall;
class Position;
class GameObject;

class MovableGameObject : public GameObject
{
public:
	// Constructeurs/Destructeur
	MovableGameObject(std::string_view const& imageSpritePath);
	~MovableGameObject();

	// Fonctions/Méthodes
	virtual void move(MyVector& speed) = 0;
	AnimationComponent* getAnimationComponent();
	/**
	 * @brief Déplacer un objet vers une salle
	 * est virtuel pour permettre de récrire la fonction et
	 * spécifier peut être des conditions de déplacement.
	 * NOTE - Cet déplacement ne concerne pas le chagement des cordonnes mais juste l'éta d'appartenance. Néanmoins c'est à partir d'elle qu'on informe l'object des nouvelles limites de mouvement.
	 *
	 * @param hall
	 * @return true Si le déplacement s'est effectué avec succès
	 * @return false Si le déplacement n'a pas eu lieu
	 */
	virtual bool addToHall(Hall* hall); // REVIEW - on va informer le hall de l'ajout par ici ou soit on ajout un const
	/**
	 * @brief Get the Actual Hall object
	 *
	 * @return const Hall*
	 */
	virtual const Hall* getActualHall() const;

	/**
	 * @brief Pour dessiner l'élement dans la fenêtre.
	 *
	 * @param window
	 */
	virtual void show(sf::RenderTarget& window);
	/**
	 * @brief émit quand il entre en contacte avec un autre élément
	 *
	 * @param collision
	 */
	virtual void onCollisionEnter(Collision const& collision) const = 0;
	virtual void update() = 0;

protected:
	// Variables
	AnimationComponent* animationComponent;
	void createAnimationComponent(sf::Texture& texture);
	// Represente la salle dans laquelle se trouve actuellement le joueur
	//! Ce pointeur ne doit pas être supprimé à ce niveau
	const Hall* hall;

	// Fonctions d'initialisation
	virtual void initPosition(float posX, float posY) override;
	/**
	 * @brief Initialiser animationComponent et les animations
	 *
	 */
	virtual void initAnimations() = 0;

	// Fonctions
	/**
	 * @brief Met à jour les nouvelle limite de déplacement.
	 *
	 * @param hall
	 */
	virtual void setPositionMovementLimit(const Hall* hall);

	/**
	 * @brief Permet de mettre à jour la position actuelle.
	 *
	 */
	virtual void updatePosition(float posX, float posY) = 0;
};

#endif // __MOVABLE_GAME_OBJECT_HPP__
