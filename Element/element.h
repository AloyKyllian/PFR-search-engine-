#ifndef element_h
#define element_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../descript_audio/descript_audio.h"

#define MAX_CHAINE 100
typedef char String[MAX_CHAINE];



//  typedef struct eELEMENT
//   { 
//      String CHEMIN;
//      String nom_fic;
//      int id;
//   }ELEMENT;

// typedef struct 
// {
//     ELEMENT receuillefichiers[500];
//     int taille;
// } STR;

typedef struct 
{
    descri_audio audio;
    int id;
}struct_audio;

// typedef struct 
// {
//     structure 
//     int id;
// }struct_image;

// typedef struct 
// {
//     structure 
//     int id;
// }struct_texte;


void affiche_ELEMENT(ELEMENT element);
void affect_ELEMENT(ELEMENT *elemaffect, ELEMENT e2);

#endif 