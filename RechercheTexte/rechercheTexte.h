#ifndef RECHERCHETEXTE_H
#define RECHERCHETEXTE_H
#include "../head/Global.h"
typedef struct{
    int id;
    int nb_occurence;
}tab_Res;
void rechercheTexte(char *mot, char *chemin);


#endif