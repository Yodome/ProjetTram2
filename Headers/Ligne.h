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
    Ligne( int num );

private:
    int d_num;
    Liste *d_listeArret;
    File *d_fileSens1;
    File *d_fileSens2;

};


#endif //PROJETTRAM_LIGNE_H
