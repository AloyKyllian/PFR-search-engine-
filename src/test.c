#include <stdio.h>
#include <stdlib.h>
#define NOMBRE_DE_COLONNES 5

void afficherTableau(int **tableau, int nombreDeLignes, int nombreDeColonnes)
{
  for (int i = 0; i < nombreDeLignes; i++)
  {
    for (int j = 0; j < nombreDeColonnes; j++)
    {
      tableau[i][j]=6;
      printf("%d ", tableau[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int monTableau[][NOMBRE_DE_COLONNES] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};

  int **mabite;

  mabite = malloc(3 * sizeof(*mabite));
  for (int i = 0; i < 3; i++)
  {
      mabite[i] = malloc(5 * sizeof(**mabite));
  }

  //mabite[0][0]=6;

  //printf("%d",mabite[0][0]);

  afficherTableau(mabite, 3, 5);
  return 0;
}