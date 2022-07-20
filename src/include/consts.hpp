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

#define M_PI 3.14		  //16
#define WINDOW_WIDTH 1200 // 800 NOTE - On va la gerder
#define WINDOW_HEIGHT 600 // 540
// #define GAME_MAP_WIDTH 1100	 // !depracted
// #define GAME_MAP_HEIGHT 2200 // !depracted

#define DISTANCE_MIN_BETWEEN_OBJECTS 10 // Distance minimal entre deux points de contact d'un objet

#define DEFAULT_DETECTABILITY_RADIUS 16	   // Diamètre 32
#define PERSONNAGE_DETECTABILITY_RADIUS 16 // Diamètre 32
#define PERSONNAGE_WIDTH 32				   // Diamètre de la zone occupé par un personnage
#define GAME_BLOCKS_WIDTH 32			   // Taille de la largeur d'un bloc; un bloc est carré...

#define WALL_WIDTH 32

enum movement_states
{
	IDLE = 0,
	MOVING,
	MOVING_LEFT,
	MOVING_RIGHT,
	MOVING_UP,
	MOVING_DOWN
};

#endif // __CONST_HPP__