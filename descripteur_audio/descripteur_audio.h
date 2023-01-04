#ifndef DESCRIPT_AUDIO_H
#define DESCRIPT_AUDIO_H

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int ligne;
    int colonne;
    int **tab;
} descri_audio;

descri_audio Descripteur_audio(int fenetre, int intervalle, char *chemin_fichier, descri_audio desci,int * erreur);

#endif