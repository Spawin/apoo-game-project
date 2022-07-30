#if !defined(__ANIMATION_COMPONENT_HPP__)
	#define __ANIMATION_COMPONENT_HPP__

	#include "include/Animation.hpp"

class Animation;

class AnimationComponent
{
public:
	// Constructeurs/Destructeur
	AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);
	~AnimationComponent();

	// Fonctions/Méthodes
	const bool& isDone(const std::string key);
	/**
	 * @brief
	 *
	 * @param priority
	 * @param animation
	 * @param animationTimer
	 * @param start_x
	 * @param start_y
	 * @param end_x
	 * @param end_y
	 * @param width
	 * @param height
	 * @param fixLastFrame indique si l'animation une fois arrivée à la dernière frame ne dois pas recommencer de zéro (si bien sur c'est elle qui à la priorité)
	 */
	void addAnimation(int priority, const std::string animation, float animationTimer, int start_x, int start_y, int end_x, int end_y, int width, int height, bool fixLastFrame = false);
	/**
	 * @brief Vérifie si cette animation peut etre lancée
	 * (on va comparer les priorité)
	 * Retourne vrai si la dernière animation est finie ou si la nouvelle animation est prioritaire
	 *
	 * @param animationKey
	 * @param allowSimilar renvera true si c'est la même animation qui est en cours
	 * @return true
	 * @return false
	 */
	bool canPlay(const std::string& animationKey, bool allowSimilar = false);
	const bool& play(const std::string& animationKey, const float& deltatime);

private:
	// Variables
	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animations;
	Animation* lastAnimation;

	// Fonctions d'initialisation
	void initEmptyAnimations();
};

#endif // __ANIMATION_COMPONENT_HPP__
