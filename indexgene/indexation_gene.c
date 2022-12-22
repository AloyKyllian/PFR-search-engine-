#include "indexation_gene.h"



void recup_path_img_audio( STR *str, int deb, String path, String *Erreur)
{
      char commande[500] ;
      FILE * ptr_fic;  
    /*------------------------------------------------------*/
    /* RECUPERATION DU CONTENU DU REPERTOIRE  CHEMIN        */
    /*------------------------------------------------------*/
     strcpy(commande, "ls -l ");
     strcat(commande, path);
     strcat(commande, " | grep \".txt\" > fic_temp");

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
    fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", (*str).receuillefichiers[deb].nom_fic);
       while ( !feof(ptr_fic) )
    {   
         (*str).receuillefichiers[deb].id = deb +1;
         strcpy((*str).receuillefichiers[deb].CHEMIN,path);
          printf( "nom fichier = %s \n", (*str).receuillefichiers[deb].nom_fic);
	  
	      /* nouvelle commande appliqu?e ? chaque fichier de la liste */
	      strcpy(commande, "wc -l ");
         strcat((*str).receuillefichiers[deb].CHEMIN, (*str).receuillefichiers[deb].nom_fic);
	      strcat(commande, (*str).receuillefichiers[deb].CHEMIN); 
	      system(commande);
	     printf("\n==================================\n");
	 
	     /* nom de fichier suivant */
        deb++;
        (*str).taille=deb;
	    fscanf( ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", (*str).receuillefichiers[deb].nom_fic);
     }
      fclose(ptr_fic);
}
else
{
   strcpy(*Erreur,"ERREUR :  PB avec liste_rep\n" );
}

}


void recup_path_texte( STR *str, int deb ,String path, String *Erreur)
{
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
    fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", (*str).receuillefichiers[deb].nom_fic);
       while ( !feof(ptr_fic) )
    {   
         (*str).receuillefichiers[deb].id = deb +1;
         strcpy((*str).receuillefichiers[deb].CHEMIN,path);
          printf( "nom fichier = %s \n", (*str).receuillefichiers[deb].nom_fic);
	  
	      /* nouvelle commande appliqu?e ? chaque fichier de la liste */
	      strcpy(commande, "wc -l ");
         strcat((*str).receuillefichiers[deb].CHEMIN, (*str).receuillefichiers[deb].nom_fic);
	      strcat(commande, (*str).receuillefichiers[deb].CHEMIN); 
	      system(commande);
	     printf("\n==================================\n");
	 
	     /* nom de fichier suivant */
        deb++;
        (*str).taille=deb;
	    fscanf( ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", (*str).receuillefichiers[deb].nom_fic);
     }
      fclose(ptr_fic);
}
else
{
   strcpy(*Erreur,"ERREUR :  PB avec liste_rep\n" );
}

}