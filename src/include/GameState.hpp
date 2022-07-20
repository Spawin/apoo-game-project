#if !defined(__GAME_STATE_HPP__)
	#define __GAME_STATE_HPP__

	#include "State.hpp"

class GameState : public State
{

public:
	// Constructeurs/Destructeur
	GameState(StateData* stateData);
	virtual ~GameState();

	// Fonctions/Méthodes
	void endState() override;
	void updateInput(const float& deltaTime) override;
	void update(const float& deltaTime) override;
	void render(sf::RenderTarget* target = nullptr) override;

private:
	// Variables
	sf::View view;
	Player* player;

	// Fonctions d'initialisation
	void initPlayer();
};

#endif // __GAME_STATE_HPP__
