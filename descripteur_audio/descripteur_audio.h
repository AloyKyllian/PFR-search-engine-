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
 * elle permet de creer un descripteur d'un fichier txt tirer d'un fichier audio
 * 
 * @param fenetre 
 * @param intervalle 
 * @param chemin_fichier 
 * @param erreur 
 * @return descri_audio 
 * 
 * 
 * 
 */
descri_audio Descripteur_audio(int fenetre, int intervalle, char *chemin_fichier,int * erreur);

/**
 * @brief 
 * 
 * a quoi elle sert
 * 
 * @param path chemin du fichier
 * @param erreur 
 * @return int 
 */
int getligne(char *path, int *erreur);

#endif