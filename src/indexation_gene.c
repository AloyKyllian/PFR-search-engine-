#include "../head/indexation_gene.h"

// modifier recup path avec grep 
//une fonction que pour texte
void recup_path( receuillefichiers *doctexte, String path, String *Erreur)
{
     int i =0;
      char commande[1000] ;
      FILE * ptr_fic;  
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
    fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", (*doctexte)[i].nom_fic);
       while ( !feof(ptr_fic) )
    {   
         (*doctexte)[i].id = i +1;
         strcpy((*doctexte)[i].CHEMIN,path);
          printf( "nom fichier = %s \n", (*doctexte)[i].nom_fic);
	  
	      /* nouvelle commande appliqu?e ? chaque fichier de la liste */
	      strcpy(commande, "wc -l ");
	      strcat(commande, (*doctexte)[i].CHEMIN); 
	      strcat(commande, (*doctexte)[i].nom_fic);
	      system(commande);
	     printf("\n==================================\n");
	 
	     /* nom de fichier suivant */
        i++;
	    fscanf( ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", (*doctexte)[i].nom_fic);
     }
      fclose(ptr_fic);
}
else
{
   strcpy(*Erreur,"ERREUR :  PB avec liste_rep\n" );
}

}


void recup_path( receuillefichiers *doctexte, String path, String *Erreur)
{
     int i =0;
      char commande[1000] ;
      FILE * ptr_fic;  
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
    fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", (*doctexte)[i].nom_fic);
       while ( !feof(ptr_fic) )
    {   
         (*doctexte)[i].id = i +1;
         strcpy((*doctexte)[i].CHEMIN,path);
          printf( "nom fichier = %s \n", (*doctexte)[i].nom_fic);
	  
	      /* nouvelle commande appliqu?e ? chaque fichier de la liste */
	      strcpy(commande, "wc -l ");
	      strcat(commande, (*doctexte)[i].CHEMIN); 
	      strcat(commande, (*doctexte)[i].nom_fic);
	      system(commande);
	     printf("\n==================================\n");
	 
	     /* nom de fichier suivant */
        i++;
	    fscanf( ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", (*doctexte)[i].nom_fic);
     }
      fclose(ptr_fic);
}
else
{
   strcpy(*Erreur,"ERREUR :  PB avec liste_rep\n" );
}

}