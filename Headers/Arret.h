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
    Arret();
    Position& getPosition() ;
    int getTempsArret() const;
    void setLibelle(std::string nom);
    void setPotistion(int x, int y);
    void setTempsArret(int temps);


private:
    int d_tempsArretMin;
    std::string d_libelle;
    Position d_position;
    Arret *d_arretSuiv;
    Arret *d_arretPrec;

};


#endif //PROJETTRAM_ARRET_H