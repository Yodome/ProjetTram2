//
// Created by e1701567 on 20/02/2018.
//

#include "..\Headers\Liste.h"

Liste::Liste() : d_taille{0}, d_arretTete{ nullptr }, d_arretQueue{ nullptr }   //Initialisation des variables privées par défaut (liste vide donc = 0 et pas de tete ni de queue)
{}

Liste::Liste(Liste & l) //Constructeur par recopie
{
	Arret *a2 = l.d_arretTete, *prec1 = 0, *a1 = 0;    //On crée un arrêt a2 qui va nous permettre de parcourir la liste passée en paramètre sans perdre la tête,
                                                       //on crée un arrêt prec1 qui sera le précédent et un arrêt a1 qui est l'arrêt courant dans la liste this

	while (a2 != 0)    //Tant que la tête n'est pas nulle
	{ 
		a1 = new Arret(); //On crée un nouvel arrêt
		
		if (prec1 != 0)   //Si le précédent n'est pas nul
		{
			prec1->d_arretSuiv = a1; //le suivant de précédent devient a1
			a1->d_arretPrec = prec1; //le précédent de a1 devient prec1
		}
		else  //Sinon 
		{
			d_arretTete = a1;    //a1 devient la tête
		}

		a2 = a2->d_arretSuiv;     //On passe à l'arrêt suivant
		prec1 = a1;       //le précédent de a1 devient a1
	}
}

Liste::~Liste()     //Destructeur
{
    Arret * crt = getTeteArret()->d_arretSuiv;  //On crée un arrêt courant

    while(crt != 0)     //Tant que cet arrêt n'est pas nul
    {
        if(crt->d_arretSuiv == 0)   //Si l'arrêt suivant est nul
        {
            delete crt; //On supprime l'arrêt courant
        }
        else    //Sinon
        {
            delete crt->d_arretPrec;    //On supprime l'arrêt précédent 
            crt = crt->d_arretSuiv;     //On avance l'arrêt courant
        }
    }
}

Arret * Liste::getTeteArret() const
{
	return d_arretTete;    //Retourne l'arrêt de tête
}

Arret * Liste::getQueueArret() const
{
	return d_arretQueue;   //Retourne l'arrêt de queue
}

void Liste::setTeteArret(Arret &arretTete)
{
	*d_arretTete = arretTete;  //Modifie l'arrêt de tête par celui passé en paramètre
}

void Liste::setQueueArret(Arret &arretQueue)
{
    arretQueue.d_arretPrec = d_arretQueue; //Le précédent de l'arrêt passé en paramètre pointe vers la queue de la liste
    d_arretQueue->d_arretSuiv = &arretQueue; // Le suivant de l'ancienne queue devient l'arrêt passé en paramètre
    arretQueue.d_arretSuiv = 0; //Le suivant de la queue est nul
    d_arretQueue = &arretQueue; //La nouvelle queue devient celle passée en paramètre
}

// A refaire (�a fait des erreurs)
void Liste::insererEnQueue(Arret& ar) // ajouter les exceptions
{
    if (this->estVide())    //Si la liste d'arrêts courant est vide
    {
        d_arretTete = &ar;  //Alors la tête et la queue pointent sur l'arrêt passé en paramètre
        d_arretQueue = &ar;

    }
    else    //Sinon
    {
        setQueueArret(ar);  //l'arrêt passé en paramètre devient la queue
    }
    d_taille++;     //On incrémente la taille de la liste d'arrêts
}

bool Liste::estVide() const
{
    return (d_arretTete == nullptr);    //renvoie vrai si la liste est vide
}

int Liste::getTaille() const
{
    return  d_taille;   //Renvoie la taille de la liste d'arrêts
}

Arret *Liste::getArret(int n) const     //Renvoie un arrêt en fonction de son numéro
{
    Arret * crt = getTeteArret();   //On crée un arrêt courant pour parcourir la liste sans perdre la tête

    while(crt != 0 && crt->getIdArret() != n)   //tant que nous ne sommes pas arrivés à la queue et que le numéro ne correspond pas à celui passé en paramètre
    {
        crt = crt->getArretSuivant();   //On avance dans la liste
    }

    return crt; //On retourne l'arrêt
}
