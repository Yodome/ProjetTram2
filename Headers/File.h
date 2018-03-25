#ifndef PROJETTRAM_FILE_H
#define PROJETTRAM_FILE_H


#include "Tram.h"

class File
{
public:
	// Constructeur par défaut
	File();
	// Destructeur --> appel de sortir() tant que la file !estVide()
	~File();
	// Renvoie le premier tram
	Tram * getPremierTram() const;
	// Renvoie le dernier tram
	Tram * getDernierTram() const;

	// Modifie le premier tram
	void setPremierTram(Tram& premierTram);
	// Modifie le dernier tram
	void setDernierTram(Tram& dernierTram);

	// Retourne la taille de la file
	int getTaille() const;

	// Permet d'entrer un tram tr dans la file en dernier
	void entrer(Tram &tr);
	// Fait sortir le tram en tête de la file
	Tram& sortir();
	// Retourne vrai si la file est vide --> si tete == queue
	bool estVide() const;

    Tram* operator[](int n) const;

    double distanceTramDevant(Tram &tr) const;

private:
	int d_taille;	// taille de la file
	Tram * d_premierTram;	// pointeur sur le premier tram
	Tram *d_dernierTram;	// pointeur sur le dernier tram
};


#endif //PROJETTRAM_FILE_H