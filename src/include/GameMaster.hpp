#if !defined(__GAME_MASTER__)
	#define __GAME_MASTER__

	#include <memory>
	#include <vector>

class GameMaster
{
public:
	GameMaster();
	~GameMaster();

	void updateSFMLEvents();
	void update();
	void render();
	void run();

	//
	//
	//
	//
	//
	//
	//
	//
	static const GameMaster* GAME_MASTER();
	static const sf::Vector2i getSPRITE_BOX_CENTER();

private:
	// Variables

	// Initialisation
	void initWindow();
	//
	//
	//
	//
	static int m_countInstance;
	// Retourne l'objet gameMaster actuel
	static GameMaster* m_gameMaster;

	// std::vector<std::shared_ptr<sf::Texture>> textures;
	/**
	 * @brief Coordonnées du centre des carrés de sprite 32x32
	 *
	 */
	static const sf::Vector2i m_spriteBoxCenter;

	// Texture des éléments du jeu
	sf::Texture m_gameTexture;
};

#endif // __GAME_MASTER__
