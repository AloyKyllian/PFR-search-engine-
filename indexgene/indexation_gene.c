#include "indexation_gene.h"

void recup_path(PILE *pourchemin, int deb, String path, String type, int *erreur)
{
      ELEMENT element;
      String nom_fic, chemin;
      char commande[500];
      FILE *ptr_fic;
      /*------------------------------------------------------*/
      /* RECUPERATION DU CONTENU DU REPERTOIRE  CHEMIN        */
      /*------------------------------------------------------*/
      strcpy(commande, "ls -l ");
      strcat(commande, path);

      if (strcmp(type, "texte") == 0) // recuperer chemin pour fichier texte
            strcat(commande, " > fic_temp");
      else // recuperer chemin pour fichier .txt audio et image
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

      if (ptr_fic != NULL)
      {
            if (strcmp(type, "texte") == 0)
                  fscanf(ptr_fic, "%*s %*s"); /* SAUTER LA PREMIERE LIGNE CONSTITUEE DE 2 CHAINES total xxxx */
            fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", nom_fic);
            while (!feof(ptr_fic))
            {
                  strcpy(chemin, path);
                  strcat(chemin, nom_fic);
                  element.id = deb;
                  strcpy(element.CHEMIN, chemin);

                  *pourchemin = emPILE(*pourchemin, element);
                  /* nom de fichier suivant */
                  deb++;
                  fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", nom_fic);
            }
            fclose(ptr_fic);
      }
      else
      {
             *erreur = 1;
      }
      affichePILE(*pourchemin);
      fflush(stdout);
      fclose(ptr_fic);
}

//____________________________________________
// depiler le chemin de le fichier liste_base_texte ou liste _base_audio ou liste_base_image
//____________________________________________
void depiler_path(PILE *pourchemin, String type, int *erreur)
{
      ELEMENT elementsupp;
      FILE *fichier = NULL;
      if (strcmp(type, "texte") == 0)
            fichier = fopen("../liste_base/liste_base_texte", "w");
      else if (strcmp(type, "image") == 0)
            fichier = fopen("../liste_base/liste_base_image", "w");
      else
            fichier = fopen("../liste_base/liste_base_audio", "w");

      if (fichier != NULL)
      {
            while ((*pourchemin)->suiv != NULL)
            {
                  *pourchemin = dePILE(*pourchemin, &elementsupp);
                  fprintf(fichier, "%d | %s\n", elementsupp.id, elementsupp.CHEMIN);
            }
            *pourchemin = dePILE(*pourchemin, &elementsupp);
            fprintf(fichier, "%d | %s", elementsupp.id, elementsupp.CHEMIN);
      }
      else
      {
             *erreur = 1;
      }
      fclose(fichier);
}

PILE_audio base_descript_empiler_audio(PILE_audio dscr_audio, int *erreur)
{
      FILE *ptr_fic = NULL;
      ELEMENT_audio element_temp;
      char CHEMIN[100] = "../liste_base/liste_base_audio";
      char cheminfichier[200];
      ptr_fic = fopen(CHEMIN, "r");
      if (ptr_fic != NULL)
      {
            fscanf(ptr_fic, "%d | %s\n", &element_temp.id, cheminfichier);
            element_temp.descripteur = Descripteur_audio(4096, 30, cheminfichier, element_temp.descripteur);
            dscr_audio = emPILE_audio(dscr_audio, element_temp);
            while (!feof(ptr_fic))
            {
                  fscanf(ptr_fic, "%d | %s", &element_temp.id, cheminfichier);
                  element_temp.descripteur = Descripteur_audio(4096, 30, cheminfichier, element_temp.descripteur);
                  dscr_audio = emPILE_audio(dscr_audio, element_temp);
            }
            fclose(ptr_fic);
      }
      else
      {
             *erreur = 1;
      }
      return dscr_audio;
}

void depiler_descripteur_audio(PILE_audio dscr_audio, int *erreur)
{
      ELEMENT_audio elementsupp;
      FILE *fichier = NULL;
      fichier = fopen("../base_descripteur/base_descripteur_audio", "w");

      if (fichier != NULL)
      {
            while (dscr_audio->suiv != NULL)
            {
                  dscr_audio = dePILE_audio(dscr_audio, &elementsupp);
                  //______________________________
                  // AFFICHAGE ELEMENT DANS FICHIER
                  //_______________________________
                  fprintf(fichier, "%d\n", elementsupp.id);
                  for (unsigned i = 0; i < elementsupp.descripteur.size_x; ++i)
                  {
                        for (unsigned j = 0; j < elementsupp.descripteur.size_y; ++j)
                        {
                              fprintf(fichier, " |%3d| ", elementsupp.descripteur.tab[i][j]);
                        }
                        fprintf(fichier, "\r\n");
                  }
            }
            dscr_audio = dePILE_audio(dscr_audio, &elementsupp);
            //______________________________
            // AFFICHAGE ELEMENT DANS FICHIER
            //_______________________________
            fprintf(fichier, "%d\n", elementsupp.id);
            for (unsigned i = 0; i < elementsupp.descripteur.size_x; ++i)
            {
                  for (unsigned j = 0; j < elementsupp.descripteur.size_y; ++j)
                  {
                        fprintf(fichier, " |%3d| ", elementsupp.descripteur.tab[i][j]);
                  }
                  fprintf(fichier, "\r\n");
            }
      }
      else
      {
             *erreur = 1;
      }
      fclose(fichier);
}


PILE_image base_descript_empiler_image(PILE_image dscr_image, int *erreur)
{

      int Erreur = 0;
      FILE *ptr_fic = NULL;
      ELEMENT_image element_temp;
      IMAGE img;
      char CHEMIN[100] = "../liste_base/liste_base_image";
      char cheminfichier[200];
      CONFIG config;

      config = Lire_CONFIG(&Erreur);

      ptr_fic = fopen(CHEMIN, "r");

      if (ptr_fic != NULL)
      {
            fscanf(ptr_fic, "%d | %s\n", &element_temp.id, cheminfichier);

            img = Lire_image(&Erreur, cheminfichier);
            img = Pre_traitement(&Erreur, img, config.Nb_Bit_Fort);
            element_temp.descripteur_image = Creation_Discripteur(&Erreur, img, config.Nb_Bit_Fort);

            dscr_image = emPILE_image(dscr_image, element_temp);

            while (!feof(ptr_fic))
            {
                  fscanf(ptr_fic, "%d | %s\n", &element_temp.id, cheminfichier);
                                    
                  img = Lire_image(&Erreur, cheminfichier);
                  img = Pre_traitement(&Erreur, img, config.Nb_Bit_Fort);
                  element_temp.descripteur_image = Creation_Discripteur(&Erreur, img, config.Nb_Bit_Fort);
                  
                  dscr_image = emPILE_image(dscr_image, element_temp);
                  
            }
            fclose(ptr_fic);
      }
      else
      {
             *erreur = 1;
      }
      return dscr_image;
}

void depiler_descripteur_image(PILE_image dscr_image, int *erreur)
{
      ELEMENT_image elementsupp;
      FILE *fichier = NULL;
      fichier = fopen("../base_descripteur/base_descripteur_image", "w");
      int total = 0;

      if (fichier != NULL)
      {
            while (dscr_image->suiv != NULL)
            {
                  dscr_image = dePILE_image(dscr_image, &elementsupp);
                  //______________________________
                  // AFFICHAGE ELEMENT DANS FICHIER
                  //________________________________
                  fprintf(fichier, "%d\n", elementsupp.id);
                  for (int i = 0; i < elementsupp.descripteur_image.Nb_Ligne; i++)
                  {
                        // Permet d'afficher q'un certain nombre de valeur
                        fprintf(fichier, "Val n %d = %d Quantity = %d\n", i, elementsupp.descripteur_image.Bilan[i][0], elementsupp.descripteur_image.Bilan[i][1]);

                        total = total + elementsupp.descripteur_image.Bilan[i][1];
                  }
                  fprintf(fichier, "\nTotal de valeur = %d\n", total);
            }
            dscr_image = dePILE_image(dscr_image, &elementsupp);
            //______________________________
            // AFFICHAGE ELEMENT DANS FICHIER
            //________________________________
            fprintf(fichier, "%d\n", elementsupp.id);
            
            for (int i = 0; i < elementsupp.descripteur_image.Nb_Ligne; i++)
            {
                  // Permet d'afficher q'un certain nombre de valeur
                  fprintf(fichier, "Val n %d = %d Quantity = %d\n", i, elementsupp.descripteur_image.Bilan[i][0], elementsupp.descripteur_image.Bilan[i][1]);

                  total = total + elementsupp.descripteur_image.Bilan[i][1];
            }
            fprintf(fichier, "\nTotal de valeur = %d\n", total);
      }
      else
      {
            *erreur = 1;
      }
      fclose(fichier);
}

PILE_texte base_descript_empiler_texte( PILE_texte  dscr_texte, int * erreur)
{

      int Erreur = 0;
      FILE *ptr_fic = NULL;
      ELEMENT_texte element_temp;
      IMAGE img;
      char CHEMIN[100] = "../liste_base/liste_base_texte";
      char cheminfichier[200];
      CONFIG config;

      config = Lire_CONFIG(&Erreur);

      ptr_fic = fopen(CHEMIN, "r");

      if (ptr_fic != NULL)
      {
            fscanf(ptr_fic, "%d | %s\n", &element_temp.id, cheminfichier);
            printf("%d | %s\n",element_temp.id, cheminfichier);
            //_______________
            // appel decriteur texte

            //______________
            element_temp.descripteur_texte=descripteur_texte_finale(cheminfichier,config.Nb_Mots_Cle,element_temp.descripteur_texte); 
            fflush(stdout);  
            dscr_texte = emPILE_texte(dscr_texte, element_temp);
            printf("hello");
            fflush(stdout);
            while (!feof(ptr_fic))
            {
                  fscanf(ptr_fic, "%d | %s\n", &element_temp.id, cheminfichier);
                         //_______________
                         // appel decriteur texte

                          //______________
                  element_temp.descripteur_texte=descripteur_texte_finale(cheminfichier,config.Nb_Mots_Cle,element_temp.descripteur_texte);     
                  dscr_texte = emPILE_texte(dscr_texte, element_temp);
                  
            }
            fclose(ptr_fic);
      }
      else
      {
            *erreur = 1;
      }
      return dscr_texte;
}

void depiler_descripteur_texte( PILE_texte  dscr_texte, int * erreur)
{
      ELEMENT_texte elementsupp;
      FILE *fichier = NULL;
      fichier = fopen("../base_descripteur/base_descripteur_texte", "w");
      int total = 0;
      CONFIG config;

      config = Lire_CONFIG(erreur);

      if (fichier != NULL)
      {
            while (dscr_texte->suiv != NULL)
            {
                  dscr_texte = dePILE_texte(dscr_texte, &elementsupp);
                  //______________________________
                  // AFFICHAGE ELEMENT DANS FICHIER
                  //________________________________
                  fprintf(fichier, "%d\n", elementsupp.id);
                  for(int x=0;x<10;x++)
                   {
                        fprintf(fichier,"%s    |    %d\n",elementsupp.descripteur_texte.tab_mot[x],elementsupp.descripteur_texte.tab_app[x]);         
                   }
                  
                  
            }
            dscr_texte = dePILE_texte(dscr_texte, &elementsupp);
            //______________________________
            // AFFICHAGE ELEMENT DANS FICHIER
            //________________________________
            fprintf(fichier, "%d\n", elementsupp.id);                            
             for(int x=0;x<10;x++)
            {
                   fprintf(fichier,"%s    |    %d\n",elementsupp.descripteur_texte.tab_mot[x],elementsupp.descripteur_texte.tab_app[x]);         
              }
            
      }
      else
      {
            *erreur = 1;
      }
      fclose(fichier);
}

// PILE_image base_descript_empiler_image( PILE_image  dscr_audio, String * erreur)
// {
//       printf("ici ?");
//       IMAGE img;
//       int erreur1;
//       DESCRIPTEUR_IMAGE di;
//       int Erreur;
//       FILE *fichier;
//        String Erreur1;
//        char CHEMIN[700];
//        CONFIG config;
//        ELEMENT_image element_image;
//        printf("ici ?");
//        config = Lire_CONFIG(&erreur1);
//        //config= Lire_nb_fenetre(config,&Erreur);
//       //Lis et verifie la validiter de la valeur de l'intervale
//        //config= Lire_intervale(config,&Erreur);
//        printf("ici .. ?\n\n");
//        fflush(stdout);
//       fichier = fopen("../liste_base/liste_base_audio", "r");
//        if (fichier != NULL)
//        {
//             fscanf(fichier, "%d | %s", &element_image.id ,CHEMIN);
//              printf("%d | %s\n",element_image.id ,CHEMIN);
//             fflush(stdout);
//             img = Lire_image(&Erreur,CHEMIN);
//             img = Pre_traitement(&Erreur,img,config.Nb_Bit_Fort);
//             di = Creation_Discripteur(&Erreur,img,config.Nb_Bit_Fort);
//             fflush(stdout);
//             //affiche_ELEMENT_audio(element_audio);
//             fflush(stdout);
//             dscr_audio= emPILE_image(dscr_audio, element_image);
//             printf("%d | %s ", dscr_audio->element.id, CHEMIN);
//             while (!feof(fichier))
//             {
//                   printf("ouverture fichier");
//                   fflush(stdout);
//                   printf("%s\n",CHEMIN);
//                   fflush(stdout);
//                   //element_audio.descripteur = Descripteur_audio(2048 , 32,CHEMIN, element_audio.descripteur) ;
//                   printf("je suis la");
//                   fflush(stdout);
//                   //affect_ELEMENT_audio(&(dscr_audio->element),element_audio);
//                   dscr_audio= emPILE_image(dscr_audio, element_image);
//                   //affiche_ELEMENT_audio((*dscr_audio)->element);
//                   fscanf(fichier, "%d | %s\n", &element_image.id ,CHEMIN);

//             }
//             fclose(fichier);
//        }
//         else
//        {
//          strcpy(*erreur,"Erreur : Fichier liste base introuvable");
//       }

//     return dscr_audio;
//       //       printf("Michel");
//       //       printf("%p",pourchemin);
//       //      //mettre a jour le descripteur a empiler
//       //      printf("%s",pourchemin->element.CHEMIN);
//       //      element_audio.descripteur=Descripteur_audio( 4096 , 15,pourchemin->element.CHEMIN, element_audio.descripteur) ;
//       //      //mettre a jour le id a empiler
//       //      element_audio.id=pourchemin->element.id;
//       //      printf("id : %d , chemin : %s",element_audio.id,pourchemin->element.CHEMIN);
//       //      //empiler
//       //      *dscr_audio= emPILE_audio(*dscr_audio, element_audio);
//       //      pourchemin= pourchemin->suiv;
//        //}
// }