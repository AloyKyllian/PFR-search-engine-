#include <stdio.h>

#define NOMBRE_DE_COLONNES 5

void afficherTableau(int *tableau, int nombreDeLignes, int nombreDeColonnes)
{
  int *tab[nombreDeLignes][nombreDeColonnes];
  tab=tableau;
  for (int i = 0; i < nombreDeLignes; i++)
  {
    for (int j = 0; j < nombreDeColonnes; j++)
    {

      printf("%d ", tableau[j]);
    }
    printf("\n");
  }
}

int main()
{
  int monTableau[][NOMBRE_DE_COLONNES] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
  afficherTableau(*monTableau, 2, NOMBRE_DE_COLONNES);
  return 0;
}