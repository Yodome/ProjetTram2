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
	// Constructeur par défaut
	Tram();

	//------------------- GETTER ---------------------
	// Renvoie la vitesse actuelle du tram
	bool getVitesse() const;
	// Renvoie la vitesse max du tram
	int getVitessemax() const;
	// Renvoie le sens du tram (1 pour gauche-droite, 0 pour droite-gauche)
	bool getSens() const;
	// Renvoie le temps restant que le tram doit passer à l'arret
	int getTempsArret() const;
	// Renvoie la distance minimale à respecter entre deux trams
	int getDistanceMin() const;
	// Renvoie le numéro de ligne auquel le tram est affilié
	int getNumLigne() const;
	// Renvoie la position actuelle du tram
	Position getPosition();
	// Renvoie un pointeur sur le tram suivant (celui de devant)
	Tram* getTramSuivant() const;
	// Renvoie un pointeur sur l'arrêt vers lequel se dirige le tram
	Arret* getArretSuivant() const;
	// Renvoie le numéro de l'arrêt vers lequel se dirige le tram
    int getNumArretSuivant() const;

	//------------------ SETTER -----------------------
	// Modifie la vitesse du tram
	void setVitesse(bool vitesse);
	// Modifie la vitesse maximale du tram
	void setVitessemax(int vitesseMax);
	// Modifie le sens du tram
	void setSens(bool sens);
	// Modifie le temps restant que le tram doit passer sur l'arrêt
	void setTempsArret(int tempsArret);
	// Modifie la distance minimale que le tram doit respecter
	void setDistanceMin(int distanceMin);
	// Modifie le numéro de la ligne auquel le tram est affilié
	void setNumLigne(int numLigne);
	// Modifie la position actuelle du tram
	void setPosition(int x, int y);
	// Modifie le pointeur sur le tram suivant
	void setTramSuivant(Tram& tramSuivant);
	// Modifie le pointeur sur l'arrêt suivant (celui vers lequel le tram se dirige)
	void setArretSuivant(Arret& arretSuivant);
	// Modifie le numéro de l'arrêt vers lequel le tram se dirige
    void setNumArretSuivant (int numArretSuivant);


	// Détermine la position du tram selon sa vitesse
	void avance();
	// Renvoie la distance avec le tramSuivant
	double distanceTramDevant() const;
	// Renvoie la distance avec arretSuivant
	double distanceArretSuiv() const;
	// Indique si le tram doit s'arr�ter (ne proc�de � aucun changement des coordonn�es du tram)
	bool doitSArreter();
	// Met le tram courant à l'arrêt : sa vitesse devient nulle
	void arret();

	friend class File;
private:
	bool d_vitesse;	// vitesse actuelle du tram
	int d_vitesseMax;	// vitesse maximale du tram
	bool d_sens;	// sens du tram
	int d_tempsArret;	// temps d'arrêt restant que le tram doit passer
	int d_distanceMin;	// distance minimale que le tram doit respecter
	int d_numLigne;		// numéro de ligne auquel le tram est affilié
	int d_numArretSuiv;	// numéro de l'arrêt suivant vers lequel le tram se dirige
	Position d_position;	// position du tram
	Tram *d_tramSuiv;	// tram suivant dans la file
	Arret *d_arretSuiv;		// arret suivant vers lequel le tram se dirige
};


#endif //PROJETTRAM_TRAM_H
