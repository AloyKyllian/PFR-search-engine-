#ifndef COMPARAISON_IMAGE_C
#define COMPARAISON_IMAGE_C
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int id;
    float pourcentage;
} tab_similaire;

tab_similaire* Comparaison_descripteur_image(int *Erreur, char PathRecueil[], char PathNvImg[], int Nb_Bits_Fort, int *Nb_des);


#endif