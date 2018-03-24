//
// Created by e1701567 on 20/02/2018.
//

#include "..\Headers\Tram.h"
#include <cmath>
/**
 * Constructeur par défaut initialisant un tram
 */
Tram::Tram() : d_vitesse{ false }, d_sens{ false }, d_tempsArret{ 0 }, d_distanceMin{ 20 },
d_vitesseMax{ 20 }, d_position{}, d_tramSuiv{ nullptr }, d_arretSuiv{ nullptr },
d_numLigne{ 0 }, d_numArretSuiv { 0 }
{

}


//--------------------------------- GETTER -------------------------------
/**
 * Renvoie la vitesse actuelle du tram
 * @return vrai si le tram avance, faux sinon
 */
bool Tram::getVitesse() const
{
	return d_vitesse;
}

/**
 * Renvoie la vitesse maximale du tram
 * @return un entier indiquant la vitesse maximale du tram
 */
int Tram::getVitessemax() const
{
	return d_vitesseMax;
}

/**
 * Renvoie le sens du tram : 1 -> pour aller (gauche-droite), 0 -> pour retour (droite-gauche)
 * @return
 */
bool Tram::getSens() const
{
	return d_sens;
}

/**
 * Renvoie le temps d'arrêt du tram
 * @return entier indiquant le temps d'arrêt
 */
int Tram::getTempsArret() const
{
	return d_tempsArret;
}

/**
 * Distance minimale que le tram doit respecter
 * @return entier indiquant la distance minimale à respecter
 */
int Tram::getDistanceMin() const
{
	return d_distanceMin;
}

/**
 * Renvoie la ligne à laquelle le tram est affilié
 * @return entier indiquant la ligne sur laquelle le tram se trouve
 */
int Tram::getNumLigne() const
{
	return d_numLigne;
}

/**
 * Retourne la position du tram
 * @return un objet Position indiquant quelle est la position actuelle du tram courant
 */
Position Tram::getPosition()
{
	return d_position;
}

/**
 * Renvoie le tram suivant : celui qui est devant le tram courant
 * @return un pointeur sur le tram suivant dans la file
 */
Tram *Tram::getTramSuivant() const
{
	return d_tramSuiv;
}

/**
 * Renvoie l'arrêt vers lequelle le tram se dirige
 * @return un pointeur sur l'arrêt suivant
 */
Arret *Tram::getArretSuivant() const
{
	return d_arretSuiv;
}

/**
 * Renvoie le numéro de l'arrêt suivant
 * @return un entier indiquant le numéro de l'arrêt suivant
 */
int Tram::getNumArretSuivant() const
{
    return d_numArretSuiv;
}

//--------------------------------- SETTER -------------------------------
/**
 * Modifie la vitesse actuelle du tram
 * @param [in] vitesse - vitesse que le tram va prendre
 */
void Tram::setVitesse(bool vitesse)
{
	d_vitesse = vitesse;
}

/**
 * Modifie la vitesse maximale du tram
 * @param [in] vitesseMax - vitesse maximale que le tram aura
 */
void Tram::setVitessemax(int vitesseMax)
{
	d_vitesseMax = vitesseMax;
}

/**
 * Modifie le sens du tram
 * @param [in] sens - sens que le tram va prendre
 */
void Tram::setSens(bool sens)
{
	d_sens = sens;
}

/**
 * Modifie le temsp d'arrêt
 * @param [in] tempsArret - valeur du temsp d'arrêt du tram
 */
void Tram::setTempsArret(int tempsArret)
{
	d_tempsArret = tempsArret;
}

/**
 * Modifie la distance minimale que le tram doit respecter
 * @param [in] distanceMin - distance minimale que le tram devra respecter
 */
void Tram::setDistanceMin(int distanceMin)
{
	d_distanceMin = distanceMin;
}

/**
 * Modifie le numéro de ligne sur laquelle le tram se déplace
 * @param [in] numLigne - numéro de ligne
 */
void Tram::setNumLigne(int numLigne)
{
	d_numLigne = numLigne;
}

/**
 * Modifie la position du tram
 * @param [in] x - coordonnée x
 * @param [in] y - coordonnée y
 */
void Tram::setPosition(int x, int y)
{
	d_position.setPos(x, y);
}

/**
 * Modifie le pointeur sur le tram suivant
 * @param [in] tramSuivant - pointeur sur le tram suivant
 */
void Tram::setTramSuivant(Tram &tramSuivant)
{
	d_tramSuiv = &tramSuivant;
}

/**
 * Modifie l'arrêt vers lequel se dirige le tram
 * @param [in] arretSuivant - pointeur sur l'arrêt suivant
 */
void Tram::setArretSuivant(Arret &arretSuivant)
{
	d_arretSuiv = &arretSuivant;
}

/**
 * Modifie le numéro du prochain arrêt
 * @param [in] numArretSuivant - numéro du prochain arrêt
 */
void Tram::setNumArretSuivant(int numArretSuivant)
{
    d_numArretSuiv = numArretSuivant;
}

/**
 * Renvoie la distance avec le tram devant (le tram suivant dans la file)
 * @return reel indiquant la distance entre le tram courant et le tram suivant
 */
double Tram::distanceTramDevant() const
{
	return sqrt(pow( (d_tramSuiv->d_position.getX() - d_position.getX()), 2) + pow((d_tramSuiv->d_position.getY() - d_position.getY()), 2));
}


/**
 * Calcule la distance entre le tram et l'arrêt suivant
 * @return reel indiquant la distance avec l'arrêt suivant
 */
double Tram::distanceArretSuiv() const
{
	return sqrt(pow(d_arretSuiv->getPosition().getX() - d_position.getX(), 2) + pow(d_arretSuiv->getPosition().getY() - d_position.getY(), 2));
}

/**
 * Détermine les prochaines coordonnées du tram selon sa vitesse, et modifie sa Position en conséquence
 */
void Tram::avance()
{
    if(d_vitesse)
    {
        double ds = 0;

        if(getSens())
        {
            ds=d_arretSuiv->getArretSuivant()->distanceArretPrecedent();
        }
        else
        {
            ds=d_arretSuiv->getArretPrecedent()->distanceArretSuivant();
        }

        // distance � l'arret suivant
        double dt = distanceArretSuiv();

        // distance de l'arr�t selon la future position du tram

        dt = dt - d_vitesseMax;

        double a = (ds-dt) / ds;


        if ( dt < 0 )
        {
            d_position.setPos(d_arretSuiv->getPosition().getX(), d_arretSuiv->getPosition().getY());
        }
        else
        {
            if (!d_sens)
            {

                d_position.setPos((static_cast<int>((1 - a) * d_arretSuiv->getArretPrecedent()->getPosition().getX() +
                                                    a * d_arretSuiv->getPosition().getX())),
                                  (static_cast<int>((1 - a) * d_arretSuiv->getArretPrecedent()->getPosition().getY() +
                                                    a * d_arretSuiv->getPosition().getY())));
            }
            else
            {
                d_position.setPos((static_cast<int>((1 - a) * d_arretSuiv->getArretSuivant()->getPosition().getX() +
                                                    a * d_arretSuiv->getPosition().getX())),
                                  (static_cast<int>((1 - a) * d_arretSuiv->getArretSuivant()->getPosition().getY() +
                                                    a * d_arretSuiv->getPosition().getY())));
            }
        }
    }
    else
    {

    }
}

/**
 * Indique si le tram doit s'arrêter
 * @return un entier correspondant à la raison pour laquelle le tram doit s'arrêté
 */
bool Tram::doitSArreter()
{
    return  ( distanceArretSuiv()==0 /*|| distanceTramDevant() <= d_distanceMin*/);
}



/**
 * Permet de stopper le tram courant : met sa vitesse à nulle
 */
void Tram::arret()
{
	setVitesse(false);
}
