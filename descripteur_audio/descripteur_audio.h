/**
 * Fait par Kyllian Aloy
 * 
 * Le 23/01/2023
 * 
*/

#ifndef DESCRIPT_AUDIO_H
#define DESCRIPT_AUDIO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int ligne;
    int colonne;
    int **tab;
} descri_audio;

/**
 * @brief
 *
 * Elle utilise la fonction "getligne" pour obtenir le nombre de lignes dans le fichier,
 * calcule le nombre de fenêtres en divisant le nombre de lignes par "nb_val_fenetre",
 * crée une structure "descri_audio" pour stocker les données du descripteur audio, alloue de la mémoire pour cette structure, initialise les valeurs de cette structure à zéro,
 * ouvre le fichier en mode lecture,
 * lit les valeurs et les stockent dans la structure en utilisant une logique de comparaison pour déterminer à quelle intervalle chaque valeur appartient,
 * ferme le fichier et retourne la structure "descri_audio" qui contient le descripteur audio.
 *
 * @param fenetre
 * @param intervalle
 * @param chemin_fichier
 * @param erreur
 * @return descri_audio
 */
descri_audio Descripteur_audio(int fenetre, int intervalle, char *chemin_fichier, int *erreur);

/**
 * @brief
 *
 *  Elle utilise une commande "wc -l" pour compter le nombre de lignes dans le fichier spécifié par "path",
 *  enregistre le résultat dans un fichier temporaire "getligne_temp" et l'ouvre ensuite pour lire le résultat.
 *  Si le fichier est vide, elle assigne 7 à "erreur". Enfin, elle supprime le fichier temporaire et renvoie le nombre de lignes lues.
 *
 * @param path chemin du fichier
 * @param erreur
 * @return int
 */
int getligne(char *path, int *erreur);

#endif