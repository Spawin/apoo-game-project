#if !defined(__MOVABLE_GAME_OBJECT_HPP__)
	#define __MOVABLE_GAME_OBJECT_HPP__

	#include "include/GameObject.hpp"
	#include "include/AnimationComponent.hpp"

class MovableGameObject : public GameObject
{
public:
	// Constructeurs/Destructeur
	MovableGameObject(std::string_view const& imageSpritePath, float posX, float posY);
	~MovableGameObject();

	// Fonctions/Méthodes
	void createAnimationComponent(sf::Texture& texture);
	AnimationComponent* getAnimationComponent();

protected:
	// Variables
	AnimationComponent* animationComponent;

	// Fonctions d'initialisation
};

#endif // __MOVABLE_GAME_OBJECT_HPP__
