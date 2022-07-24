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

#define DISTANCE_MIN_BETWEEN_OBJECTS 10 // Distance minimal entre deux points de contact d'un objet

#define DEFAULT_DETECTABILITY_RADIUS 16	   // Diamètre 32
#define PERSONNAGE_DETECTABILITY_RADIUS 16 // Diamètre 32
#define PERSONNAGE_WIDTH 32				   // Diamètre de la zone occupé par un personnage
// #define GAME_BLOCKS_WIDTH 32			   // Taille de la largeur d'un bloc; un bloc est carré...

#define WALL_WIDTH 32

namespace game
{
//* ------------------- Constantes
constexpr int WINDOW_WIDTH = 1200;
constexpr int WINDOW_HEIGHT = 675;
constexpr float PERSONAGE_MOVE_VELOCITY = 300.f;

constexpr int GAME_BLOCKS_WIDTH = 200; //32; // Taille de la largeur d'un bloc; un bloc est carré...

constexpr float GAME_MAP_WIDTH = game::GAME_BLOCKS_WIDTH * 40;
constexpr float GAME_MAP_HEIGHT = game::GAME_BLOCKS_WIDTH * 80;
constexpr int HOUSE_TILES_NUMBER = 40 * 80;

enum movement_states
{
	IDLE = 0,
	MOVING,
	MOVING_LEFT,
	MOVING_RIGHT,
	MOVING_UP,
	MOVING_DOWN
};

//* ------------------- Variables
// static float SCREEN_SCALING_FACTOR = 1.f;

// REVIEW -
inline std::string const& GAME_NAME()
{
	static std::string ret = "---";
	return ret;
}

}

#endif // __CONST_HPP__