//
// Created by e1701567 on 20/02/2018.
//


#include "..\Headers\Position.h"

/**
 * Constructeur par défaut : initialise une position avec les coordonnées x et y nulles
 */
Position::Position() : d_x{ 0 }, d_y{ 0 }
{}

/**
 * Renvoie la coordonnée en abscisse 
 * @return d_x - coordonnée en abscisse
 */
int Position::getX() const
{
	return d_x;
}

/**
 * Renvoie la coordonnée en ordonnée
 * @return d_y - coordonnée en ordonnée
 */
int Position::getY() const
{
	return d_y;
}

/**
 * Renvoie les coordonnées de lui même 
 * @return Position - coordonnées de lui-même
 */
Position& Position::getPos()
{
	return *this;
}

/**
 * Modifie la coordonnée en abscisse et en ordonnée
 * @param [in] x - coordonnée en abscisse
 * @param [in] y - coordonnée en ordonnée
 */
void Position::setPos(int x, int y)
{
	d_x = x;
	d_y = y;
}