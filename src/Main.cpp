#include "Platform/Platform.hpp"

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());

	// Create the main window
	// Use the screenScalingFactor
	window.create(sf::VideoMode(800.0f * screenScalingFactor, 600.0f * screenScalingFactor), "Le guerrier");
	platform.setIcon(window.getSystemHandle());

	sf::CircleShape shape(window.getSize().y / 2);
	shape.setFillColor(sf::Color::White);

	// Load a sprite to display
	sf::Texture shapeTexture;
	if (!shapeTexture.loadFromFile("content/sfml.png"))
		return EXIT_FAILURE;
	shape.setTexture(&shapeTexture);

	/*
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("nice_music.ogg"))
        return EXIT_FAILURE;
    // Play the music
    music.play();
	//*/

	sf::Event event;

	// REVIEW -  Pour enlever le spam de l'erreur : Failed to set DirectInput device axis mode: 1
	sf::err().rdbuf(NULL);

	// Start the game loop
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Clear screen
		window.clear();

		window.draw(shape);

		// Update the window
		window.display();
	}

	return 0;
}
