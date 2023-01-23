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

tab_similaire *Comparaison_descripteur_image(int *Erreur, char PathRecueil[], char PathNvImg[], int Nb_Bits_Fort, int *Nb_des);

/**
 * @brief
 *
 */
float comparaison(int val_lu, descri_audio descripteur_comparé, int ligne, int intervalle, descri_audio descri, float fenetre);

/**
 * @brief
 *
 * Elle utilise la fonction "getligne" pour obtenir le nombre de lignes dans le fichier à comparer,
 * crée un descripteur audio pour ce fichier en utilisant la fonction "Descripteur_audio",
 * alloue de la mémoire pour une table de similarité,
 * ouvre le fichier de descripteur audio en mode lecture, lit les valeurs de ce fichier et les utilise pour créer un descripteur audio pour chaque fichier de comparaison,
 * utilise une fonction "comparaison" pour calculer le pourcentage de similarité entre les deux descripteurs audio,
 * stock ces pourcentages dans la table de similarité, trie les fichiers par ordre de similarité, et retourne la table de similarité.
 *
 * @param fenetre
 * @param intervalle
 * @param chemin_descripteur_compare
 * @param chemin_descripteur_audio
 * @param erreur
 * @param Nb_ligne
 * @return tab_similaire*
 */
tab_similaire *comparaison_audio(int fenetre, int intervalle, char *chemin_descripteur_compare, char *chemin_descripteur_audio, int *erreur, int *Nb_ligne);

tab_similaire *comparaison_texte(int nbr_mot, char *chemin_fichier_a_compare, char *chemin_descripteur, int *Erreur, int *Nb_ligne);

// typedef enum {texte,image,audio}type_compare;

#endif