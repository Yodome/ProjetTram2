//
// Created by e1701567 on 20/02/2018.
//

#include "..\Headers\Liste.h"

Liste::Liste() : d_arretTete{ nullptr }, d_arretQueue{ nullptr }
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

void Liste::insererEnQueue()
{
	Arret *ar = new Arret();
	ar->d_arretPrec = d_arretQueue;
	d_arretQueue->d_arretSuiv = ar;
	ar->d_arretSuiv = 0;
	d_arretQueue = ar;
}
