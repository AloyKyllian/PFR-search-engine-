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
typedef struct
{
    String ID;
    int **Bilan;
}DESCRIPTEUR_IMAGE;



IMAGE Lire_image(String *, String);

IMAGE Pre_traitement(IMAGE img);

DESCRIPTEUR_IMAGE Creation_Discripteur(IMAGE,int, String *);

#endif