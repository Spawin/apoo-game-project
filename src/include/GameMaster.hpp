#if !defined(__GAME_MASTER__)
	#define __GAME_MASTER__

	#include <memory>
	#include <vector>

class GameMaster
{
public:
	GameMaster();
	~GameMaster();

	static const sf::Vector2i getSPRITE_BOX_CENTER();

private:
	std::vector<std::shared_ptr<sf::Texture>> textures;
	/**
	 * @brief Coordonnées du centre des carrés de sprite 32x32
	 *
	 */
	static const sf::Vector2i m_spriteBoxCenter;
};

#endif // __GAME_MASTER__
