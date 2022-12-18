#ifndef PILE_h
#define PILE_h

#include "../head/element.h"
#define MAX 100


//structure
typedef struct eCellule
{
    ELEMENT element;
    struct eCellule * suiv;
} Cellule,*PILE;

//fonctions
PILE init_PILE();
void affichePILE(PILE pile);
int PILE_estVide(PILE pile);
PILE emPILE(PILE pile, ELEMENT entier);
PILE dePILE(PILE pile, ELEMENT *elementsupp);

#endif /* pile_statique_h */