#ifndef element_h
#define element_h

#include "../head/Global.h"

// notre element est une structure avec le nom du fichier, le chemin d'acces et ID

typedef struct eELEMENT
{ 
    String nom_fic;
    String CHEMIN;
    int ID;
}ELEMENT;

void affiche_ELEMENT(ELEMENT element);
void affect_ELEMENT(ELEMENT *elemaffect, ELEMENT e2);

#endif 