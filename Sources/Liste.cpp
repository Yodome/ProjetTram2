//
// Created by e1701567 on 20/02/2018.
//

#include "..\Headers\Liste.h"

Liste::Liste() : d_taille{0}, d_arretTete{ nullptr }, d_arretQueue{ nullptr }
{}

Liste::Liste(Liste & l)
{
	Arret *a2 = l.d_arretTete, *prec1 = 0, *a1 = 0;

	while (a2 != 0)
	{
		a1 = new Arret();
		
		if (prec1 != 0)
		{
			prec1->d_arretSuiv = a1;
			a1->d_arretPrec = prec1;
		}
		else
		{
			d_arretTete = a1;
		}

		a2 = a2->d_arretSuiv;
		prec1 = a1;
	}
}

Liste::~Liste()
{
    Arret * crt = getTeteArret()->d_arretSuiv;

    while(crt != 0)
    {
        if(crt->d_arretSuiv == 0)
        {
            delete crt;
        }
        else
        {
            delete crt->d_arretPrec;
            crt = crt->d_arretSuiv;
        }
    }
}

Arret * Liste::getTeteArret() const
{
	return d_arretTete;
}

Arret * Liste::getQueueArret() const
{
	return d_arretQueue;
}

void Liste::setTeteArret(Arret &arretTete)
{
	*d_arretTete = arretTete;
}

void Liste::setQueueArret(Arret &arretQueue)
{
    arretQueue.d_arretPrec = d_arretQueue; // le precedent du nouveau chainon pointe vers la queue de liste
    d_arretQueue->d_arretSuiv = &arretQueue; // le chainon ar devient la queue
    arretQueue.d_arretSuiv = 0;
    d_arretQueue = &arretQueue;
}

// A refaire (�a fait des erreurs)
void Liste::insererEnQueue(Arret& ar) // ajouter les exceptions
{
    if (this->estVide())
    {
        d_arretTete = &ar;
        d_arretQueue = &ar;

    }
    else
    {
        setQueueArret(ar);
    }
    d_taille++;
}

bool Liste::estVide() const
{
    return (d_arretTete == nullptr);
}

int Liste::getTaille() const
{
    return  d_taille;
}

Arret *Liste::getArret(int n) const
{
    Arret * crt = getTeteArret();

    while(crt != 0 && crt->getIdArret() != n)
    {
        crt = crt->getArretSuivant();
    }

    return crt;
}
