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

void Tram::avance()
{
	// 1. Détermination du nombre de pixels dont le tram doit avancer

	// variation de x et y pour changer les coordonnées du tram (th. Pythagore)
	double variation = sqrt((pow(d_vitesse, 2) / 2));


	// 2. Changement de la position du tram

	// position de l'arrêt vers lequel se dirige le tram
	Position pArretSuiv = d_arretSuiv->getPosition();

	if (d_sens)	// avance de gauche à droite (d_sens = true)
	{	
		// cas où la droite entre les deux arrêts autour du tram est décroissante 
		if (pArretSuiv.getX() > d_position.getX() && pArretSuiv.getY() > d_position.getY())		// <==> prochain arrêt visuellement en-dessous du tram
		{
			d_position.setPos(d_position.getX() + variation, d_position.getY() + variation);
		}
		// cas où la droite entre les deux arrêts autour du tram est croissante
		else if (pArretSuiv.getX() > d_position.getX() && pArretSuiv.getY() < d_position.getY())	// <==> prochain arrêt visuellement au-dessus du tram
		{
			d_position.setPos(d_position.getX() + variation, d_position.getY - variation);
		}
	}
	else	// avance de droite à gauche (d_sens = false)
	{
		// droite décroissante (prochain arêt en-dessous du tram)
		if (pArretSuiv.getX() < d_position.getX() && pArretSuiv.getY() > d_position.getY())
		{
			d_position.setPos(d_position.getX() - variation, d_position.getY() + variation);
		}
		// droite croissante (prochain arrêt au-dessus du tram)
		else if (pArretSuiv.getX() < d_position.getX() && pArretSuiv.getY() < d_position.getY())
		{
			d_position.setPos(d_position.getX() - variation, d_position.getY() - variation);
		}
	}
}

double Tram::distanceTramDevant() const
{
	double distance = sqrt(pow( (d_tramSuiv->d_position.getX() - d_position.getX()), 2) + pow((d_tramSuiv->d_position.getY() - d_position.getY()), 2));
	return distance;
}

bool Tram::doitSArreter()
{
	return distanceTramDevant() <= d_distanceMin;
}

void Tram::arret()
{
	setVitesse(false);
}
