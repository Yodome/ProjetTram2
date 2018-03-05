//
// Created by e1701567 on 20/02/2018.
//

#include "..\Headers\Arret.h"



Arret::Arret() :d_tempsArretMin{ 1000 }, d_libelle{ "" }, d_position{}, d_arretSuiv{ nullptr }, d_arretPrec{ nullptr }
{

}

Arret::Arret(int tempsArretMin, std::string libelle, Position pos) : d_tempsArretMin{tempsArretMin}, d_libelle{libelle}, d_position{pos}, d_arretSuiv{ nullptr }, d_arretPrec{ nullptr }
{

}

Position &Arret::getPosition()
{
	return d_position.getPos();
}

int Arret::getTempsArret() const
{
	return d_tempsArretMin;
}

void Arret::setLibelle(std::string nom)
{
	d_libelle = nom;
}

void Arret::setPotistion(int x, int y)
{
	d_position.setPos(x, y);
}

void Arret::setTempsArret(int temps)
{
	d_tempsArretMin = temps;
}