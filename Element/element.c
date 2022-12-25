#include "element.h"

void affiche_ELEMENT(ELEMENT element)
{
      printf("%d | %s\n", element.id, element.CHEMIN);
}

void affect_ELEMENT(ELEMENT *elemaffect, ELEMENT e2)
{
    *elemaffect=e2;
}
