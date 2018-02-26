//
// Created by e1701567 on 20/02/2018.
//

#include "../Headers/Tram.h"

Tram::Tram() : d_vitesse {false}, d_sens{false}, d_tempsArret{1000}, d_distanceMin{100},
               d_vitesseMax{20}, d_position {}, d_tramSuiv{nullptr}, d_arretSuiv{nullptr},
               d_numLigne{0}
{

}
