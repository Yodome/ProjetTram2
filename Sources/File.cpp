//
// Created by e1701567 on 20/02/2018.
//

#include "..\Headers\File.h"

File::File() : d_premierTram{ nullptr }, d_dernierTram{ nullptr } {

}

File::~File()
{
	while (d_premierTram) sortir();
}

Tram * File::getPremierTram() const
{
	return d_premierTram;
}

Tram * File::getDernierTram() const
{
	return d_dernierTram;
}


void File::setPremierTram(Tram &premierTram)
{
	*d_premierTram = premierTram;
}

void File::setDernierTram(Tram &dernierTram)
{
	*d_dernierTram = dernierTram;
}

void File::entrer(Tram &tr)
{
	if (this->estVide())
	{
		d_premierTram = d_dernierTram = &tr;
	}
	else
	{
		d_dernierTram->d_tramSuiv = &tr;
		d_dernierTram = d_dernierTram->d_tramSuiv;
		tr.d_tramSuiv = 0;
	}

	d_taille++;
}

Tram& File::sortir()
{
	Tram *tr = new Tram();
	tr->d_vitesse = d_premierTram->d_vitesse;
	tr->d_vitesseMax = d_premierTram->d_vitesseMax;
	tr->d_sens = d_premierTram->d_sens;
	tr->d_tempsArret = d_premierTram->d_tempsArret;
	tr->d_distanceMin = d_premierTram->d_distanceMin;
	tr->d_numLigne = d_premierTram->d_numLigne;
	tr->d_position = d_premierTram->d_position;

	Tram *as = d_premierTram;
	d_premierTram = d_premierTram->d_tramSuiv;

	if (d_premierTram == 0)	// �a devient une file vide
	{
		d_dernierTram = 0;
	}

	d_taille--;
	delete as;
	return *tr;
}

bool File::estVide() const
{
	return (d_premierTram == nullptr);
}

int File::getTaille() const {
	return d_taille;
}
