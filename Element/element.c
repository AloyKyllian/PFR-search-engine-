#include "element.h"

void affiche_ELEMENT(ELEMENT element)
{
      printf("%d | %s\n", element.id, element.CHEMIN);
}

void affiche_ELEMENT_audio(ELEMENT_audio element)
{
      printf("%d \n", element.id);
      for (unsigned i = 0; i < element.descripteur.size_x; ++i)
    {
        for (unsigned j = 0; j < element.descripteur.size_y; ++j)
        {
            printf(" |%3d| ",element.descripteur.tab[i][j]);
        }
        printf("\r\n");
    }
    fflush(stdout);
}
void affiche_ELEMENT_image(ELEMENT_image element)
;
void affect_ELEMENT_image(ELEMENT_image *elemaffect, ELEMENT_image e2)
;

void affect_ELEMENT(ELEMENT *elemaffect, ELEMENT e2)
{
    *elemaffect=e2;
}

void affect_ELEMENT_audio(ELEMENT_audio *elemaffect, ELEMENT_audio e2)
{
    *elemaffect=e2;
}
