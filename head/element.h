#ifndef element_h
#define element_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_CHAINE 100
typedef char String[MAX_CHAINE];

// notre element est une structure avec le nom du fichier, le chemin d'acces et ID

typedef struct eELEMENT
{ 
    String nom_fic;
    String CHEMIN;
    int id;
}ELEMENT;

typedef struct 
{
    ELEMENT receuillefichiers[500];
    int taille;
} STR;


void affiche_ELEMENT(ELEMENT element);
void affect_ELEMENT(ELEMENT *elemaffect, ELEMENT e2);

#endif 