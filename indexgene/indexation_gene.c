#include "indexation_gene.h"


void recup_path( PILE *pourchemin, int deb, String path,String type, String *Erreur)
{
             ELEMENT element;
             String nom_fic,chemin;
             char commande[500] ;
             FILE * ptr_fic;  
    /*------------------------------------------------------*/
    /* RECUPERATION DU CONTENU DU REPERTOIRE  CHEMIN        */
    /*------------------------------------------------------*/
             strcpy(commande, "ls -l ");
             strcat(commande, path);

               if( strcmp(type, "texte")==0) // recuperer chemin pour fichier texte
                   strcat(commande, " > fic_temp"); 
              else                          // recuperer chemin pour fichier .txt audio et image
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
                   if( strcmp(type, "texte")==0)
                   fscanf( ptr_fic, "%*s %*s");      /* SAUTER LA PREMIERE LIGNE CONSTITUEE DE 2 CHAINES total xxxx */
                   fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", nom_fic);
                   while ( !feof(ptr_fic) )
                   {   
                           strcpy(chemin,path);
                          strcat(chemin, nom_fic);
                          element.id=deb;
                           strcpy(element.CHEMIN,chemin);

                            *pourchemin= emPILE(*pourchemin, element);
	                   /* nom de fichier suivant */
                          deb++;
	                    fscanf( ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", nom_fic);
                   }
                  fclose(ptr_fic);
            }
            else
            {
                  strcpy(*Erreur,"Erreur : Fichier introuvable");
            }
            fclose(ptr_fic); 
}

//____________________________________________
//depiler le chemin de le fichier liste_base_texte ou liste _base_audio ou liste_base_image
//____________________________________________
void depiler_path ( PILE *pourchemin, String type, String *Erreur)
{
     ELEMENT elementsupp;
     FILE *fichier = NULL;
     if (strcmp(type, "texte")==0)
           fichier = fopen("../liste_base/liste_base_texte", "w");
     else if (strcmp(type, "image")==0)
           fichier = fopen("../liste_base/liste_base_image", "w");
     else
           fichier = fopen("../liste_base/liste_base_audio", "w");    

    if (fichier != NULL)
    {
          while ( *pourchemin !=NULL)
            {
               *pourchemin= dePILE(*pourchemin, &elementsupp);
               fprintf(fichier, "%d | %s\n",elementsupp.id, elementsupp.CHEMIN );
            }
    }
    else
    {
        strcpy(*Erreur,"Erreur : Fichier introuvable");
    }
    fclose(fichier); 
}


void lire_chemin (PILE *pourchemin, String type, String * erreur)
{   
    FILE *fichier = NULL;
    ELEMENT element;
      if (strcmp(type, "texte")==0)
           fichier = fopen("../liste_base/liste_base_texte", "r");
     else if (strcmp(type, "image")==0)
           fichier = fopen("../liste_base/liste_base_image", "r");
     else
           fichier = fopen("../liste_base/liste_base_audio", "r");    
    if (fichier != NULL)
    {
            fscanf(fichier, "%d | %s\n",&element.id,element.CHEMIN);
            *pourchemin= emPILE(*pourchemin, element);
              while (! feof(fichier))
              {   
                    fscanf(fichier, "%d | %s\n",&element.id,element.CHEMIN);
                     *pourchemin= emPILE(*pourchemin, element);
                     
              } 

    }
    else
    {
        strcpy(*erreur,"Erreur : Fichier liste base introuvable");
    }
    fclose(fichier);
}


void base_descript_empiler_audio (PILE_audio * dscr_audio)
{
       String Erreur1;
       //CONFIG config;
       PILE pourchemin=init_PILE();
       ELEMENT_audio element_audio;
       lire_chemin (&pourchemin, "audio", &Erreur1);
       affichePILE(pourchemin);
       //config = Lire_CONFIG(&Erreur1);
       //config= Lire_nb_fenetre(config,&Erreur); 
      //Lis et verifie la validiter de la valeur de l'intervale
       //config= Lire_intervale(config,&Erreur);
       while(pourchemin!=NULL)
       {
           //mettre a jour le descripteur a empiler
           element_audio.descripteur=Descripteur_audio( 4096 , 15,pourchemin->element.CHEMIN, element_audio.descripteur) ;
           //mettre a jour le id a empiler
           element_audio.id=pourchemin->element.id;
           printf("id : %d , chemin : %s",element_audio.id,pourchemin->element.CHEMIN);
           //empiler
           *dscr_audio= emPILE_audio(*dscr_audio, element_audio);
           pourchemin= pourchemin->suiv;           
       }    
}