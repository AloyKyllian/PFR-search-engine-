#ifndef DESCRIPTEUR_IMAGE_H
#define DESCRIPTEUR_IMAGE_H

#include "../Config/Global.h"

/*
Exemple pour cree un descripteur :

IMAGE img;
DESCRIPTEUR_IMAGE di;
String Erreur;

img = Lire_image(&Erreur,Path/Chemin du fichier);
img = Pre_traitement(&Erreur,img,CONFIG.Nb_bitfort);
di = Creation_Discripteur(&Erreur,img,CONFIG.Nb_bitfort);
*/

typedef struct
{
    int Nb_Ligne;
    int Nb_Colonne;
    int Nb_composante;
    int **adr_Matrice;
    String Path;
} IMAGE;

typedef struct
{
    String ID;
    String Path;
    int **Bilan;
} DESCRIPTEUR_IMAGE;

// Permet de lire le .txt d'une image et de renvoyer une struct IMAGE
IMAGE Lire_image(String *, String);

// Fais le traitement des valeurs et les stock dans la matrice de la structure IMAGE
IMAGE Pre_traitement(String *, IMAGE, int);

// Renvoie le descripteur de l'image(Pre_Traiter)
DESCRIPTEUR_IMAGE Creation_Discripteur(String *, IMAGE, int);

#endif