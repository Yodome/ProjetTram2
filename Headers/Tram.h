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


private:
    bool d_vitesse;
    bool d_sens;
    int d_tempsArret;
    int d_distanceMin;
    int d_vitesseMax;
    int d_numLigne;
    Position d_position;
    Tram *d_tramSuiv;
    Arret *d_arretSuiv;
};


#endif //PROJETTRAM_TRAM_H

