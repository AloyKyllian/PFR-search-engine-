#ifndef COMPARAISON_IMAGE_C
#define COMPARAISON_IMAGE_C
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int pourcentage;
} tab_similaire;

tab_similaire* Comparaison_descripteur_image(int *Erreur, char PathRecueil[], char PathNvImg[], int Nb_Bits_Fort);


#endif