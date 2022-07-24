#include "include/Position.hpp"
#include "include/Collider.hpp"
#include "include/GameMap.hpp"
#include "include/Hall.hpp"
#include "include/consts.hpp"
#include "include/utils.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <math.h>

int Position::m_spaceWidth { 0 };
int Position::m_spaceHeight { 0 };

// Constructeur factultatif mais ici on envoie un message d’erreur si une coordonnée est créée avant l’initialisation de l’espace
Position::Position(float detectabilityRadius) :
	DETECTABILITY_RADIUS(detectabilityRadius)
{
	if (m_spaceWidth == 0 || m_spaceHeight == 0)
	{
		std::cerr << "Attention : une coordonnée a été créée avant l’initialisation de l’espace !" << std::endl;
	}
	setPreviousPosition(m_x, m_y);
	recalculate();
}

Position::Position(float px, float py, float detectabilityRadius) :
	m_x(px),
	m_y(py),
	DETECTABILITY_RADIUS(detectabilityRadius)
{
	if (m_spaceWidth == 0 || m_spaceHeight == 0)
	{
		std::cerr << "Attention : une coordonnée a été créée avant l’initialisation de l’espace !" << std::endl;
	}
	setPreviousPosition(m_x, m_y);
	recalculate();
}

Position::~Position()
{
}

//

int Position::getSpaceWidth() const
{
	return m_spaceWidth;
}

int Position::getSpaceHeight() const
{
	return m_spaceHeight;
}

float Position::getX() const
{
	return m_x;
}

float Position::getY() const
{
	return m_y;
}

// L’opérateur += ajoute déjà le vecteur en paramètre puis ajoute ou retire la taille de l’espace sur les composantes x,y si besoin
void Position::operator+=(MyVector const& v)
{
	setPreviousPosition(m_x, m_y);
	m_x += v.m_x;
	m_y += v.m_y;
	recalculate();
}

void Position::operator=(Position const& p)
{
	setPreviousPosition(m_x, m_y);
	m_x = p.getX();
	m_y = p.getY();
	recalculate();
}

std::ostream& operator<<(std::ostream& out, Position const& p)
{
	out << "[ x=" << p.getX() << " , y=" << p.getY() << " ]";
	out << " Block [ x=" << ceil(p.getX() / (float)GAME_BLOCKS_WIDTH) << " , y=" << ceil(p.getY() / (float)GAME_BLOCKS_WIDTH) << " ]";
	return out;
}

void Position::initSpace(int width, int height)
{
	// on envoie un message d’erreur si l’espace était déjà initialisé
	if (m_spaceWidth != 0 || m_spaceHeight != 0)
	{
		std::cerr << "Attention : l’espace était déjà initialisé !" << std::endl;
	}
	m_spaceWidth = width;
	m_spaceHeight = height;
}

void Position::recalculate()
{

	Collider::update(); // REVIEW - On peut l'enlever mait il faudrait augmenter les points de contact.

	if (!canMove() || m_thereIsARigidBody)
	{
		if (m_x != m_previousPosition.m_x)
		{
			m_x = m_previousPosition.m_x;
		}
		if (m_y != m_previousPosition.m_y)
		{
			m_y = m_previousPosition.m_y;
		}
		m_thereIsARigidBody = false;
	}
	//* Pour replacer dans la zone autorisé : méthode pas ouf
	/*
	if (!canMove())
	{
		// TODO -
		// REVIEW - Pour le cas du lounge, les dimensions ont changés
		// On replace m_y
		if (m_y < WALL_WIDTH + DETECTABILITY_RADIUS)
		{
			m_y = WALL_WIDTH + DETECTABILITY_RADIUS;
		}
		if (m_y > (int)GameMap::getGAME_MAP_HEIGHT - WALL_WIDTH - DETECTABILITY_RADIUS)
		{
			m_y = (int)GameMap::getGAME_MAP_HEIGHT - WALL_WIDTH - DETECTABILITY_RADIUS;
		}
		if (isBetween(m_y, (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS, (int)Hall::getMIN_HEIGHT))
		{
			m_y = (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS;
		}
		if (isBetween(m_y, (int)Hall::getMIN_HEIGHT, (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS))
		{
			m_y = (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS;
		}
		if (isBetween(m_y, 2 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS, 2 * (int)Hall::getMIN_HEIGHT))
		{
			m_y = 2 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS;
		}
		if (isBetween(m_y, 2 * (int)Hall::getMIN_HEIGHT, 2 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS))
		{
			m_y = 2 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS;
		}
		if (isBetween(m_y, 3 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS, 3 * (int)Hall::getMIN_HEIGHT))
		{
			m_y = 3 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS;
		}
		if (isBetween(m_y, 3 * (int)Hall::getMIN_HEIGHT, 3 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS))
		{
			m_y = 3 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS;
		}
		if (isBetween(m_y, 4 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS, 4 * (int)Hall::getMIN_HEIGHT))
		{
			m_y = 4 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS;
		}
		if (isBetween(m_y, 4 * (int)Hall::getMIN_HEIGHT, 4 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS))
		{
			m_y = 4 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS;
		}
		if (isBetween(m_y, 5 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS, 5 * (int)Hall::getMIN_HEIGHT))
		{
			m_y = 5 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS;
		}
		if (isBetween(m_y, 5 * (int)Hall::getMIN_HEIGHT, 5 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS))
		{
			m_y = 5 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS;
		}
		if (isBetween(m_y, 6 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS, 6 * (int)Hall::getMIN_HEIGHT))
		{
			m_y = 6 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS;
		}
		if (isBetween(m_y, 6 * (int)Hall::getMIN_HEIGHT, 6 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS))
		{
			m_y = 6 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS;
		}
		// On replace m_x
		if (m_x < WALL_WIDTH + DETECTABILITY_RADIUS)
		{
			m_x = WALL_WIDTH + DETECTABILITY_RADIUS;
		}
		if (m_x > (int)GameMap::getGAME_MAP_WIDTH - WALL_WIDTH - DETECTABILITY_RADIUS)
		{
			m_x = (int)GameMap::getGAME_MAP_WIDTH - WALL_WIDTH - DETECTABILITY_RADIUS;
		}
		if (m_y < 6 * (int)Hall::getMIN_HEIGHT)
		{
			if (isBetween(m_x, (int)Hall::getMIN_WIDTH - WALL_WIDTH / 2 - DETECTABILITY_RADIUS, (int)Hall::getMIN_WIDTH))
			{
				m_x = (int)Hall::getMIN_WIDTH - WALL_WIDTH / 2 - DETECTABILITY_RADIUS;
			}
			if (isBetween(m_x, (int)Hall::getMIN_WIDTH, (int)Hall::getMIN_WIDTH + WALL_WIDTH / 2 + DETECTABILITY_RADIUS))
			{
				m_x = (int)Hall::getMIN_WIDTH + WALL_WIDTH / 2 + DETECTABILITY_RADIUS;
			}
			if (isBetween(m_x, (int)Hall::getMIN_WIDTH + (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS, (int)Hall::getMIN_WIDTH + (int)Hall::getMIN_HEIGHT))
			{
				m_x = (int)Hall::getMIN_WIDTH + (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS;
			}
			if (isBetween(m_x, (int)Hall::getMIN_WIDTH + (int)Hall::getMIN_HEIGHT, (int)Hall::getMIN_WIDTH + (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS))
			{
				m_x = (int)Hall::getMIN_WIDTH + (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS;
			}
		}
	}
	//*/
}

float Position::getDistanceWith(Position const& autre) const
{
	auto delta = MyVector { std::min({ abs(m_x - autre.m_x), abs(m_x - autre.m_x - m_spaceWidth), abs(m_x - autre.m_x + m_spaceWidth) }), std::min({ abs(m_y - autre.m_y), abs(m_y - autre.m_y - m_spaceHeight), abs(m_y - autre.m_y + m_spaceHeight) }) };
	return sqrt(delta.m_x * delta.m_x + delta.m_y * delta.m_y);
}

void Position::setPosition(float posX, float posY)
{
	setPreviousPosition(m_x, m_y);
	m_x = posX;
	m_y = posY;
	recalculate();
}

MyVector Position::getPosition() const
{
	return MyVector { m_x, m_y };
}

void Position::setPreviousPosition(float x, float y)
{
	m_previousPosition.m_x = x;
	m_previousPosition.m_y = y;
}

void Position::setPreviousPosition(MyVector v)
{
	m_previousPosition = v;
}

bool Position::canMove()
{
	bool canMove(0);
	// On va repousser la zone de non mouvement d'un facteur
	// pour qu'il n'y ai pas de conflit avec la zone de redéploiment avec la fonction recalculate d'un corps qui ne doit pas bouger.
	int fac(0);
	if (isBetween(m_y, 6 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS - fac, (int)game::GAME_MAP_HEIGHT - WALL_WIDTH - DETECTABILITY_RADIUS + fac))
	{
		if (isBetween(m_x, WALL_WIDTH + DETECTABILITY_RADIUS - fac, (int)game::GAME_MAP_WIDTH - WALL_WIDTH - DETECTABILITY_RADIUS + fac))
		{
			canMove = true;
		}
	}
	else if (isBetween(m_y, WALL_WIDTH + DETECTABILITY_RADIUS - fac, (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS + fac) || isBetween(m_y, (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS - fac, 2 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS + fac) || isBetween(m_y, 2 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS - fac, 3 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS + fac) || isBetween(m_y, 3 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS - fac, 4 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS + fac) || isBetween(m_y, 4 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS - fac, 5 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS + fac) || isBetween(m_y, 5 * (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS - fac, 6 * (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS + fac))
	{
		if (isBetween(m_x, WALL_WIDTH + DETECTABILITY_RADIUS - fac, (int)Hall::getMIN_WIDTH - WALL_WIDTH / 2 - DETECTABILITY_RADIUS + fac) || isBetween(m_x, (int)Hall::getMIN_WIDTH + WALL_WIDTH / 2 + DETECTABILITY_RADIUS - fac, (int)Hall::getMIN_WIDTH + (int)Hall::getMIN_HEIGHT - WALL_WIDTH / 2 - DETECTABILITY_RADIUS + fac) || isBetween(m_x, (int)Hall::getMIN_WIDTH + (int)Hall::getMIN_HEIGHT + WALL_WIDTH / 2 + DETECTABILITY_RADIUS - fac, (int)game::GAME_MAP_WIDTH - WALL_WIDTH - DETECTABILITY_RADIUS + fac))
		{
			canMove = true;
		}
	}

	return canMove;
}
