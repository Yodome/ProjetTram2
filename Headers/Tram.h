//
// Created by e1701567 on 20/02/2018.
//

#ifndef PROJETTRAM_TRAM_H
#define PROJETTRAM_TRAM_H


#include "Position.h"
#include "Arret.h"


class Tram
{
public:
	Tram();

	//getter
	bool getVitesse() const;
	int getVitessemax() const;
	bool getSens() const;
	int getTempsArret() const;
	int getDistanceMin() const;
	int getNumLigne() const;
	Position getPosition();
	Tram* getTramSuivant() const;
	Arret* getArretSuivant() const;
    int getNumArretSuivant() const;

	//setter
	void setVitesse(bool vitesse);
	void setVitessemax(int vitesseMax);
	void setSens(bool sens);
	void setTempsArret(int tempsArret);
	void setDistanceMin(int distanceMin);
	void setNumLigne(int numLigne);
	void setPosition(int x, int y);
	void setTramSuivant(Tram& tramSuivant);
	void setArretSuivant(Arret& arretSuivant);
    void setNumArretSuivant (int numArretSuivant);

	void avance();	// d�termine la position du tram selon sa vitesse
	double distanceTramDevant() const;
	double distanceArretSuiv() const;
	bool doitSArreter();	// indique si le tram doit s'arr�ter (ne proc�de � aucun changement des coordonn�es du tram)
	void arret();

	friend class File;
private:
	bool d_vitesse;
	int d_vitesseMax;
	bool d_sens;
	int d_tempsArret;
	int d_distanceMin;
	int d_numLigne;
	int d_numArretSuiv;
	Position d_position;
	Tram *d_tramSuiv;
	Arret *d_arretSuiv;//friend, on veut juste avoir le prochain
};


#endif //PROJETTRAM_TRAM_H
