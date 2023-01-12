#ifndef DESCRIPTEUR_TEXTE_H
#define DESCRIPTEUR_TEXTE_H

#include <stdint.h>
#include <stdio.h>
#include "../head/Global.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct 
{
    String *tab_mot;
    int *tab_app;
    int index;
}DESCRIPTEUR_TEXTE;

int comptemot(char* mot_lu);
DESCRIPTEUR_TEXTE descripteur_texte_finale(char* chemin_fichier,int nbr_occ,DESCRIPTEUR_TEXTE tab_renvoyer,int* Erreur);
DESCRIPTEUR_TEXTE tab_occ(int nbr_occ,DESCRIPTEUR_TEXTE tab,DESCRIPTEUR_TEXTE tab_occ_finale);
DESCRIPTEUR_TEXTE descripteur_texte( int nbr_mot, char* mot,DESCRIPTEUR_TEXTE tab,int* Erreur,String id);
bool filtrage(char* mot,int * Erreur);
char *nettoyage(char mot_lu[100]);


#endif