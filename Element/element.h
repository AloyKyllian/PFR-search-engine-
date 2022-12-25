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

void affiche_ELEMENT(ELEMENT element);
void affect_ELEMENT(ELEMENT *elemaffect, ELEMENT e2);

#endif