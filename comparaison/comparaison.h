#ifndef COMPARAISON_H
#define COMPARAISON_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../descripteur_audio/descripteur_audio.h"
#include "../descripteur_image/Descripteur_image.h"
#include "../descripteur_texte/descripteur_texte.h"

typedef struct
{
    int id;
    float pourcentage;
} tab_similaire;

tab_similaire* Comparaison_descripteur_image(int *Erreur, char PathRecueil[], char PathNvImg[], int Nb_Bits_Fort, int *Nb_des);


float comparaison(int val_lu, descri_audio descripteur_comparé, int ligne, int intervalle, descri_audio descri, float fenetre);


tab_similaire *comparaison_audio(int seuil, int fenetre, int intervalle, char *chemin_descripteur_compare, char *chemin_descripteur_audio);


tab_similaire* comparaison_texte(int nbr_mot,char* chemin_fichier_a_compare,char* chemin_descripteur,int * Erreur,int seuil);


#endif