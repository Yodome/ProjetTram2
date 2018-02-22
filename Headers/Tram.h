//
// Created by e1701567 on 20/02/2018.
//

#ifndef PROJETTRAM_TRAM_H
#define PROJETTRAM_TRAM_H


#include "Position.h"
#include "Arret.h"
#include "Ligne.h"

class Tram
{
public:


private:
    bool d_vitesse;
    bool d_sens;
    int d_tempsArret;
    int d_distanceMin;
    int d_vitesseMax;
    Position d_position;
    Tram *d_tramSuiv;
    Arret *d_arretSuiv;
    Ligne *d_ligne;
};


#endif //PROJETTRAM_TRAM_H

