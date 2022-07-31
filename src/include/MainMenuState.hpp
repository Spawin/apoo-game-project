#if !defined(__MAIN_MENU_STATE_HPP__)
	#define __MAIN_MENU_STATE_HPP__

	#include "include/State.hpp"
	#include "include/Gui.hpp"

class State;
namespace gui
{
class Button;
} // namespace gui

class MainMenuState : public State
{
public:
	// Constructeurs/Destructeur
	MainMenuState(StateData* stateData);
	~MainMenuState();

	// Fonctions/Méthodes
	// void endState() override;
	virtual void updateSFMLEvents(const sf::Event& sfEvent) override;
	void updateInput(const float& deltaTime) override;
	void updateButtons();
	void update(const float& deltaTime) override;
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = nullptr) override;

private:
	// Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, gui::Button*> buttons;

	AnimationComponent* animationComponent;
	sf::Sprite animationSprite;
	sf::Texture animationTexture;
	void createAnimationComponent();

	// Fonctions d'initialisation
	// void initVariables();
	void initFonts();
	// void initKeybinds();
	void initGui();
	void resetGui();
	void initAnimations();
};

#endif // __MAIN_MENU_STATE_HPP__
