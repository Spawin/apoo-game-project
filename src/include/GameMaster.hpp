#if !defined(__GAME_MASTER__)
	#define __GAME_MASTER__

	#include <memory>
	#include <vector>

class GameMaster
{
public:
	GameMaster();
	~GameMaster();

private:
	std::vector<std::shared_ptr<sf::Texture>> textures;
};

#endif // __GAME_MASTER__
