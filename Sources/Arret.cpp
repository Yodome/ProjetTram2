//
// Created by e1701567 on 20/02/2018.
//

#include "..\Headers\Arret.h"


/**
 * Constructeur par défaut initialisant un arrêt
 */
Arret::Arret() :d_tempsArretMin{ 1000 }, d_libelle{ "" }, d_position{}, d_arretSuiv{ nullptr }, d_arretPrec{ nullptr }
{

}


/**
 * Constructeur initialisant un arrêt avec les paramètres qui lui sont donnés
 * @param [in] idArret - Numéro de l'arrêt
 * @param [in] tempsArretMin - temps d'arret minimum d'un tram sur l'arrêt
 * @param [in] libelle - Nom de l'arrêt
 * @param [in] pos - Position de l'arrêt dans la fenêtre
 */
Arret::Arret(int idArret, int tempsArretMin, std::string libelle, Position pos) :d_idArret{idArret} , d_tempsArretMin{tempsArretMin}, d_libelle{libelle}, d_position{pos}, d_arretSuiv{ nullptr }, d_arretPrec{ nullptr }
{

}


//--------------------------------- GETTER -------------------------------
/**
 * Renvoie la position de l'arrêt
 * @return d_position - position de l'arrêt
 */
Position &Arret::getPosition()
{
	return d_position.getPos();
}

/**
 * Renvoie le temps d'arrêt minimum d'un tram sur l'arrêt
 * @return  d_tempsArretMin - temps d'arrêt minimum
 */
int Arret::getTempsArret() const
{
	return d_tempsArretMin;
}

/**
 * Renvoie le nomde l'arrêt
 * @return d_libelle - nom de l'arrêt
 */
std::string Arret::getLibelle() const
{
    return d_libelle;
}

/**
 * Renvoie le numéro d'identification de l'arrêt
 * @return  d_idArret - identifiant de l'arrêt
 */
int Arret::getIdArret() const
{
    return d_idArret;
}

/**
 * Renvoie l'arrêt se trouvant après l'arrêt actuelle dans la ligne
 * @return d_arretSuiv - arrêt suivant sur la ligne
 */
Arret *Arret::getArretSuivant() const
{
    return d_arretSuiv;
}

/**
 * Renvoie l'arrêt se trouvant avant l'arrêt actuelle dans la ligne
 * @return d_arretPrec - arrêt précédent sur la ligne
 */
Arret *Arret::getArretPrecedent() const
{
    return d_arretPrec;
}


//--------------------------------- SETTER -------------------------------
/**
 * Modifie le nom de l'arrêt
 * @param [in] nom - nouveau nom de l'arrêt
 */
void Arret::setLibelle(std::string nom)
{
	d_libelle = nom;
}

/**
 * Modifie la position de l'arrêt
 * @param [in]  x - coordonnée en abscisse de l'arrêt
 * @param [in] y - coordonnée en ordonnée de l'arrêt
 */
void Arret::setPotistion(int x, int y)
{
	d_position.setPos(x, y);
}

/**
 * Modifie le temps d'arret minimum d'un tram sur l'arrêt
 * @param [in] temps - temps d'arret minimum
 */
void Arret::setTempsArret(int temps)
{
	d_tempsArretMin = temps;
}

/**
 * Modifie le numéro de l'arrêt
 * @param [in] id - numéro de l'arrêt
 */
void Arret::setIdArret(int id)
{
    d_idArret = id;
}

