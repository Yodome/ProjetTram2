#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include <ctime>

#include "../Headers/graphics.h"
#include <conio.h>

#include "../Headers/Arret.h"
#include "../Headers/File.h"
#include "../Headers/Ligne.h"
#include "../Headers/Liste.h"
#include "../Headers/Position.h"
#include "../Headers/Tram.h"


/**
 * Lit un fichier texte et stocke ses données
 * @param [in] nomFichier - chaine de caractère qui correspond au fichier à lire
 * @param [in] tabLigne - tableau de lignes
 */
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

    f.close();
}


//-------------------------------------- TEST -----------------------------------
/**
 * Affichage des informations sous forme textuelle, récoltées depuis le fichier texte et stockées dans les structures
 * @param [in] tabLigne - tableau de lignes
 */
void testAfficherLigne(std::vector<Ligne> &tabLigne)
{
    int indice = 0;
    for ( int j =0 ; j < tabLigne.size(); j++)
    {

        std::cout << "Arrets : " << std::endl;
        Arret *arretCourant ;      //On crée un nouvel arrêt pour pouvoir parcourir la liste d'arrêts sans perdre la tête
        arretCourant = tabLigne[j].getListeArret().getTeteArret(); //arretCourant = arret de tête
        for(int i = 0; i < tabLigne[j].getListeArret().getTaille(); i++)   //Pour i allant de la tête au dernier arrêt
        {

            std::cout << arretCourant->getIdArret() << " "      //On affiche les informations concernant cet arrêt
                      << arretCourant->getLibelle() << " "
                      << arretCourant->getPosition().getX() << " "
                      << arretCourant->getPosition().getY() << " "
                      << arretCourant->getTempsArret() << std::endl;

            arretCourant = arretCourant->getArretSuivant();     //On passe à l'arrêt suivant
        }


        std::cout << "Trams : " << std::endl;

        Tram* tramCourant ;     //On crée un tram courant pour pouvoir parcourir la file de trams
        tramCourant = tabLigne[j].getFileRetour().getPremierTram(); //tramCourant = premier tram (tête)
        for(int i = 0; i < tabLigne[j].getFileRetour().getTaille(); i++)    //Pour i allant de la tête au dernier tram
        {


            std::cout << tramCourant->getVitesse() << " "       //On affiche toutes les informations de ce tram
                      << tramCourant->getPosition().getX() << " "
                      << tramCourant->getPosition().getY() << " "
                      << tramCourant->getSens() << " "
                      << tramCourant->getNumLigne() << " "
                      << tramCourant->getNumArretSuivant() <<  std::endl;
            tramCourant = tramCourant->getTramSuivant();    //On passe au tram suivant
        }
    }
    indice ++ ;
}

/**
 * Affichage des arrêts et des voies qui les relient
 * @param [in] tabDeLignes - tableau de lignes
 */
void afficherReseau(const std::vector<Ligne> &tabDeLignes)
{
    setcolor(RED);
    for(int i = 0; i < tabDeLignes.size(); i++)     // Pour i allant de la première ligne à la dernière
    {
        Arret * arCrt = tabDeLignes[i].getListeArret().getTeteArret();  //On crée un arrêt courant = tête arrêt

        for(int j = 0; j < tabDeLignes[i].getListeArret().getTaille(); j++)     //Pour j allant du premier arrêt au dernier
        {
            bar(arCrt->getPosition().getX()-7, arCrt->getPosition().getY()-7,   //On dessine un rectangle de 5x5 pour représenter l'arrêt et on le place à la bonne position
                arCrt->getPosition().getX()+7, arCrt->getPosition().getY()+7);

            if(arCrt->getArretSuivant() != 0)      //Si on n'est pas à la queue (si il y a encore un arrêt après)
            {
                line(arCrt->getPosition().getX(), arCrt->getPosition().getY(),      //On trace une ligne qui relie les deux arrêts (actuel et suivant)
                     arCrt->getArretSuivant()->getPosition().getX(), arCrt->getArretSuivant()->getPosition().getY());
            }

            arCrt = arCrt->getArretSuivant();   //On passe à l'arrêt suivant
        }

    }
}

/**
 * Affichage des trams sur le réseau
 * @param [in] tabDeLignes - tableau de lignes
 */
void afficherTrams(const std::vector<Ligne> &tabDeLignes)
{

    for(int i = 0; i < tabDeLignes.size(); i++) //Pour i allant de la première ligne à la dernière
    {
        setcolor(GREEN);
        Tram * trCrtAller = tabDeLignes[i].getFileAller().getPremierTram(); //On crée un tram courant pour le sens aller = tête tram aller
        Tram * trCrtRetour = tabDeLignes[i].getFileRetour().getPremierTram();   //On crée un tram courant pour le sens retour = tête tram retour

        for(int j = 0; j < tabDeLignes[i].getFileAller().getTaille(); j++)  //Pour j allant du premier tram de la file aller au dernier
        {
            circle(trCrtAller->getPosition().getX(), trCrtAller->getPosition().getY(), 8); //On dessine un cercle de rayon 10 pour le représenter et on le place à la bonne position
            floodfill(trCrtAller->getPosition().getX(), trCrtAller->getPosition().getY(),GREEN);
            trCrtAller = trCrtAller->getTramSuivant();  //On passe au tram suivant
        }

        for(int j = 0; j < tabDeLignes[i].getFileRetour().getTaille(); j++) //Pour j allant du premier tram de la file retour au dernier
        {
            setcolor(BLUE);
            circle(trCrtRetour->getPosition().getX(), trCrtRetour->getPosition().getY(), 8);   //On dessine un cercle de rayon 10 et on le place à la bonne position
            floodfill(trCrtRetour->getPosition().getX(), trCrtRetour->getPosition().getY(),BLUE);
            trCrtRetour = trCrtRetour->getTramSuivant();    //On passe au tram suivant
        }
    }
}

/**
 * Efface l'écran et réaffiche le réseau d'arrêts et les trams
 * @param [in] tabDeLignes - tableau de lignes
 */
void reaffichage(const std::vector<Ligne> &tabDeLignes)
{
    cleardevice();
    afficherReseau(tabDeLignes);
    afficherTrams(tabDeLignes);
}

/**
 * Modifie l'arrêt suivant d'un tram
 * @param [in, out] tabDeLignes - tableau de lignes
 * @param [in] tr - tram sur lequel on veut modifier son arrêt suivant
 */
void changerArretSuivantTram(std::vector<Ligne> &tabDeLignes, Tram &tr)
{
    if(tr.getPosition().getX() == tr.getArretSuivant()->getPosition().getX() && // si le tram est sur son arrêt suivant et qu'il est dans le sens retour ( gauche - droite )
       tr.getPosition().getY() == tr.getArretSuivant()->getPosition().getY() &&
       tr.getArretSuivant()->getArretSuivant() != nullptr &&
       !tr.getSens())
    {
        if ( tr.getPosition().getX() == tabDeLignes[0].getListeArret().getQueueArret()->getPosition().getX() && // si il est sur l'arret queue
                tr.getPosition().getY() == tabDeLignes[0].getListeArret().getQueueArret()->getPosition().getY())
        {
            tr.setArretSuivant(*tr.getArretSuivant()->getArretPrecedent()); // l'arret suivant du tram est l'arrêt précédent de l'arrêt sur lequel il se trouve
        }
        else
        {
            tr.setArretSuivant(*tr.getArretSuivant()->getArretSuivant()); // sinon c'est l'arrêt suivant
        }


    }
    else if ( tr.getPosition().getX() == tr.getArretSuivant()->getPosition().getX() && // idem mais pour le sens inverse
              tr.getPosition().getY() == tr.getArretSuivant()->getPosition().getY() &&
              tr.getArretSuivant()->getArretSuivant() != nullptr &&
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

/**
 * Change un tram de file
 * @param [in, out] tabDeLignes - tableau de lignes
 * @param [in] tr - tram qui doit changer de file
 */
void changerFileTram(std::vector<Ligne> &tabDeLignes, Tram &tr)
{

    if (&tr == tabDeLignes[0].getFileAller().getPremierTram() || &tr == tabDeLignes[0].getFileRetour().getPremierTram())
    {


        if (!tabDeLignes[0].getFileAller().estVide()) // si la file aller n'est pas vide
        {
            if (tabDeLignes[0].getFileAller().getPremierTram()->getPosition().getX() ==
                // le tram se trouve sur l'arrêt tête
                tabDeLignes[0].getListeArret().getTeteArret()->getPosition().getX() &&
                tabDeLignes[0].getFileAller().getPremierTram()->getPosition().getY() ==
                tabDeLignes[0].getListeArret().getTeteArret()->getPosition().getY())
            {
                Tram *t = tabDeLignes[0].getFileAller().getPremierTram(); // on récupère le premier tram de la file aller
                tabDeLignes[0].changerFile(*t); // on le change de file
                tabDeLignes[0].getFileRetour().getDernierTram()->setSens(
                        !tabDeLignes[0].getFileRetour().getDernierTram()->getSens()); // on actualise le sens du tram
// changer le getPremier tram ca faux
            }
        }
        if (!tabDeLignes[0].getFileRetour().estVide()) // idem mais pour le sens inverse
        {
            if (tabDeLignes[0].getFileRetour().getPremierTram()->getPosition().getX() ==
                tabDeLignes[0].getListeArret().getQueueArret()->getPosition().getX() &&
                tabDeLignes[0].getFileRetour().getPremierTram()->getPosition().getY() ==
                tabDeLignes[0].getListeArret().getQueueArret()->getPosition().getY())
            {
                Tram *t = tabDeLignes[0].getFileRetour().getPremierTram();
                tabDeLignes[0].changerFile(*t);
                tabDeLignes[0].getFileAller().getDernierTram()->setSens(
                        !tabDeLignes[0].getFileAller().getDernierTram()->getSens());
            }
        }
    }

}

/**
 * Fait bouger le tram sur la ligne
 * @param [in] tabDeLignes - tableau de lignes
 */
void mouvementsTrams(std::vector<Ligne> &tabDeLignes)
{

    if(!tabDeLignes[0].getFileAller().estVide()) // si file aller non vide
    {
        for(int i = 0; i < tabDeLignes[0].getFileAller().getTaille(); i++)
        {

            if ( tabDeLignes[0].getFileAller()[i]->getArretSuivant() == nullptr) // si l'arrêt suivant du premier tram est nul
            {
                tabDeLignes[0].getFileAller()[i]->setArretSuivant(*tabDeLignes[0].getListeArret().getQueueArret()->getArretPrecedent()); // son arrêt suivant est l'arrêt précédent de queue
            }
            tabDeLignes[0].getFileAller()[i]->avance(); // on prend le premier tram de la file


            if(tabDeLignes[0].getFileAller()[i]->doitSArreter()) // si le premier tram de la file  doit s'arrêter
            {
                tabDeLignes[0].getFileAller()[i]->arret(); // le tram passe à l'arrêt
                tabDeLignes[0].getFileAller()[i]->setTempsArret(
                        tabDeLignes[0].getFileAller()[i]->getArretSuivant()->getTempsArret()+time(NULL)); // on modifie son temps d'arrêt au temps de l'arrêt + le temps actuel

            }

            if(tabDeLignes[0].getFileAller()[i]->getTempsArret() < time(NULL)) // si le temps d'arret du tram est inférieur au temsp actuel
            {
                tabDeLignes[0].getFileAller()[i]->setVitesse(true); // le tram avance de nouveau
            }

            changerArretSuivantTram(tabDeLignes,*tabDeLignes[0].getFileAller()[i]); // actualisation de son arrêt suivant
            changerFileTram(tabDeLignes,*tabDeLignes[0].getFileAller()[i]); // on change le tram de file
        }
    }
    if(!tabDeLignes[0].getFileRetour().estVide()) // si file retour non vide
    {
        for(int i = 0 ; i < tabDeLignes[0].getFileRetour().getTaille(); i++)
        {

            if ( tabDeLignes[0].getFileRetour()[i]->getArretSuivant() == nullptr) // si l'arrêt suivant du premier tram est nul
            {
                tabDeLignes[0].getFileRetour()[i]->setArretSuivant(*tabDeLignes[0].getListeArret().getTeteArret()->getArretSuivant()); // son arrêt suivant est l'arrêt précédent de queue
            }

            tabDeLignes[0].getFileRetour()[i]->avance(); // on prend le premier tram de la file

            if(tabDeLignes[0].getFileRetour()[i]->doitSArreter()) // si le premier tram de la file  doit s'arrêter
            {
                tabDeLignes[0].getFileRetour()[i]->arret(); // le tram passe à l'arrêt
                tabDeLignes[0].getFileRetour()[i]->setTempsArret(
                        tabDeLignes[0].getFileRetour()[i]->getArretSuivant()->getTempsArret()+time(NULL)); // on modifie son temps d'arrêt au temps de l'arrêt + le temps actuel

            }

            if(tabDeLignes[0].getFileRetour()[i]->getTempsArret() < time(NULL)) // si le temps d'arret du tram est inférieur au temsp actuel
            {
                tabDeLignes[0].getFileRetour()[i]->setVitesse(true); // le tram avance de nouveau
            }

            changerArretSuivantTram(tabDeLignes,*tabDeLignes[0].getFileRetour()[i]);
            changerFileTram(tabDeLignes,*tabDeLignes[0].getFileRetour()[i]);
        }
    }



    reaffichage(tabDeLignes);
}




int main() {

    std::vector<Ligne> tabDeLignes;

    std::string nomDeMonFichierDeTypeCsv = "structureFichier.txt";
    lire(nomDeMonFichierDeTypeCsv, tabDeLignes);


    testAfficherLigne(tabDeLignes);

    opengraphsize(800, 500);

    setbkcolor(WHITE);

    int temps = time(NULL) + 20;

    while(time(NULL) < temps)
    {
        //setcolor(RED);
        afficherReseau(tabDeLignes);
        //setcolor(GREEN);
        afficherTrams(tabDeLignes);
        mouvementsTrams(tabDeLignes);




        Sleep(20);
    }


    std::cout << "FINI" << std::endl;


    getch();
    closegraph();
   // tabDeLignes[0].~Ligne();



    std::cout << "Hello, World!" << std::endl;


}