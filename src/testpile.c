
#include "../head/Pile.h"

int main ()
{
  PILE paux;
  int test;
    ELEMENT elemsupp;
  paux=init_PILE();
  (paux==NULL)?printf("\t\tTEST OK.\n"):printf("\t\tTEST NOK.\n");
  printf("\tObjectif Test2: est vide et affichage sur une pile vide\n\t\tPile Vide:\n");
  test=PILE_estVide(paux);
  (test==1)?printf("\t\tTEST OK.\n\t\tPile Pleine:\n"):printf("\t\tTEST NOK.\n\t\tPile Pleine:\n");
  printf("\t\tTest affichage:\n");
  affichePILE(paux);
  printf("\tObjectif Test3: empiler element 1,2,3,4,5,6 et affichage\n ");
  ELEMENT essaie1;
  essaie1.id=1;
  strcpy(essaie1.nom_fic,'hello');
  strcpy(essaie1.CHEMIN,'chemin/head/lol');
  paux=emPILE(paux, essaie1);
//   affichePILE(paux);
//   paux=emPILE(paux, 2);
//   affichePILE(paux);
//   paux=emPILE(paux, 3);
//   affichePILE(paux);
//   paux=emPILE(paux, 4);
//   affichePILE(paux);
//   paux=emPILE(paux, 5);
//   affichePILE(paux);
//   paux=emPILE(paux, 6);
//   affichePILE(paux);
//   printf("\tObjectif Test3: deplier element 1,2,3 et affichage:\n");
//   paux=dePILE(paux, &elemsupp);
//   affichePILE(paux);
//   printf("ELEMENT SUPP:");
//   affiche_ELEMENT(elemsupp);
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