#ifndef __GRAPHICS_SETTINGS_HPP__
#define __GRAPHICS_SETTINGS_HPP__

// TODO - Transformer en structure ou appliquer l'encapsulation
class GraphicsSettings
{
public:
	GraphicsSettings();

	//Variables
	std::string title;
	sf::VideoMode resolution;
	bool fullscreen;
	bool verticalSync;
	unsigned frameRateLimit;
	// sf::ContextSettings contextSettings;
	std::vector<sf::VideoMode> videoModes;

	//Functions
	/**
	 * @brief Retourne <screenScalingFactor>
	 *
	 * @return float const&
	 */
	float const& scScF();
	void setScreenScalingFactor(float scScF);
	// void saveToFile(const std::string path);
	void loadFromFile(const std::string path);

private:
	float screenScalingFactor;
};

#endif // __GRAPHICS_SETTINGS_HPP__