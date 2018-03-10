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
	Liste();
	Liste(Liste &l);	// constructeur par recopie
	Arret * getTeteArret() const;
	Arret& getQueueArret() const;
	void setTeteArret(Arret& arretTete);
	void setQueueArret(Arret& arretQueue);
	void insererEnQueue(Arret& ar);
    int getTaille();
    bool estVide();


private:
    int d_taille;
	Arret * d_arretTete;
	Arret *d_arretQueue;

};


#endif //PROJETTRAM_LISTE_H