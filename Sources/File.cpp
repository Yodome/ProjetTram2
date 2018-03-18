//
// Created by e1701567 on 20/02/2018.
//

#include "..\Headers\File.h"

/**
 * Constructeur par défaut : initialise une file vide, de taille 0 avec premier et dernier tram pointant sur NULL
 */
File::File() : d_taille{0}, d_premierTram{ nullptr }, d_dernierTram{ nullptr }
{}

/**
 * Destructeur de la file : fait sortir tous les trams
 */
File::~File()
{
	while (d_premierTram) sortir();
}

/**
 * Retourne le premier tram de la file
 * @return le premier tram de la file
 */
Tram * File::getPremierTram() const
{
	return d_premierTram;
}

/**
 * Retourne le dernier tram de la file
 * @return le dernier tram de la file
 */
Tram * File::getDernierTram() const
{
	return d_dernierTram;
}

/**
 * Met premierTram en tant que premier tram de la file
 * @param premierTram - premier tram de la file après application de la méthode
 */
void File::setPremierTram(Tram &premierTram)
{
	*d_premierTram = premierTram;
}

/**
 * Met dernierTram en tant que dernier tram de la file
 * @param dernierTram - dernier tram de la file après application de la méthode
 */
void File::setDernierTram(Tram &dernierTram)
{
	*d_dernierTram = dernierTram;
}

/**
 * Fait entrer un tram dans la file. Il devient instantanément le dernier tram de la file
 * @param tr - tram à faire entrer dans la file
 */
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

/**
 * Fait sortir le premier tram de la file
 * @return un objet Tram prenant les valeurs du premier tram de la file
 */
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

/**
 * Indique si la file est vide
 * @return vrai si la file est vide, faux sinon
 */
bool File::estVide() const
{
	return (d_premierTram == nullptr);
}

/**
 * Renvoie le nombre de trams de la file (sa taille)
 * @return entier indiquant la taille de la file
 */
int File::getTaille() const {
	return d_taille;
}
