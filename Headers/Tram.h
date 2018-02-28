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

    //getter
    bool getVitesse() const ;
    int getVitessemax() const ;
    bool getSens() const ;
    int getTempsArret() const ;
    int getDistanceMin() const ;
    int getNumLigne() const ;
    Position getPosition() ;
    Tram& getTramSuivant() const ;
    Arret& getArretSuivant() const ;

    //setter
    void setVitesse(bool vitesse)  ;
    void setVitessemax(int vitesseMax)  ;
    void setSens(bool sens)  ;
    void setTempsArret(int tempsArret)  ;
    void setDistanceMin(int distanceMin)  ;
    void setNumLigne(int numLigne)  ;
    void setPosition(int x, int y) ;
    void setTramSuivant(Tram& tramSuivant)  ;
    void setArretSuivant(Arret& arretSuivant)  ;

private:
    bool d_vitesse;
    int d_vitesseMax;
    bool d_sens;
    int d_tempsArret;
    int d_distanceMin;
    int d_numLigne;
    Position d_position;
    Tram *d_tramSuiv;
    Arret *d_arretSuiv;//friend, on veut juste avoir le prochain
};


#endif //PROJETTRAM_TRAM_H