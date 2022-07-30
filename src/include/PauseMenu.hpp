#if !defined(__PAUSE_MENU_HPP__)
	#define __PAUSE_MENU_HPP__

	#include "include/Gui.hpp"

namespace gui
{
class Button;
} // namespace gui

class PauseMenu
{
public:
	PauseMenu(sf::VideoMode& vm, sf::Font& font);
	virtual ~PauseMenu();

	//Accessor
	std::map<std::string, gui::Button*>& getButtons();

	//Functions
	bool isButtonPressed(const std::string key);
	void addButton(const std::string key,
		const float y,
		const float width,
		const float height,
		const unsigned char_size,
		const std::string text);
	void update(const sf::Vector2i& mousePosView);
	void render(sf::RenderTarget& target);

private:
	sf::Font& font;
	sf::Text menuText;

	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, gui::Button*> buttons;

	void setGraphicsElementPosition(sf::View const& view);
};

#endif // __PAUSE_MENU_HPP__
