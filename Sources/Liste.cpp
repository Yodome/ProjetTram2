//
// Created by e1701567 on 20/02/2018.
//

#include "../Headers/Liste.h"

Liste::Liste(): d_arretTete{nullptr}, d_arretQueue{nullptr}
{}

Arret &Liste::getTeteArret() const
{
    return *d_arretTete;
}

Arret &Liste::getQueueArret() const
{
    return *d_arretQueue;
}

void Liste::setTeteArret(Arret &arretTete)
{
    *d_arretTete = arretTete;
}

void Liste::setQueueArret(Arret &arretQueue)
{
    *d_arretQueue = arretQueue;
}
