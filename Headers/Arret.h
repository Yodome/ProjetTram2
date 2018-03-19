//
// Created by e1701567 on 20/02/2018.
//

#ifndef PROJETTRAM_ARRET_H
#define PROJETTRAM_ARRET_H


#include <string>
#include "Position.h"


class Arret
{
public:
    // Constructeur par défaut
	Arret();

    // Constructeur avec données en paramètre
	Arret(int idArret, int tempsArretMin, std::string libelle, Position pos);


    //------------------- GETTER ---------------------
	// Renvoie la position de l'arrêt
    Position& getPosition();

    // Renvoie le temps d'arret minimum sur l'arrêt
	int getTempsArret() const;

    // Renvoie le numéro de l'arrêt
    int getIdArret() const;

    // Renvoie le nom de l'arrêt
    std::string getLibelle() const;

    // Renvoie l'arrêt suivant
    Arret* getArretSuivant() const;

    // Renvoie l'arrêt précédent
    Arret* getArretPrecedent() const;


    //------------------- SETTER ---------------------
    // Modifie le nom de l'arrêt
    void setLibelle(std::string nom);

    // Modifie la position de l'arrêt
    void setPotistion(int x, int y);

    // Modifie le temsp d'arret minimum d'un tram sur l'arrêt
    void setTempsArret(int temps);

    // Modifie le numéro de l'arrêt
    void setIdArret(int id);


    double distanceArretSuivant() const;
    double distanceArretPrecedent() const;


	friend class Liste;
private:
    int d_idArret; // numéro de l'arrêt
	int d_tempsArretMin; // temps d'arret minimum d'un tram sur l'arrêt
	std::string d_libelle; // nom de l'arrêt
	Position d_position; // position de l'arrêt
	Arret *d_arretSuiv; // arrêt suivant dans la liste
	Arret *d_arretPrec; // arrêt précédent dans la liste

};


#endif //PROJETTRAM_ARRET_H