#ifndef PILE_h
#define PILE_h
#include "../Element/element.h"

//structure
typedef struct eCellule
{   ELEMENT element;
    struct eCellule * suiv;
}Cellule,*PILE;

typedef struct eCellule_audio
{   ELEMENT_audio element;
    struct eCellule_audio * suiv;
}Cellule_audio,*PILE_audio;

//fonctions
PILE init_PILE();
PILE_audio init_PILE_audio();
void affichePILE(PILE pile);
void affichePILE_audio(PILE_audio pile);
int PILE_estVide(PILE pile);
PILE emPILE(PILE pile, ELEMENT entier);
PILE dePILE(PILE pile, ELEMENT *elementsupp);
PILE_audio emPILE_audio(PILE_audio pile, ELEMENT_audio entier);
PILE_audio dePILE_audio(PILE_audio pile, ELEMENT_audio *elementsupp);

#endif 

