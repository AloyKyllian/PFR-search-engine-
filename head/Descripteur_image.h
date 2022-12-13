#ifndef DESCRIPTEUR_IMAGE_H
#define DESCRIPTEUR_IMAGE_H

#include "../head/Global.h"

typedef struct
{
    int Nb_Ligne;
    int Nb_Colonne;
    int Nb_composante;
    int **adr_Matrice;
    String Path;
}IMAGE;
typedef struct
{
    String ID;
    String Path;
    int **Bilan;
}DESCRIPTEUR_IMAGE;



IMAGE Lire_image(String *, String);

IMAGE Pre_traitement(IMAGE, int);

DESCRIPTEUR_IMAGE Creation_Discripteur(IMAGE,int, String *);

#endif