#include "include/Position.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

int Position::m_spaceWidth { 0 };
int Position::m_spaceHeight { 0 };

// Constructeur factultatif mais ici on envoie un message d’erreur si une coordonnée est créée avant l’initialisation de l’espace
Position::Position()
{
	if (m_spaceWidth == 0 || m_spaceHeight == 0)
	{
		std::cerr << "Attention : une coordonnée a été créée avant l’initialisation de l’espace !" << std::endl;
	}
}

Position::Position(float px, float py) :
	x(px),
	y(py)
{
	recalculate();
}

Position::~Position()
{
}

// L’opérateur += ajoute déjà le vecteur en paramètre puis ajoute ou retire la taille de l’espace sur les composantes x,y si besoin
void Position::operator+=(MyVector const& v)
{
	x += v.m_x;
	y += v.m_y;
	recalculate();
}

void Position::operator=(Position const& p)
{
	x = p.getX();
	y = p.getY();
	recalculate();
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
	while (x > m_spaceWidth)
	{
		x -= m_spaceWidth;
	}
	while (x < 0)
	{
		x += m_spaceWidth;
	}
	while (y > m_spaceHeight)
	{
		y -= m_spaceHeight;
	}
	while (y < 0)
	{
		y += m_spaceHeight;
	}
}

float Position::getDistanceWith(Position const& autre) const
{
	auto delta = MyVector { std::min({ abs(x - autre.x), abs(x - autre.x - m_spaceWidth), abs(x - autre.x + m_spaceWidth) }), std::min({ abs(y - autre.y), abs(y - autre.y - m_spaceHeight), abs(y - autre.y + m_spaceHeight) }) };
	return sqrt(delta.m_x * delta.m_x + delta.m_y * delta.m_y);
}