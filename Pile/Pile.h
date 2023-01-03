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

typedef struct eCellule_image
{   ELEMENT_image element;
    struct eCellule_image * suiv;
}Cellule_image,*PILE_image;

//fonctions



int PILE_estVide(PILE pile);
PILE init_PILE();
void affichePILE(PILE pile);
PILE emPILE(PILE pile, ELEMENT entier);
PILE dePILE(PILE pile, ELEMENT *elementsupp);

PILE_audio init_PILE_audio();
void affichePILE_audio(PILE_audio pile);
PILE_audio emPILE_audio(PILE_audio pile, ELEMENT_audio element);
PILE_audio dePILE_audio(PILE_audio pile, ELEMENT_audio *elementsupp);

void affichePILE_image(PILE_image pile);
PILE_image emPILE_image(PILE_image pile, ELEMENT_image element);
PILE_image dePILE_image(PILE_image pile, ELEMENT_image *elementsupp);

#endif 

