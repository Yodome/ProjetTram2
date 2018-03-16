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

            // Creation de la liste d'arrets
            Liste *listeArrets = new Liste();
            ligne->setListeArret(listeArrets);

            // Creation de la file de trams
            File *fileSensAllerTr = new File();
            File *fileSensRetourTr = new File();
            ligne->setSensFileAller(fileSensAllerTr);
            ligne->setSensFileRetour(fileSensRetourTr);

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
            ar->setTempsArret(tempsArret);
            tabLigne[indice].getListeArret().insererEnQueue(*ar); // ajout de l'arret en queue de liste
        }
        else if(s == "#T")
        {
            Tram *tr = new Tram;

            bool vitTr;
            int posXTr;
            int posYTr;
            bool sensTr;
            int numLigneTr;
            int numArretSuiv;

            f >> vitTr >> posXTr >> posYTr >> sensTr >> numLigneTr >> numArretSuiv;

            tr->setVitesse(vitTr);
            tr->setPosition(posXTr, posYTr);
            tr->setSens(sensTr);
            tr->setNumLigne(numLigneTr);
            tr->setNumArretSuivant( numArretSuiv);
            tr->setArretSuivant(*tabLigne[indice].getListeArret().getArret(numArretSuiv));


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
}


//-------------------------------------- TEST -----------------------------------
void testAfficherLigne(std::vector<Ligne> &tabLigne)
{
    int indice = 0;
    std::cout << "Arrets : " << std::endl;
    Arret *arretCourant = new Arret();
    arretCourant = tabLigne[indice].getListeArret().getTeteArret();
    for(int i = 0; i < tabLigne[indice].getListeArret().getTaille(); i++)
    {

        std::cout << arretCourant->getIdArret() << " "
                  << arretCourant->getLibelle() << " "
                  << arretCourant->getPosition().getX() << " "
                  << arretCourant->getPosition().getY() << " "
                  << arretCourant->getTempsArret() << std::endl;

//        std::cout << tabLigne[indice].arrets[i].nomArret << " " << tabLigne[indice].arrets[i].posx << " " << tabLigne[indice].arrets[i].posy << " " << tabLigne[indice].arrets[i].tempsArret << std::endl;
        arretCourant = arretCourant->getArretSuivant();
    }


    std::cout << "Trams : " << std::endl;

    Tram* tramCourant = new Tram();
    tramCourant = tabLigne[indice].getSensFileAller().getPremierTram();
    for(int i = 0; i < tabLigne[indice].getSensFileAller().getTaille(); i++)
    {


        std::cout << tramCourant->getVitesse() << " "
                  << tramCourant->getPosition().getX() << " "
                  << tramCourant->getPosition().getY() << " "
                  << tramCourant->getSens() << " "
                  << tramCourant->getNumLigne() << " "
                  << tramCourant->getNumArretSuivant() <<  std::endl;
        tramCourant = tramCourant->getTramSuivant();
    }
    indice ++ ;
}

void afficherReseau(const std::vector<Ligne> &tabDeLignes)
{
    for(int i = 0; i < tabDeLignes.size(); i++)
    {
        Arret * arCrt = tabDeLignes[i].getListeArret().getTeteArret();

        for(int j = 0; j < tabDeLignes[i].getListeArret().getTaille(); j++)
        {
            bar(arCrt->getPosition().getX()-5, arCrt->getPosition().getY()-5,
                arCrt->getPosition().getX()+5, arCrt->getPosition().getY()+5);

            if(arCrt->getArretSuivant() != 0)
            {
                line(arCrt->getPosition().getX(), arCrt->getPosition().getY(),
                     arCrt->getArretSuivant()->getPosition().getX(), arCrt->getArretSuivant()->getPosition().getY());
            }

            arCrt = arCrt->getArretSuivant();
        }

    }
}

void afficherTrams(const std::vector<Ligne> &tabDeLignes)
{
    for(int i = 0; i < tabDeLignes.size(); i++)
    {
        Tram * trCrtAller = tabDeLignes[i].getSensFileAller().getPremierTram();
        Tram * trCrtRetour = tabDeLignes[i].getSensFileRetour().getPremierTram();

        for(int j = 0; j < tabDeLignes[i].getSensFileAller().getTaille(); j++)
        {
            circle(trCrtAller->getPosition().getX(), trCrtAller->getPosition().getY(), 10);

            trCrtAller = trCrtAller->getTramSuivant();
        }

        for(int j = 0; j < tabDeLignes[i].getSensFileRetour().getTaille(); j++)
        {
            circle(trCrtRetour->getPosition().getX(), trCrtRetour->getPosition().getY(), 10);

            trCrtRetour = trCrtRetour->getTramSuivant();
        }
    }
}

void reaffichage(const std::vector<Ligne> &tabDeLignes)
{
    //cleardevice();
    afficherReseau(tabDeLignes);
    afficherTrams(tabDeLignes);
}

void mouvementsTrams(const std::vector<Ligne> &tabDeLignes)
{
    tabDeLignes[0].getSensFileAller().getPremierTram()->avance();
    reaffichage(tabDeLignes);
}



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
    testAfficherLigne(tabDeLignes);

    opengraphsize(800, 500);

    int compteur = 0;
    while(compteur != 100)
    {
        setcolor(RED);
        afficherReseau(tabDeLignes);
        setcolor(GREEN);
        afficherTrams(tabDeLignes);
        mouvementsTrams(tabDeLignes);

        Sleep(100);
        ++compteur;
    }


    getch();
    closegraph();



    std::cout << "Hello, World!" << std::endl;

    return 0;
}