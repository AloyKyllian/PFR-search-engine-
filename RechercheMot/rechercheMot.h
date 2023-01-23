#ifndef RECHERCHEMOT_H
#define RECHERCHEMOT_H
#include "../Gestion-Config/Global.h"
#include "../comparaison/comparaison.h"

void rechercheMot(char *mot, char *chemin, tab_similaire *tabResultat, int nb_mot, int *nbElTab, int *erreur);
#endif