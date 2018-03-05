//
// Created by e1701567 on 20/02/2018.
//

#ifndef PROJETTRAM_LIGNE_H
#define PROJETTRAM_LIGNE_H


#include "File.h"
#include "Liste.h"

class Ligne
{

public:
	Ligne(int num);
	int getLigne() const;
	Liste& getListeArret() const;
	File& getSensFileAller() const;
	File& getSensFileRetour() const;

	void setLigne(int num);
	void setListeArret(Liste &listeArret);
	void setSensFileAller(File &sensFileAller);
	void setListeArret(File &sensFileAller);

private:
	int d_num;
	Liste *d_listeArret;
	File *d_fileSensAller;
	File *d_fileSensRetour;

};


#endif //PROJETTRAM_LIGNE_H