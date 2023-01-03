#include <stdio.h>
#include <stdlib.h>
#include"descript_audio.h"
#define NOMBRE_DE_COLONNES 5

void afficherTableau(int **tableau, int nombreDeLignes, int nombreDeColonnes)
{
  for (int i = 0; i < nombreDeLignes; i++)
  {
    for (int j = 0; j < nombreDeColonnes; j++)
    {
      //tableau[i][j]=6;
      printf("%d ", tableau[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int erreur;
  descri_audio tableau;

    tableau=Descripteur_audio(4096,32,"../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/jingle_fi.txt",tableau,&erreur);
    printf("%d",erreur);
    
    for (unsigned i = 0; i < tableau.size_x; ++i)
    {
        for (unsigned j = 0; j < tableau.size_y; ++j)
        {
            printf(" |%3d| ",tableau.tab[i][j]);
        }
        printf("\r\n");
    }

}