//
// Created by e1701567 on 20/02/2018.
//

#include "../Headers/File.h"

File::File() : d_premierTram{nullptr} , d_dernierTram{nullptr}{

}

Tram &File::getPremierTram() const
{
    return *d_premierTram;
}

Tram &File::getDernierTram() const
{
    return *d_dernierTram;
}




void File::setPremierTram(Tram &premierTram)
{
    *d_premierTram = premierTram;
}

void File::setDernierTram(Tram &dernierTram)
{
    *d_dernierTram = dernierTram;
}






