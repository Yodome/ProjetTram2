//
// Created by e1701567 on 20/02/2018.
// Liste doublement chainée
//

#ifndef PROJETTRAM_LISTE_H
#define PROJETTRAM_LISTE_H


#include "Arret.h"

class Liste
{
public:
	Liste();	//Constructeur par défaut
	Liste(Liste &l);	// constructeur par recopie
	~Liste();	//Destructeur
	Arret * getTeteArret() const;	//Renvoie un pointeur d'arrêt correspondant à la tête de la liste d'arrêts (premier arrêt)
	Arret * getQueueArret() const;	//Renvoie un pointeur d'arrêt correspondant à la queue de la liste d'arrêts (dernier arrêt)
    Arret * getArret(int n) const;	//Renvoie un pointeur d'arrêt correpondant à un arrêt de la liste désigné par son numéro n
	void setTeteArret(Arret& arretTete);	//Modifier la tête de la liste d'arrêts
	void setQueueArret(Arret& arretQueue);	//Modifier la queue de la liste d'arrêts
	void insererEnQueue(Arret& ar);		//Insère un arrêt en queue de liste
    int getTaille() const;	//Renvoie la taille de la liste d'arrêts
    bool estVide() const;	//Renvoie vrai si la liste d'arrêts est vide


private:
    int d_taille;	//Variable qui contient la taille de la liste d'arrêts
	Arret * d_arretTete;	//Pointeur sur arrêt sur la tête de la liste
	Arret *d_arretQueue;	//Pointeur sur arrêt sur la queue de la liste

};


#endif //PROJETTRAM_LISTE_H