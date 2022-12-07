#ifndef DESCRIPTEUR_IMAGE_H
#define DESCRIPTEUR_IMAGE_H

#include "../head/Global.h"

typedef struct
{
    int Nb_Ligne;
    int Nb_Colonne;
    int Nb_composante;
    int **adr_Matrice;
}IMAGE;


IMAGE Lire_image(String *, String);

IMAGE Pre_traitement(IMAGE img);

#endif