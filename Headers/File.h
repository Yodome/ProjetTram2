#ifndef PROJETTRAM_FILE_H
#define PROJETTRAM_FILE_H


#include "Tram.h"

class File
{
public:
    File();
    Tram& getPremierTram() const;
    Tram& getDernierTram() const;

    void setPremierTram(Tram& premierTram);
    void setDernierTram(Tram& dernierTram);

private:
    Tram *d_premierTram;
    Tram *d_dernierTram;
};


#endif //PROJETTRAM_FILE_H