/**
 * @file consts.hpp
 * @author B AND D
 * @brief Ensemble des constantes du jeux
 * @version 0.1
 * @date 2022-07-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __CONST_HPP__
#define __CONST_HPP__

// #define GAME_MAP_WIDTH 1100	 // !depracted
// #define GAME_MAP_HEIGHT 2200 // !depracted

namespace game
{
//* ------------------- Constantes
constexpr int WINDOW_WIDTH = 1200;
constexpr int WINDOW_HEIGHT = 675;
constexpr float PERSONAGE_MOVE_VELOCITY = 300.f;

// Taille de la largeur d'un bloc; un bloc est carré...
constexpr int GAME_BLOCKS_WIDTH = 200;

constexpr float GAME_MAP_WIDTH = game::GAME_BLOCKS_WIDTH * 40;
constexpr float GAME_MAP_HEIGHT = game::GAME_BLOCKS_WIDTH * 80;
constexpr int HOUSE_TILES_NUMBER = 40 * 80;

constexpr int WALL_WIDTH = 120; //32
// Représente la marge considérée d'un mur mis en horizontal
constexpr int WALL_HEIGHT = 32;

// Distance minimal entre deux points de contact d'un objet
constexpr int DISTANCE_MIN_BETWEEN_OBJECTS = 10;

// Diamètre 32
constexpr int DEFAULT_DETECTABILITY_RADIUS = 16;
// Diamètre 32
constexpr int PERSONNAGE_DETECTABILITY_RADIUS = 16;
// Diamètre de la zone occupé par un personnage
constexpr int PERSONNAGE_WIDTH = 32;

constexpr int PERSONNAGE_MAX_HEALTH = 100;
constexpr int PERSONNAGE_MAX_SPECIALITY = 100;

constexpr int INVENTORY_BLOCK_WIDTH = 80;

// constexpr int NOMBER_OF_WALLS = 32;

enum movement_states
{
	IDLE = 0,
	MOVING,
	MOVING_LEFT,
	MOVING_RIGHT,
	MOVING_UP,
	MOVING_DOWN
};

enum inventory_items_types
{
	DEFAULT = -1,
	VIAL = 0,
	ARMORY,
	TELEPORTKEY,
	MONEY
};

//* ------------------- Variables
// static float SCREEN_SCALING_FACTOR = 1.f;
// sf::VideoMode* vm = nullptr;
// // Dosis-Light.ttf
// sf::Font defaultFont;

// REVIEW -
inline std::string const& GAME_NAME()
{
	static std::string ret = "---";
	return ret;
}

}

#endif // __CONST_HPP__