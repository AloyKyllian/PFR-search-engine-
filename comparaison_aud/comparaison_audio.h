#ifndef COMPARAISON_AUDIO_H
#define COMPARAISON_AUDIO_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../descripteur_audio/descripteur_audio.h"

typedef struct
{
    int id;
    float pourcentage;
} tab_similaire;

float comparaison(int val_lu, descri_audio descripteur_comparé, int ligne, int intervalle, descri_audio descri, float fenetre);

tab_similaire *comparaison_audio(int seuil, int fenetre, int intervalle, char *chemin_descripteur_compare, char *chemin_descripteur_audio);

#endif