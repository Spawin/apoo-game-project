#if !defined(__GUI__)
	#define __GUI_HPP__

enum button_states
{
	BTN_IDLE = 0,
	BTN_HOVER,
	BTN_ACTIVE
};

namespace gui
{
class Button
{

public:
	// Constructeurs/Destructeur
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	// Fonctions/Méthodes
	bool isPressed() const;
	const std::string getText() const;
	const short unsigned& getId() const;

	void setText(const std::string text);
	void setId(const short unsigned id);

	void update(const sf::Vector2i& mousePosWindow);
	void render(sf::RenderTarget& target);

private:
	// Variables
	short unsigned buttonState;
	short unsigned id;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	// Fonctions d'initialisation
};

} // namespace gui

#endif // __HUTTON_HPP__
