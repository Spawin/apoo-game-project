#include "Platform/Platform.hpp"
#include "include/GameMaster.hpp"

int main()
{
	// REVIEW -  Pour enlever le spam de l'erreur : Failed to set DirectInput device axis mode: 1
	sf::err().rdbuf(NULL);

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif
	// util::Platform platform;
	// GameMaster game(platform);
	GameMaster game;

	game.run();

	return 0;
}
