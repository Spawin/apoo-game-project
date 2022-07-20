#ifndef __GRAPHICS_SETTINGS_HPP__
#define __GRAPHICS_SETTINGS_HPP__

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
	// void saveToFile(const std::string path);
	void loadFromFile(const std::string path);
};

#endif // __GRAPHICS_SETTINGS_HPP__