#include "Platform/Platform.hpp"
#include "include/Collider.hpp"
#include "include/GameMap.hpp"
#include "include/House.hpp"
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

	// On fix la limite de frames
	window.setFramerateLimit(60);

	// Create the main window
	// Use the screenScalingFactor
	window.create(sf::VideoMode(windowWidth, windowHeight), "Le guerrier" /*, sf::Style::Close*/);
	platform.setIcon(window.getSystemHandle());

	// Initialisations de l'espace pour tous les éléments du jeux
	Position::initSpace((int)GameMap::getGAME_MAP_WIDTH, (int)GameMap::getGAME_MAP_HEIGHT);

	// Construction de la maison
	House house;
	if (!house.load("content/house.png", sf::Vector2u(32, 32), house.getDisposition(), 40, 80))
	{
		std::cerr << "Erreur chargement < content/Tiles.png >" << std::endl;
		return -1;
	}

	// Mise en place des vues
	// sf::View player_view(sf::Vector2f(350.f, 300.f), sf::Vector2f(1000.f, 600.f));
	sf::View player_view(sf::Vector2f(350.f, 300.f), sf::Vector2f(1000.f, 600.f));
	sf::View minimap_view;
	minimap_view.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));

	Personage spawin = Personage("content/personage/personage.png", true);
	spawin.setGameObjectName("spawin");

	// Personage p2 = Personage(50, 50);

	auto chrono = sf::Clock();
	sf::Event event;

	// activation de la vue
	window.setView(player_view);
	// window.setView(minimap_view);

	// Start the game loop
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::Resized)
			{
				// on met à jour la vue, avec la nouvelle taille de la fenêtre
				// sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
				// window.setView(sf::View(visibleArea));
				player_view.setSize(event.size.width, event.size.height);
				window.setView(player_view);
				// window.setView(minimap_view);
			}

			// spawin.sendEvent(event);
		}

		// Appel pour tester la proximité de chaque collider
		Collider::update();

		// initialisation du time du game object
		GameObject::SetTime(chrono.restart().asSeconds());

		//* ANCHOR - Appel des update
		spawin.update();
		// p2.update();

		// Clear screen
		window.clear();

		//* Affichage de la maison
		window.draw(house);

		//* ANCHOR - Affichage des gameObjects
		spawin.show(window);
		// p2.show(window);

		// Update the window
		window.display();
	}

	return 0;
}
