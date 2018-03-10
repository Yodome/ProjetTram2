//
// Created by e1701567 on 20/02/2018.
//

#include "..\Headers\Tram.h"
#include <cmath>

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

double Tram::distanceTramDevant() const
{
	return sqrt(pow( (d_tramSuiv->d_position.getX() - d_position.getX()), 2) + pow((d_tramSuiv->d_position.getY() - d_position.getY()), 2));
}

double Tram::distanceArretSuiv() const
{
	return sqrt(pow(d_arretSuiv->getPosition().getX() - d_position.getX(), 2) + pow(d_arretSuiv->getPosition().getY() - d_position.getY(), 2));
}

void Tram::avance()
{
	Position posArretSuiv = d_arretSuiv->getPosition();

	// distance à l'arret suivant
	double ds = distanceArretSuiv();

	// distance de l'arrêt selon la future position du tram
	double dt = ds - d_vitesse;

	double a = dt / ds;

	d_position.setPos(static_cast<int>((1 - a)*d_position.getX() - a * d_arretSuiv->getPosition().getX()),
						static_cast<int>((1 - a)*d_position.getY() - a * d_arretSuiv->getPosition().getY()));
}

bool Tram::doitSArreter()
{
	return distanceTramDevant() <= d_distanceMin;
}

void Tram::arret()
{
	setVitesse(false);
}
