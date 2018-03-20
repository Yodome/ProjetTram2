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
    std::ifstream f(nomFichier.c_str());    //Création de la variable du fichier

    int nbLignes;
    char poubelle;

    f >> nbLignes;  //On récupère le nombre de lignes de tram qu'il y a

    tabLigne.reserve(nbLignes);     //On réserve l'espace mémoire en fonction du nombre de lignes

    int indice = -1;

    while(!f.eof())     //Tant que ce n'est pas la fin du fichier ...
    {
        std::string s;

        f >> s;     //On met à la poubelle la première ligne car on l'a déjà au dessus
        //std::cout << s << std::endl;

        if(s == "#L")   //Si le début du ligne commence par #L (donc est une ligne)
        {
            int numLigne ;
            f >> numLigne;      //On récupère son numéro de ligne
            Ligne *ligne = new Ligne(numLigne); // creation de la ligne avec son numero en param

            // Creation de la liste d'arrets
            Liste *listeArrets = new Liste();
            ligne->setListeArret(listeArrets);  //On ajoute la liste d'arrêts à la ligne

            // Creation de la file de trams
            File *fileSensAllerTr = new File();
            File *fileSensRetourTr = new File();
            ligne->setSensFileAller(fileSensAllerTr);   //On ajoute la file de sens aller à la ligne
            ligne->setSensFileRetour(fileSensRetourTr); //On ajoute la file de sens retour à la ligne

            tabLigne.push_back(*ligne);     //On stocke la ligne dans le tableau de lignes
            indice++;
        }
        else if(s == "#A")  //Sinon si le début de ligne commence par #A (donc un arrêt) 
        {
            Arret *ar = new Arret();    //On crée un arrêt
            std::string libelle;    
            int id, posx, posy,tempsArret;  //On initialise des variables pour récupérer les informations
            f >> id >>libelle >> posx >> posy >> tempsArret; //On récupères les infos
            ar->setIdArret(id);     //On les stocke dans chaque variable 
            ar->setLibelle(libelle);
            ar->setPosition(posx, posy);
            ar->setTempsArret(tempsArret);
            tabLigne[indice].getListeArret().insererEnQueue(*ar); // Ajout de l'arret en queue de liste
        }
        else if(s == "#T")  //Sinon si le début de la ligne commence par #T (donc un tram)
        {
            Tram *tr = new Tram();    //On crée un nouveau tram

            bool vitTr;     //On initialise chaque variable pour récupérer les infos
            int posXTr;
            int posYTr;
            bool sensTr;
            int numLigneTr;
            int numArretSuiv;

            f >> vitTr >> posXTr >> posYTr >> sensTr >> numLigneTr >> numArretSuiv;     //On récupère les infos

            tr->setVitesse(vitTr);      //On stocke les infos dans les variables
            tr->setPosition(posXTr, posYTr);
            tr->setSens(sensTr);
            tr->setNumLigne(numLigneTr);
            tr->setNumArretSuivant( numArretSuiv);
            tr->setArretSuivant(*tabLigne[indice].getListeArret().getArret(numArretSuiv));


            if(tr->getSens())	// Si le sens est true alors sens aller
            {
                tabLigne[indice].getFileAller().entrer(*tr);
            }
            else    //Sinon sens retour
            {
                tabLigne[indice].getFileRetour().entrer(*tr);
            }
        }
        else    //Si on ne tombe sur aucun des cas précédents alors erreur
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
    Arret *arretCourant = new Arret();      //On crée un nouvel arrêt pour pouvoir parcourir la liste d'arrêts sans perdre la tête
    arretCourant = tabLigne[indice].getListeArret().getTeteArret(); //arretCourant = arret de tête
    for(int i = 0; i < tabLigne[indice].getListeArret().getTaille(); i++)   //Pour i allant de la tête au dernier arrêt
    {

        std::cout << arretCourant->getIdArret() << " "      //On affiche les informations concernant cet arrêt
                  << arretCourant->getLibelle() << " "
                  << arretCourant->getPosition().getX() << " "
                  << arretCourant->getPosition().getY() << " "
                  << arretCourant->getTempsArret() << std::endl;

//        std::cout << tabLigne[indice].arrets[i].nomArret << " " << tabLigne[indice].arrets[i].posx << " " << tabLigne[indice].arrets[i].posy << " " << tabLigne[indice].arrets[i].tempsArret << std::endl;
        arretCourant = arretCourant->getArretSuivant();     //On passe à l'arrêt suivant
    }


    std::cout << "Trams : " << std::endl;

    Tram* tramCourant = new Tram();     //On crée un tram courant pour pouvoir parcourir la file de trams
    tramCourant = tabLigne[indice].getFileRetour().getPremierTram(); //tramCourant = premier tram (tête)
    for(int i = 0; i < tabLigne[indice].getFileRetour().getTaille(); i++)    //Pour i allant de la tête au dernier tram
    {


        std::cout << tramCourant->getVitesse() << " "       //On affiche toutes les informations de ce tram
                  << tramCourant->getPosition().getX() << " "
                  << tramCourant->getPosition().getY() << " "
                  << tramCourant->getSens() << " "
                  << tramCourant->getNumLigne() << " "
                  << tramCourant->getNumArretSuivant() <<  std::endl;
        tramCourant = tramCourant->getTramSuivant();    //On passe au tram suivant
    }
    indice ++ ;
}

void afficherReseau(const std::vector<Ligne> &tabDeLignes)
{
    setcolor(RED);
    for(int i = 0; i < tabDeLignes.size(); i++)     // Pour i allant de la première ligne à la dernière
    {
        Arret * arCrt = tabDeLignes[i].getListeArret().getTeteArret();  //On crée un arrêt courant = tête arrêt

        for(int j = 0; j < tabDeLignes[i].getListeArret().getTaille(); j++)     //Pour j allant du premier arrêt au dernier
        {
            bar(arCrt->getPosition().getX()-5, arCrt->getPosition().getY()-5,   //On dessine un rectangle de 5x5 pour représenter l'arrêt et on le place à la bonne position
                arCrt->getPosition().getX()+5, arCrt->getPosition().getY()+5);

            if(arCrt->getArretSuivant() != 0)      //Si on n'est pas à la queue (si il y a encore un arrêt après)
            {
                line(arCrt->getPosition().getX(), arCrt->getPosition().getY(),      //On trace une ligne qui relie les deux arrêts (actuel et suivant)
                     arCrt->getArretSuivant()->getPosition().getX(), arCrt->getArretSuivant()->getPosition().getY());
            }

            arCrt = arCrt->getArretSuivant();   //On passe à l'arrêt suivant
        }

    }
}

void afficherTrams(const std::vector<Ligne> &tabDeLignes)
{
    setcolor(GREEN);
    for(int i = 0; i < tabDeLignes.size(); i++) //Pour i allant de la première ligne à la dernière
    {
        Tram * trCrtAller = tabDeLignes[i].getFileAller().getPremierTram(); //On crée un tram courant pour le sens aller = tête tram aller
        Tram * trCrtRetour = tabDeLignes[i].getFileRetour().getPremierTram();   //On crée un tram courant pour le sens retour = tête tram retour

        for(int j = 0; j < tabDeLignes[i].getFileAller().getTaille(); j++)  //Pour j allant du premier tram de la file aller au dernier
        {
            circle(trCrtAller->getPosition().getX(), trCrtAller->getPosition().getY(), 10); //On dessine un cercle de rayon 10 pour le représenter et on le place à la bonne position

            trCrtAller = trCrtAller->getTramSuivant();  //On passe au tram suivant
        }

        for(int j = 0; j < tabDeLignes[i].getFileRetour().getTaille(); j++) //Pour j allant du premier tram de la file retour au dernier
        {
            circle(trCrtRetour->getPosition().getX(), trCrtRetour->getPosition().getY(), 10);   //On dessine un cercle de rayon 10 et on le place à la bonne position

            trCrtRetour = trCrtRetour->getTramSuivant();    //On passe au tram suivant
        }
    }
}

void reaffichage(const std::vector<Ligne> &tabDeLignes)
{
    cleardevice();
    afficherReseau(tabDeLignes);
    afficherTrams(tabDeLignes);
}

void changerArretSuivantTram(std::vector<Ligne> &tabDeLignes, Tram &tr)
{
    if(tr.getPosition().getX() == tr.getArretSuivant()->getPosition().getX() &&
       tr.getPosition().getY() == tr.getArretSuivant()->getPosition().getY() &&
       tr.getArretSuivant()->getArretSuivant() != 0 &&
       !tr.getSens())
    {
        if ( tr.getPosition().getX() == tabDeLignes[0].getListeArret().getQueueArret()->getPosition().getX() &&
                tr.getPosition().getY() == tabDeLignes[0].getListeArret().getQueueArret()->getPosition().getY())
        {
            tr.setArretSuivant(*tr.getArretSuivant()->getArretPrecedent());
        }
        else
        {
            tr.setArretSuivant(*tr.getArretSuivant()->getArretSuivant());
        }


    }
    else if ( tr.getPosition().getX() == tr.getArretSuivant()->getPosition().getX() &&
              tr.getPosition().getY() == tr.getArretSuivant()->getPosition().getY() &&
              tr.getArretSuivant()->getArretSuivant() != 0 &&
              tr.getSens())
    {
        if ( tr.getPosition().getX() == tabDeLignes[0].getListeArret().getTeteArret()->getPosition().getX() &&
                tr.getPosition().getY() == tabDeLignes[0].getListeArret().getTeteArret()->getPosition().getY())
        {
            tr.setArretSuivant(*tr.getArretSuivant()->getArretSuivant());
        }
        else
        {
            tr.setArretSuivant(*tr.getArretSuivant()->getArretPrecedent());
        }

    }
}

void changerFileTram(std::vector<Ligne> &tabDeLignes, Tram &tr)
{
    if(!tabDeLignes[0].getFileAller().estVide()) // si
    {
        if(tabDeLignes[0].getFileAller().getPremierTram()->getPosition().getX() ==
           tabDeLignes[0].getListeArret().getTeteArret()->getPosition().getX() &&
           tabDeLignes[0].getFileAller().getPremierTram()->getPosition().getY() ==
           tabDeLignes[0].getListeArret().getTeteArret()->getPosition().getY())
        {
            Tram *tr=tabDeLignes[0].getFileAller().getPremierTram();
            tabDeLignes[0].changerFile(*tr);

        }
    }
    if(!tabDeLignes[0].getFileRetour().estVide())
    {
        if(tabDeLignes[0].getFileRetour().getPremierTram()->getPosition().getX() ==
           tabDeLignes[0].getListeArret().getQueueArret()->getPosition().getX() &&
           tabDeLignes[0].getFileRetour().getPremierTram()->getPosition().getY() ==
           tabDeLignes[0].getListeArret().getQueueArret()->getPosition().getY())
        {
            Tram *tr=tabDeLignes[0].getFileRetour().getPremierTram();
            tabDeLignes[0].changerFile(*tr);

        }
    }

}



void mouvementsTrams(std::vector<Ligne> &tabDeLignes)
{
    if(!tabDeLignes[0].getFileAller().estVide()) // si file aller non vide
    {
        if ( tabDeLignes[0].getFileAller().getPremierTram()->getArretSuivant() == nullptr) // si l'arrêt suivant du premier tram est nul
        {
            tabDeLignes[0].getFileAller().getPremierTram()->setArretSuivant(*tabDeLignes[0].getListeArret().getQueueArret()->getArretPrecedent()); // son arrêt suivant est l'arrêt précédent de queue
        }
        tabDeLignes[0].getFileAller().getPremierTram()->avance(); // on prend le premier tram de la file
        changerArretSuivantTram(tabDeLignes,*tabDeLignes[0].getFileAller().getPremierTram()); // actualisation de son arrêt suivant
        changerFileTram(tabDeLignes,*tabDeLignes[0].getFileAller().getPremierTram()); // on change le tram de file
    }
    if(!tabDeLignes[0].getFileRetour().estVide()) // si file retour non vide
    {
        tabDeLignes[0].getFileRetour().getPremierTram()->avance(); // on prend le premier tram de la file
        changerArretSuivantTram(tabDeLignes,*tabDeLignes[0].getFileRetour().getPremierTram());
        changerFileTram(tabDeLignes,*tabDeLignes[0].getFileRetour().getPremierTram());
    }



    reaffichage(tabDeLignes);
}




int main() {

    std::vector<Ligne> tabDeLignes;

    std::string nomDeMonFichierDeTypeCsv = "structureFichier.txt";
    lire(nomDeMonFichierDeTypeCsv, tabDeLignes);
    testAfficherLigne(tabDeLignes);

    opengraphsize(800, 500);


    int compteur = 500;
    while(compteur > 0)
    {
        //setcolor(RED);
        afficherReseau(tabDeLignes);
        //setcolor(GREEN);
        afficherTrams(tabDeLignes);
        mouvementsTrams(tabDeLignes);



        --compteur;
        Sleep(20);
    }


    getch();
    closegraph();



    std::cout << "Hello, World!" << std::endl;

    return 0;
}