#ifndef __GAME_MAP_HPP__
#define __GAME_MAP_HPP__

class GameMap : public sf::Drawable, public sf::Transformable
{
public:
	GameMap();
	~GameMap();

	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	/**
	 * @brief
	 *
	 * @param tileset la ressource
	 * @param tileSize les dimenssion du dessin voulut
	 * @param tilesStart les ccordonnes du premier point dsz chaque tiles
	 * @param tiles la matrice de la disposition
	 * @param width nombre d'élément en ligne
	 * @param height le nombre d'élément en colonne
	 * @param count la taille des tableau
	 * @return true
	 * @return false
	 */
	bool load(const std::string& tileset, sf::Vector2u* tileSize, sf::Vector2u* tilesStart, const int* tiles, unsigned int width, unsigned int height, int count);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

#endif // __GAME_MAP_HPP__
