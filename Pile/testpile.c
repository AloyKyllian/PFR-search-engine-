
#include "Pile.h"

int main ()
{
  PILE paux;
  int test;
    ELEMENT elemsupp;
  paux=init_PILE();
  (paux==NULL)?printf("\t\tTEST OK.\n"):printf("\t\tTEST NOK.\n");
  printf("\tObjectif Test2: est vide et affichage sur une pile vide\n\t\tPile Vide:\n");
  test=PILE_estVide(paux);
  (test==1)?printf("\t\tTEST OK.\n"):printf("\t\tTEST NOK.\n");
  printf("\t\tTest affichage:\n");
  affichePILE(paux);
  printf("\tObjectif Test3: empiler element et affichage\n ");
  ELEMENT essaie1;
  essaie1.id=1;
  strcpy(essaie1.nom_fic,"hello");
  strcpy(essaie1.CHEMIN,"/Users/yasmine/programme1A/PFR/DATA_FIL_ROUGE_DEV/Textes/");
  paux=emPILE(paux, essaie1);
 affichePILE(paux);

printf("\tObjectif Test3: deplier element  et affichage:\n");
   paux=dePILE(paux, &elemsupp);
  affichePILE(paux);
  printf("ELEMENT SUPP:\n");
  affiche_ELEMENT(elemsupp);
//     paux=dePILE(paux, &elemsupp);
//     affichePILE(paux);
//     printf("ELEMENT SUPP:");
//     affiche_ELEMENT(elemsupp);
//     paux=dePILE(paux, &elemsupp);
//     affichePILE(paux);
//     printf("ELEMENT SUPP:");
//     affiche_ELEMENT(elemsupp);
//     paux=dePILE(paux, &elemsupp);
//     affichePILE(paux);
//     printf("ELEMENT SUPP:");
//     affiche_ELEMENT(elemsupp);
//     paux=dePILE(paux, &elemsupp);
//     affichePILE(paux);
//     printf("ELEMENT SUPP:");
//     affiche_ELEMENT(elemsupp);
//     paux=dePILE(paux, &elemsupp);
//     affichePILE(paux);
//     printf("ELEMENT SUPP:");
//     affiche_ELEMENT(elemsupp);
//     printf("\nTest depiler une pile vide");
//     paux=dePILE(paux, &elemsupp);
//     affichePILE(paux);
//     (paux==NULL)? printf("\t test OK"):printf("\t test NOK");

}