#include "include/GraphicsSettings.hpp"

GraphicsSettings::GraphicsSettings()
{
	this->title = "DEFAULT";
	this->resolution = sf::VideoMode::getDesktopMode();
	this->fullscreen = false;
	this->verticalSync = true;
	this->frameRateLimit = 60;
	// this->contextSettings.antialiasingLevel = 0;
	this->videoModes = sf::VideoMode::getFullscreenModes();

	this->screenScalingFactor = 1.f;
}

//
float const& GraphicsSettings::scScF()
{
	return this->screenScalingFactor;
}

void GraphicsSettings::setScreenScalingFactor(float scScF)
{
	this->screenScalingFactor = scScF;
}

void GraphicsSettings::loadFromFile(const std::string path)
{
	std::ifstream ifs(path);

	if (ifs.is_open())
	{
		std::getline(ifs, this->title);
		ifs >> this->resolution.width >> this->resolution.height;
		ifs >> this->fullscreen;
		ifs >> this->frameRateLimit;
		ifs >> this->verticalSync;
		ifs >> this->screenScalingFactor;
		// ifs >> this->contextSettings.antialiasingLevel;
	}

	ifs.close();
}