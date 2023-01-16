#ifndef DESCRIPTEUR_TEXTE_H
#define DESCRIPTEUR_TEXTE_H

#include <stdint.h>
#include <stdio.h>
#include "../head/Global.h"
#include <string.h>
#include <ctype.h>

typedef struct 
{
    String *tab_mot;
    int *tab_app;
    int index;
}tab_total;

int comptemot(char* mot_lu);
tab_total descripteur_texte_finale(char* chemin_fichier,int nbr_occ,tab_total tab_renvoyer);
tab_total tab_occ(int nbr_occ,tab_total tab,tab_total tab_occ_finale);
tab_total descripteur_texte( int nbr_mot, char* mot,tab_total tab);
bool filtrage(char* mot);
char *nettoyage(char mot_lu[100]);


#endif