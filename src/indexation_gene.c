#include "../head/indexation_gene.h"
#include "element.h"

void recup_path( receuillefichiers doctexte, String path, String *Erreur)
{
     int i =0;
      char commande[100] ;
      FILE * ptr_fic;  
      strcpy(doctexte[i].CHEMIN,path);
    /*------------------------------------------------------*/
    /* RECUPERATION DU CONTENU DU REPERTOIRE  CHEMIN        */
    /*------------------------------------------------------*/
     strcpy(commande, "ls -l ");
     strcat(commande, path);
     strcat(commande, " > fic_temp"); 

     printf("execution de %s\n", commande); 
     fflush(stdout);
    /*---------------------------------------------------------------------*/
    /* AFFICHAGE DU CONTENU DU FICHIER CREE LORS DE LA PRECEDENTE COMMANDE */
    /*---------------------------------------------------------------------*/
     system(commande);
     system("cat fic_temp");
     printf("---------------------------------\n");  

    /* ouverture du fichier temporaire fic_temp*/

     ptr_fic = fopen("fic_temp", "r");

if( ptr_fic != NULL)
{   
    fscanf( ptr_fic, "%*s %*s");
    fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", doctexte[i].nom_fic);
       while ( !feof(ptr_fic) )
    {   
          printf( "nom fichier = %s \n", doctexte[i].nom_fic);
	  
	      /* nouvelle commande appliqu?e ? chaque fichier de la liste */
	   
	      strcpy(commande, "wc -l ");
	      strcat(commande, doctexte[i].CHEMIN); 
	      strcat(commande, doctexte[i].nom_fic);
	      system(commande);
	     printf("\n==================================\n");
	 
	     /* nom de fichier suivant */
	    fscanf( ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", doctexte[i].nom_fic);
        i++;
     }
      fclose(ptr_fic);
}
else
{
   fprintf(stderr, "ERREUR :  PB avec liste_rep\n");
}

}