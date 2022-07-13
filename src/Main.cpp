#include "Platform/Platform.hpp"
#include "include/Personage.hpp"
#include "include/Position.hpp"
#include "include/consts.hpp"

int main()
{
	// REVIEW -  Pour enlever le spam de l'erreur : Failed to set DirectInput device axis mode: 1
	sf::err().rdbuf(NULL);

	float windowWidth(0);
	float windowHeight(0);
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	windowWidth = (float)WINDOW_WIDTH * screenScalingFactor;
	windowHeight = (float)WINDOW_HEIGHT * screenScalingFactor;

	// Create the main window
	// Use the screenScalingFactor
	window.create(sf::VideoMode(windowWidth, windowHeight), "Le guerrier");
	platform.setIcon(window.getSystemHandle());

	// Initialisations de l'espace pour tous les éléments du jeux
	Position::initSpace(windowWidth, windowHeight);

	Personage spawin = Personage();

	auto chrono = sf::Clock();
	sf::Event event;
	// Start the game loop
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();

			///     if (event.type == sf::Event::Resized)
			///         doSomethingWithTheNewSize(event.size.width, event.size.height);

			// spawin.sendEvent(event);
		}

		// initialisation du time du game object
		GameOject::SetTime(chrono.restart().asSeconds());

		spawin.update();

		// Clear screen
		window.clear();

		// window.draw(shape);
		spawin.show(window);

		// Update the window
		window.display();
	}

	return 0;
}
