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


void lire(const std::string &nomFichier, std::vector<Ligne> &tabLigne)
{
    std::ifstream f(nomFichier.c_str());

    int nbLignes;
    char poubelle;

    f >> nbLignes;

    tabLigne.reserve(nbLignes);

    int indice = -1;

    while(!f.eof())
    {
        std::string s;

        f >> s;
        //std::cout << s << std::endl;

        if(s == "#L")
        {
            int numLigne ;
            f >> numLigne;
            Ligne *ligne = new Ligne(numLigne); // creation de la ligne avec son numero en param
            tabLigne.push_back(*ligne);
            indice++;
        }
        else if(s == "#A")
        {
            Arret *ar = new Arret();
            std::string libelle;
            int id, posx, posy,tempsArret;
            f >> id >>libelle >> posx >> posy >> tempsArret;
            ar->setIdArret(id);
            ar->setLibelle(libelle);
            ar->setPotistion(posx, posy);
            ar->setTempsArret(tempsArret); // On a stop ici
            tabLigne[indice].getListeArret().insererEnQueue(*ar); // ajout de l'arret en queue de liste
        }
        else if(s == "#T")
        {
            Tram *tr = new Tram;

            int vitTr;
            int posXTr;
            int posYTr;
            bool sensTr;
            int numLigneTr;

            f >> vitTr >> posXTr >> posYTr >> sensTr >> numLigneTr;

            if(tr->getSens())	// sens aller
            {
                tabLigne[indice].getSensFileAller().entrer(*tr);
            }
            else
            {
                tabLigne[indice].getSensFileRetour().entrer(*tr);
            }
        }
        else
        {
            std::cout << "error";
        }

    }

    std::cout << "Arrets : " << std::endl;


    Arret *arretCourant = new Arret();
    for(int i = 0; i < tabLigne[indice].getListeArret().getTaille(); i++)
    {
        arretCourant = tabLigne[indice].getListeArret().getTeteArret();
        std::cout << arretCourant->getIdArret() << " "
                  << arretCourant->getLibelle() << " "
                  << arretCourant->getPosition().getX() << " "
                  << arretCourant->getPosition().getY() << " "
                  << arretCourant->getTempsArret() << std::endl;

//        std::cout << tabLigne[indice].arrets[i].nomArret << " " << tabLigne[indice].arrets[i].posx << " " << tabLigne[indice].arrets[i].posy << " " << tabLigne[indice].arrets[i].tempsArret << std::endl;
    }
}


/*void lire(const std::string &nomFichier, std::vector<Ligne> &tabLigne)
{
    std::ifstream f(nomFichier);

    int nbLignes; 	// nombres de lignes du réseau, nécessaire à la création d'un tableau dynamique de lignes

    char p; 		// p pour poubelle

    f >> nbLignes;



    tabLigne.reserve(nbLignes);

    int indice = -1;
    int numeroLigne = 1;

    while(!f.eof())
    {
        std::string s;	// variable qui prend '#L", "#A" ou "#T" comme valeurs

        f >> s;

        if(s == "#L")
        {
            Ligne ligne;
            std::string tmp;
            f >> tmp;
            ligne.setLigne(std::atoi(tmp.c_str()));

            tabLigne.push_back(ligne);
            ++indice;
            ++numeroLigne;
        }

        else if( s == "#A")
        {
            Arret ar;

            std::string nomAr;
            int posXAr;
            int posYAr;
            int tpsAr;

            f >> nomAr >> posXAr >> posYAr >> tpsAr;

            ar.setLibelle(nomAr);
            ar.setPotistion(posXAr, posYAr);
            ar.setTempsArret(tpsAr);

            tabLigne[indice].getListeArret().insererEnQueue(ar);
        }

        else if(s == "#T")
        {
            Tram tr;

            int vitTr;
            int posXTr;
            int posYTr;
            bool sensTr;
            int numLigneTr;

            f >> vitTr >> posXTr >> posYTr >> sensTr >> numLigneTr;

            if(tr.getSens())	// sens aller
            {
                tabLigne[indice].getSensFileAller().entrer(tr);
            }
            else
            {
                tabLigne[indice].getSensFileRetour().entrer(tr);
            }
        }

        else
        {
            std::cout << "Erreur de lecture. Code d'erreur 0.";
        }
    }


}*/

/*void afficherReseau(const std::vector<Ligne> &tabLigne)
{
    for(int i = 0; i < tabLigne.size(); i++)
    {
        bar(tabLigne[i].arrets[0].posx-5, tabLigne[i].arrets[0].posy-5, tabLigne[i].arrets[0].posx+5, tabLigne[i].arrets[0].posy+5);

        for(int j = 1; j < tabLigne[i].arrets.size(); j++)
        {
            Arret arPrec = tabLigne[i].arrets[j-1];
            Arret arSuiv = tabLigne[i].arrets[j];

            line(arPrec.posx, arPrec.posy, arSuiv.posx, arSuiv.posy);

            bar(arSuiv.posx-5, arSuiv.posy-5, arSuiv.posx+5, arSuiv.posy+5);
            *//*
            std::cout << "arPrec x : " << arPrec.posx;
            std::cout << std::endl;
            std::cout << "arSuiv y : " << arSuiv.posy;
            *//*
        }
    }
}*/

int main() {

    std::vector<Ligne> tabDeLignes;

    std::string nomDeMonFichierDeTypeCsv = "structureFichier.txt";
    lire(nomDeMonFichierDeTypeCsv, tabDeLignes);


   /* opengraphsize(800, 500);

    //------------------- test
    //std::cout << "Taille de tabDeLignes : " << tabDeLignes.size() << std::endl;

    // ----------------------

    setcolor(RED);
    afficherReseau(tabDeLignes);

    // ------ déplacer un tram ---------
    int compteur = 20;
    Tram tr;
    tr.posx = 50;
    tr.posy = 50;

    while(compteur > 0)
    {
        deplacementTram(tr);
        --compteur;
    }

    getch();
    closegraph();*/



    std::cout << "Hello, World!" << std::endl;
    return 0;
}