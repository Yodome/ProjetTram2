//
// Created by e1701567 on 20/02/2018.
//

#include "..\Headers\Ligne.h"


/**
 * Constructeur de ligne avec des paramètres
 * @param [in] num - numéro de la ligne
 */
Ligne::Ligne(int num) : d_num{ num }, d_listeArret{ nullptr }, d_fileSensAller{ nullptr },
d_fileSensRetour{ nullptr }
{

}

//--------------------------------- GETTER -------------------------------
/**
 * Renvoie le numéro de la ligne
 * @return d_num - numéro de la ligne
 */
int Ligne::getLigne() const
{
	return d_num;
}

/**
 * Renvoie la liste des arrêts de la ligne
 * @return d_listeArret - la liste de tous les arrêts de la ligne
 */
Liste &Ligne::getListeArret() const
{
	return *d_listeArret;
}

/**
 * Renvoie la file de tram dans le sens aller
 * @return d_fileSensAller - file de tram du sens aller
 */
File &Ligne::getFileAller() const
{
	return *d_fileSensAller;
}

/**
 * Renvoie la file de tram dans le sens retour
 * @return d_fileSensRetour - file de tram du sens retour
 */
File &Ligne::getFileRetour() const
{
	return *d_fileSensRetour;
}


//--------------------------------- SETTER -------------------------------
/**
 * Modifie le numéro de la ligne
 * @param [in] num - numéro de la ligne
 */
void Ligne::setLigne(int num) {
	d_num = num;
}

/**
 * Modifie la liste des arrêts de la ligne
 * @param [in] listeArret - nouvelle liste d'arrêt
 */
void Ligne::setListeArret(Liste *listeArret) {
	d_listeArret = listeArret;
}

/**
 * Modifie la file de tram de l'aller
 * @param [in] sensFileAller - nouvelle file de tram pour le sens aller
 */
void Ligne::setSensFileAller(File *sensFileAller) {
	d_fileSensAller = sensFileAller;
}

/**
 * Modifie la file de tram du retour
 * @param [in] sensFileRetour - nouvelle file de tram pour le sens retour
 */
void Ligne::setSensFileRetour(File *sensFileRetour) {
	d_fileSensRetour = sensFileRetour;
}

void Ligne::changerFile(Tram &tr) {
	if(tr.getSens())
	{
		getFileRetour().entrer(getFileAller().sortir());
	}
	if(!tr.getSens())
	{
		getFileAller().entrer(getFileRetour().sortir());
	}
}
