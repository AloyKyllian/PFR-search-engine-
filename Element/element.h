#ifndef element_h
#define element_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../descript_audio/descript_audio.h"

#define MAX_CHAINE 100
typedef char String[MAX_CHAINE];

typedef struct 
{
    int id;
    String CHEMIN;
}ELEMENT;

typedef struct 
{
    descri_audio descripteur;
    int id;
}ELEMENT_audio;


void affect_ELEMENT_audio(ELEMENT_audio *elemaffect, ELEMENT_audio e2);
void affiche_ELEMENT(ELEMENT element);
void affect_ELEMENT(ELEMENT *elemaffect, ELEMENT e2);
void affiche_ELEMENT_audio(ELEMENT_audio element);

#endif