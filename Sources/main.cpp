#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>

#include "../Headers/graphics.h"
#include<conio.h>

#include "../Headers/Arret.h"
#include "../Headers/File.h"
#include "../Headers/Ligne.h"
#include "../Headers/Liste.h"
#include "../Headers/Position.h"
#include "../Headers/Tram.h"


//void lire(const std::string &nomFichier, std::vector<Ligne> &tab)
//{
//    std::ifstream f(nomFichier.c_str());
//
//    int nbLignes;
//    char poubelle;
//
//    f >> nbLignes;
//
//    tab.reserve(nbLignes);
//
//    int indice = -1;
//
//    while(!f.eof())
//    {
//        std::string s;
//
//        f >> s;
//        //std::cout << s << std::endl;
//
//        if(s == "#L")
//        {
//            int numLigne ;
//            f >> numLigne;
//            Ligne *ligne = new Ligne(numLigne);
//            tab.push_back(*ligne);
//            indice++;
//        }
//        else if(s == "#A")
//        {
//            Arret *ar = new Arret();
//            std::string libelle;
//            int posx, posy,tempsArret;
//            f >> libelle >> posx >> posy >> tempsArret;
//            ar->setLibelle(libelle);
//            ar->setPotistion(posx, posy);
//            ar->setTempsArret(tempsArret); // On a stop ici
//            tab[indice].arrets.push_back(ar);
//        }
//        else if(s == "#T")
//        {
//            Tram tr;
//            f >> tr.vitesse >> tr.posx >> tr.posy >> tr.sens >> tr.numeroLigne;
//            tab[indice].trams.push_back(tr);
//        }
//        else
//        {
//            std::cout << "error";
//        }
//
//    }
//
//    std::cout << "Arrets : " << std::endl;
//
//    for(int i = 0; i < tab[indice].arrets.size(); i++)
//    {
//        std::cout << tab[indice].arrets[i].nomArret << " " << tab[indice].arrets[i].posx << " " << tab[indice].arrets[i].posy << " " << tab[indice].arrets[i].tempsArret << std::endl;
//    }
//}
//
//
//void afficherReseau(const std::vector<Ligne> &tab)
//{
//    for(int i = 0; i < tab.size(); i++)
//    {
//        bar(tab[i].arrets[0].posx-5, tab[i].arrets[0].posy-5, tab[i].arrets[0].posx+5, tab[i].arrets[0].posy+5);
//
//        for(int j = 1; j < tab[i].arrets.size(); j++)
//        {
//            Arret arPrec = tab[i].arrets[j-1];
//            Arret arSuiv = tab[i].arrets[j];
//
//            line(arPrec.posx, arPrec.posy, arSuiv.posx, arSuiv.posy);
//
//            bar(arSuiv.posx-5, arSuiv.posy-5, arSuiv.posx+5, arSuiv.posy+5);
//            /*
//            std::cout << "arPrec x : " << arPrec.posx;
//            std::cout << std::endl;
//            std::cout << "arSuiv y : " << arSuiv.posy;
//            */
//        }
//    }
//}

int main() {

//    std::vector<Ligne> tabDeLignes;
//
//    std::string nomDeMonFichierDeTypeCsv = "structureFichier.txt";
//    lire(nomDeMonFichierDeTypeCsv, tabDeLignes);
//
//
//    opengraphsize(800, 500);
//
//    //------------------- test
//    //std::cout << "Taille de tabDeLignes : " << tabDeLignes.size() << std::endl;
//
//    // ----------------------
//
//    setcolor(RED);
//    afficherReseau(tabDeLignes);
//
//    // ------ déplacer un tram ---------
//    int compteur = 20;
//    Tram tr;
//    tr.posx = 50;
//    tr.posy = 50;
//
//    while(compteur > 0)
//    {
//        deplacementTram(tr);
//        --compteur;
//    }
//
//    getch();
//    closegraph();



    std::cout << "Hello, World!" << std::endl;
    return 0;
}