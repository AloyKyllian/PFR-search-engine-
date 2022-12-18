#include "../head/element.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void affiche_ELEMENT(ELEMENT element)
{
      char commande[1000];
	  printf( "id = %s \n", element.id);
      printf( "nom fichier = %s \n", element.nom_fic);
	  strcpy(commande, "wc -l ");
	  strcat(commande, element.CHEMIN); 
	  strcat(commande, element.nom_fic);
	  system(commande);
	  printf("\n==================================\n");
}

void affect_ELEMENT(ELEMENT *elemaffect, ELEMENT e2)
{
    *elemaffect=e2;
}
