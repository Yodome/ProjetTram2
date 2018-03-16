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
	~Liste();
	Arret * getTeteArret() const;
	Arret * getQueueArret() const;
    Arret * getArret(int n) const;
	void setTeteArret(Arret& arretTete);
	void setQueueArret(Arret& arretQueue);
	void insererEnQueue(Arret& ar);
    int getTaille() const;
    bool estVide() const;


private:
    int d_taille;
	Arret * d_arretTete;
	Arret *d_arretQueue;

};


#endif //PROJETTRAM_LISTE_H