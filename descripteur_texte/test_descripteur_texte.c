#include "../head/descripteur_texte.h"

int main()
{
tab_total tab;
    int nbr_occ=20;

//tab=descripteur_texte_finale("../texte/Textes_UTF8/03-Mimer_un_signal_nerveux_pour_utf8.xml",nbr_occ,tab);





/* mettre un chemin vers un rpertoire qui ne contient que des fichiers */
char CHEMIN [100] =  "../texte/Textes_UTF8/";

char commande[1000] ;
FILE * ptr_fic;  

char nom_fic[100];


/* cr?ation de la commande ? ex?cuter ==> doit ^etre une cha^ine de carcat?re */

/*------------------------------------------------------*/
/* RECUPERATION DU CONTENU DU REPERTOIRE  CHEMIN        */
/*------------------------------------------------------*/
strcpy(commande, "ls -l ");
strcat(commande, CHEMIN);
strcat(commande, " > fic_temp"); 

//printf("execution de %s\n", commande); 
fflush(stdout);

/*---------------------------------------------------------------------*/
/* AFFICHAGE DU CONTENU DU FICHIER CREE LORS DE LA PRECEDENTE COMMANDE */
/*---------------------------------------------------------------------*/
system(commande);
system("cat fic_temp");
//printf("---------------------------------\n");


/* ouverture du fichier temporaire fic_temp*/

ptr_fic = fopen("fic_temp", "r");

if( ptr_fic != NULL)
{   
    /*-- POUR CHAQUE LIGNE CONTENUE DANS LE FICHIER, ON RECUPERE LE NOM DU FICHIER */ 
    /*-- FORMAT DE LA LIGNE :  -rw-r--r--   1 ferrane  minfg       4834 Sep 23  2008 28-Danse___Robyn_Orlin_et.xml */

    fscanf( ptr_fic, "%*s %*s");      /* SAUTER LA PREMIERE LIGNE CONSTITUEE DE 2 CHAINES total xxxx */
    
    fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", nom_fic);  /* %*s INGNORE LA CHAINE LUE */
    while ( !feof(ptr_fic) )
    {   
          printf( "nom fichier = %s \n", nom_fic);
	  
	   /* nouvelle commande appliqu?e ? chaque fichier de la liste */
      strcpy(commande, "");
	  strcat(commande, CHEMIN); 
      //printf("nom fic : %s\n",nom_fic);
	  strcat(commande, nom_fic);
      printf("commande : %s\n",commande);
      tab=descripteur_texte_finale(commande,nbr_occ,tab);
	  printf("\n==================================\n");
	 
	 /* nom de fichier suivant */
	fscanf( ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", nom_fic);
    }
      fclose(ptr_fic);
}
else
{
   fprintf(stderr, "ERREUR :  PB avec liste_rep\n");
}



}