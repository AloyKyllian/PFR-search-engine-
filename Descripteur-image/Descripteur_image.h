#ifndef DESCRIPTEUR_IMAGE_H
#define DESCRIPTEUR_IMAGE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
Exemple pour cree un descripteur :

    DESCRIPTEUR_IMAGE descripteur_image;
    int Erreur;
    descripteur_image = Pack_Descripteur_image(&Erreur,Path,Nb_Bit_Fort);
    if(Erreur!=0)
    {
        // Afficer Erreur
    }
*/

typedef struct
{
    int Nb_Ligne;
    int Nb_Colonne;
    int Nb_composante;
    int **adr_Matrice;
} IMAGE;

typedef struct
{
    int Nb_Ligne;
    int Nb_Colonne;
    int **Bilan;
} DESCRIPTEUR_IMAGE;

// Permet de lire le .txt d'une image et de renvoyer une struct IMAGE
IMAGE Lire_image(int *Erreur, char Path[]);

// Fais le traitement des valeurs et les stock dans la matrice de la structure IMAGE
IMAGE Pre_traitement(int *, IMAGE, int);

// Renvoie le descripteur de l'image(Pre_Traiter)
DESCRIPTEUR_IMAGE Creation_Discripteur(int *, IMAGE, int);

// Utilise les fonctions precédante pour cree un descripteur
DESCRIPTEUR_IMAGE Pack_Descripteur_image(int *Erreur, char Path[],int Nb_Bits_Fort);

#endif