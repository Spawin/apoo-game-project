#include "include/GameMap.hpp"

const float GameMap::GAME_MAP_WIDTH(32 * 40);
const float GameMap::GAME_MAP_HEIGHT(32 * 80);

GameMap::GameMap()
{
}

GameMap::~GameMap()
{
}

float GameMap::getGAME_MAP_WIDTH()
{
	return GAME_MAP_WIDTH;
}
float GameMap::getGAME_MAP_HEIGHT()
{
	return GAME_MAP_HEIGHT;
}

bool GameMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
	// on charge la texture du tileset
	if (!m_tileset.loadFromFile(tileset))
	{
		std::cerr << "erreur chargement dans GameMap :" << tileset << std::endl;
		return false;
	}

	// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	// on remplit le tableau de vertex, avec un quad par tuile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// on récupère le numéro de tuile courant
			// int tileNumber = tiles[i + j * width];
			int tileNumber = tiles[i + j * width];

			// on en déduit sa position dans la texture du tileset
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			// on récupère un pointeur vers le quad à définir dans le tableau de vertex
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// on définit ses quatre coins
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// on définit ses quatre coordonnées de texture
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}

	return true;
}

bool GameMap::load(const std::string& tileset, sf::Vector2u* tileSize, sf::Vector2u* tilesStart, const int* tiles, unsigned int width, unsigned int height, int count)
{
	// TODO - Controller si la tailles des tableau envoyés diffèrent

	// on charge la texture du tileset
	if (!m_tileset.loadFromFile(tileset))
	{
		std::cerr << "erreur chargement dans GameMap :" << tileset << std::endl;
		std::cerr << count << tileset << std::endl;
		return false;
	}

	// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	// for (int i = 0; i < (int)(width * height); i++)
	// {
	// on remplit le tableau de vertex, avec un quad par tuile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// tile number
			int k(tiles[i + j * width]);
			// on remplit le tableau de vertex, avec un quad par tuile

			// on récupère le numéro de tuile courant
			// int tileNumber = tiles[k * width[k]];

			// on en déduit sa position dans la texture du tileset
			// int tu = tileNumber % (m_tileset.getSize().x / tileSize[k].x);
			// int tv = tileNumber / (m_tileset.getSize().x / tileSize[k].x);

			// on récupère un pointeur vers le quad à définir dans le tableau de vertex
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// on définit ses quatre coins
			quad[0].position = sf::Vector2f(i * tileSize[k].x, j * tileSize[k].y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize[k].x, j * tileSize[k].y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize[k].x, (j + 1) * tileSize[k].y);
			quad[3].position = sf::Vector2f(i * tileSize[k].x, (j + 1) * tileSize[k].y);

			//? coordonnée de sortie?
			// on définit ses quatre coordonnées de texture
			quad[0].texCoords = sf::Vector2f(tilesStart[k].x, tilesStart[k].y);
			quad[1].texCoords = sf::Vector2f(tilesStart[k].x + tileSize[k].x, tileSize[k].y);
			quad[2].texCoords = sf::Vector2f(tilesStart[k].x + tileSize[k].x, tilesStart[k].y + tileSize[k].y);
			quad[3].texCoords = sf::Vector2f(tilesStart[k].x, tilesStart[k].y + tileSize[k].y);

			// for (unsigned int i = 0; i < width[k]; ++i)
			// 	for (unsigned int j = 0; j < height[k]; ++j)
			// 	{
			// 	}
		}

	return true;
}

void GameMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// on applique la transformation
	states.transform *= getTransform();

	// on applique la texture du tileset
	states.texture = &m_tileset;

	// et on dessine enfin le tableau de vertex
	target.draw(m_vertices, states);
}