#if !defined(__GAME_STATE_HPP__)
	#define __GAME_STATE_HPP__

	#include "State.hpp"

class GameState : public State
{

public:
	// Constructeurs/Destructeur
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	// Fonctions/Méthodes
	void endState() override;
	void updateKeyBinds(const float& deltaTime) override;
	void update(const float& deltaTime) override;
	void render(sf::RenderTarget* target = nullptr) override;

private:
	// Variables

	// Fonctions d'initialisation
};

#endif // __GAME_STATE_HPP__
