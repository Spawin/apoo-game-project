#if !defined(__GUI_HPP__)
	#define __GUI_HPP__

enum button_states
{
	BTN_IDLE = 0,
	BTN_HOVER,
	BTN_ACTIVE
};

namespace gui
{
float p2pX(const float perc, const sf::VideoMode& vm);
float p2pY(const float perc, const sf::VideoMode& vm);
unsigned calcCharSize(const sf::VideoMode& vm, const unsigned modifier = 60);

class Button
{

public:
	// Constructeurs/Destructeur
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, unsigned characterSize,
		sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor,
		sf::Color outline_idle_color = sf::Color::Transparent, sf::Color outline_hover_color = sf::Color::Transparent, sf::Color outline_active_color = sf::Color::Transparent, short unsigned id = 0);
	~Button();

	// Fonctions/Méthodes
	bool isPressed() const;
	const std::string getText() const;
	const short unsigned& getId() const;

	void setText(const std::string text);
	void setId(const short unsigned id);

	const sf::Vector2f& getPosition() const;
	/**
	 * @brief Set the Position object
	 *
	 * @param x
	 * @param y
	 * @param addX Décalage sur l'axe des x
	 * @param addY Décalage sur l'axe des y
	 */
	void setPosition(float x, float y, float addX, float addY);

	void update(const sf::Vector2i& mousePosWindow);
	void render(sf::RenderTarget& target);

private:
	// Variables
	short unsigned buttonState;
	short unsigned id;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color textIdleColor;
	sf::Color textHoverColor;
	sf::Color textActiveColor;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	sf::Color outlineIdleColor;
	sf::Color outlineHoverColor;
	sf::Color outlineActiveColor;

	// Pour tenir compte du décalage de la position de la souris sur certains affichages (quand oon modifie le centre de la vue et la position des shapes)
	sf::Vector2f offset;

	// Fonctions d'initialisation
};

class ProgressBar
{
private:
	sf::VideoMode& vm;
	std::string barString;
	sf::Text text;
	float maxWidth;
	sf::RectangleShape back;
	sf::RectangleShape inner;

public:
	ProgressBar(float x, float y, float width, float height,
		sf::Color inner_color, unsigned character_size,
		sf::VideoMode& vm, sf::Font* font = NULL, bool text_bold = false);
	~ProgressBar();

	//Accessors

	//Modifiers
	void setPosition(sf::Vector2f const& position, sf::VideoMode& vm);

	//Functions
	void update(int current_value, int max_value);
	void render(sf::RenderTarget& target);
};

} // namespace gui

#endif // __GUI_HPP__
