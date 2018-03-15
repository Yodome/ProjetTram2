#ifndef PROJETTRAM_FILE_H
#define PROJETTRAM_FILE_H


#include "Tram.h"

class File
{
public:
	File();
	~File();
	Tram * getPremierTram() const;
	Tram * getDernierTram() const;

	void setPremierTram(Tram& premierTram);
	void setDernierTram(Tram& dernierTram);

	int getTaille() const;

	void entrer(Tram &tr);
	Tram& sortir();
	bool estVide() const;

private:
	int d_taille;
	Tram * d_premierTram;
	Tram *d_dernierTram;
};


#endif //PROJETTRAM_FILE_H