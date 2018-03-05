//
// Created by e1701567 on 20/02/2018.
//

#include "..\Headers\Tram.h"

Tram::Tram() : d_vitesse{ false }, d_sens{ false }, d_tempsArret{ 1000 }, d_distanceMin{ 100 },
d_vitesseMax{ 20 }, d_position{}, d_tramSuiv{ nullptr }, d_arretSuiv{ nullptr },
d_numLigne{ 0 }
{

}


//--------------------------------- GETTER -------------------------------

bool Tram::getVitesse() const
{
	return d_vitesse;
}

int Tram::getVitessemax() const
{
	return d_vitesseMax;
}

bool Tram::getSens() const
{
	return d_sens;
}

int Tram::getTempsArret() const
{
	return d_tempsArret;
}

int Tram::getDistanceMin() const
{
	return d_distanceMin;
}

int Tram::getNumLigne() const
{
	return d_numLigne;
}

Position Tram::getPosition()
{
	return d_position;
}

Tram &Tram::getTramSuivant() const
{
	return *d_tramSuiv;
}

Arret &Tram::getArretSuivant() const
{
	return *d_arretSuiv;
}

//--------------------------------- SETTER -------------------------------
void Tram::setVitesse(bool vitesse)
{
	d_vitesse = vitesse;
}

void Tram::setVitessemax(int vitesseMax)
{
	d_vitesseMax = vitesseMax;
}

void Tram::setSens(bool sens)
{
	d_sens = sens;
}

void Tram::setTempsArret(int tempsArret)
{
	d_tempsArret = tempsArret;
}

void Tram::setDistanceMin(int distanceMin)
{
	d_distanceMin = distanceMin;
}

void Tram::setNumLigne(int numLigne)
{
	d_numLigne = numLigne;
}

void Tram::setPosition(int x, int y)
{
	d_position.setPos(x, y);
}

void Tram::setTramSuivant(Tram &tramSuivant)
{
	*d_tramSuiv = tramSuivant;
}

void Tram::setArretSuivant(Arret &arretSuivant)
{
	*d_arretSuiv = arretSuivant;
}
