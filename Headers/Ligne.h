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
    // constructeur de la ligne avec des paramètres
	Ligne(int num);


    ~Ligne();

    //------------------- GETTER ---------------------
    // Renvoie le numéro de la ligne
	int getLigne() const;

    // Renvoie la liste des arrêts de la ligne
	Liste& getListeArret() const;

    // Renvoie la file de tram dans le sens aller
	File& getFileAller() const;

    // Renvoie la file de tram dans le sens retour
	File& getFileRetour() const;


    //------------------- SETTER ---------------------
    // Modifie le numéro de la ligne
	void setLigne(int num);

    // Modifie la liste des arrêts de la ligne
	void setListeArret(Liste *listeArret);

    // Modifie la file de tram de l'aller
	void setSensFileAller(File *sensFileAller);

    // Modifie la file de tram du retour
	void setSensFileRetour(File *sensFileRetour);

	//Change un tram de file sur une même ligne
	void changerFile(Tram &tr);

private:
	int d_num; // numéro de la ligne
	Liste *d_listeArret; // liste des arrêts de la ligne
	File *d_fileSensAller; // file de tram dans le sens aller
	File *d_fileSensRetour; // file de tram dans le sens retour

};


#endif //PROJETTRAM_LIGNE_H
