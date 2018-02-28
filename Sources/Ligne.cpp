//
// Created by e1701567 on 20/02/2018.
//

#include "../Headers/Ligne.h"

Ligne::Ligne(int num) : d_num {num}, d_listeArret{nullptr}, d_fileSensAller{nullptr},
                        d_fileSensRetour{nullptr}
{

}

int Ligne::getLigne() const
{
    return d_num;
}

Liste &Ligne::getListeArret() const
{
    return *d_listeArret;
}

File &Ligne::getSensFileAller() const
{
    return *d_fileSensAller;
}

File &Ligne::getSensFileRetour() const
{
    return *d_fileSensRetour;
}




void Ligne::setLigne(int num) {
    d_num = num;
}

void Ligne::setListeArret(Liste &listeArret) {
    *d_listeArret = listeArret;
}

void Ligne::setSensFileAller(File &sensFileAller) {
    *d_fileSensAller = sensFileAller;
}

void Ligne::setListeArret(File &sensFileRetour) {
    *d_fileSensRetour = sensFileRetour;
}





