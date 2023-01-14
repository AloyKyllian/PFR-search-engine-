//
// AUTEUR :
//          YASMINE ALLAL
// DERNIERE VERSION :
//    12/01/2023

#include "indexation_gene.h"

//____________________________________________
// Recupere le chemin des fichiers dans DATA dans une pile
//____________________________________________
void recup_path(PILE *pourchemin, int deb, String path, String type, int *erreur)
{
      ELEMENT element;
      String nom_fic, chemin;
      char commande[500];
      FILE *ptr_fic;
      /*------------------------------------------------------*/
      /* RECUPERATION DU CONTENU DU REPERTOIRE  CHEMIN        */
      /*------------------------------------------------------*/
      strcpy(commande, "ls -ltu ");
      strcat(commande, path);

      if (strcmp(type, "texte") == 0) // recuperer chemin pour fichier texte
            strcat(commande, " > fic_temp");
      else // recuperer chemin pour fichier .txt audio et image
            strcat(commande, " | grep \".txt\" > fic_temp");

      /*---------------------------------------------------------------------*/
      /* AFFICHAGE DU CONTENU DU FICHIER CREE LORS DE LA PRECEDENTE COMMANDE */
      /*---------------------------------------------------------------------*/
      system(commande);

      /* ouverture du fichier temporaire fic_temp*/
      ptr_fic = fopen("fic_temp", "r");

      if (ptr_fic != NULL)
      {
            if (strcmp(type, "texte") == 0)
                  fscanf(ptr_fic, "%*s %*s"); /* SAUTER LA PREMIERE LIGNE CONSTITUEE DE 2 CHAINES total xxxx */

            fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", nom_fic); /* %*s INGNORE LA CHAINE LUE */
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
      }
      else
      {
            *erreur = 7;
      }
      fclose(ptr_fic);
}

//____________________________________________
// depiler le chemin de le fichier liste_base_texte ou liste _base_audio ou liste_base_image
//____________________________________________
void depiler_path(PILE *pourchemin, char *path, int *erreur)
{
      ELEMENT elementsupp;
      FILE *fichier = NULL;
      fichier = fopen(path, "w");

      if (fichier != NULL)
      {
            while ((*pourchemin)->suiv != NULL)
            {
                  *pourchemin = dePILE(*pourchemin, &elementsupp);
                  fprintf(fichier, "-%d |%s\n", elementsupp.id, elementsupp.CHEMIN);
            }
            *pourchemin = dePILE(*pourchemin, &elementsupp);
            fprintf(fichier, "-%d |%s", elementsupp.id, elementsupp.CHEMIN);
      }
      else
      {
            *erreur = 7;
      }
      fclose(fichier);
}

//____________________________________________
// EMPILE LEs DESCRIPTEUR AUDIO AVEC leur ID DANS UNE PILE
//____________________________________________
PILE_audio base_descript_empiler_audio(PILE_audio dscr_audio, int *erreur, int *erreur_audio, CONFIG config)
{
      int id;
      int ligne;
      FILE *ptr_fic = NULL;
      ELEMENT_audio element_temp;
      char CHEMIN[100] = "../liste_base/liste_base_audio";
      char cheminfichier[200];
      ptr_fic = fopen(CHEMIN, "r");
      if (ptr_fic != NULL)
      {
            while (!feof(ptr_fic))
            {
                  printf("debut du while\n");
                  fscanf(ptr_fic, "-%d | %s\n", &element_temp.id, cheminfichier);
                  printf("-%d | %s\n", element_temp.id, cheminfichier);
                  fflush(stdout);
                  element_temp.descripteur = Descripteur_audio(config.Nb_Fenetre, config.Intervale, cheminfichier, erreur_audio);
                  printf("EMPILE : NOMBRE DE LIGNE : %d\n",element_temp.descripteur.ligne);
                  fflush(stdout);
                  if (*erreur_audio == 0)
                  {
                        dscr_audio = emPILE_audio(dscr_audio, element_temp);
                  }
                  id = element_temp.id;

                  printf("fin du while\n");
                  fflush(stdout);
            }

            fclose(ptr_fic);
      }
      else
      {
            *erreur = 7;
      }
      return dscr_audio;
}

//____________________________________________
// DEPILE LES DESCRIPTEURS AUDIO DANS LE FICHIER BASE_DESCRIPTEUR
//____________________________________________
void depiler_descripteur_audio(PILE_audio dscr_audio, int *erreur, int erreur_audio)
{
      ELEMENT_audio elementsupp;
      FILE *fichier = NULL;
      fichier = fopen("../base_descripteur/base_descripteur_audio", "w");
      if (erreur_audio == 0)
      {
            if (fichier != NULL)
            {
                  while (dscr_audio != NULL)
                  {

                        dscr_audio = dePILE_audio(dscr_audio, &elementsupp);
                        //______________________________
                        // AFFICHAGE ELEMENT DANS FICHIER
                        //_______________________________
                        printf("DEPILE : NOMBRE DE LIGNE : %d\n",elementsupp.descripteur.ligne);
                        fprintf(fichier, "-%d %d\n", elementsupp.id, elementsupp.descripteur.ligne);
                        for (unsigned i = 0; i < elementsupp.descripteur.ligne; ++i)
                        {
                              for (unsigned j = 0; j < elementsupp.descripteur.colonne; ++j)
                              {
                                    fprintf(fichier, " %d ", elementsupp.descripteur.tab[i][j]);
                              }
                              fprintf(fichier, "\r\n");
                        }

                        for (int i = 0; i < elementsupp.descripteur.ligne; i++) // creation des colonne du tableau
                        {
                              free(elementsupp.descripteur.tab[i]);
                        }
                        free(elementsupp.descripteur.tab);
                  }
            }
            else
            {
                  *erreur = 7;
            }
      }
      fclose(fichier);
}

//____________________________________________
// EMPILE LEs DESCRIPTEUR AUDIO AVEC leur ID DANS UNE PILE
//____________________________________________
PILE_image base_descript_empiler_image(PILE_image dscr_image, int *erreur, int *erreur_image, CONFIG config)
{
      FILE *ptr_fic = NULL;
      ELEMENT_image element_temp;
      char CHEMIN[100] = "../liste_base/liste_base_image/NB";
      char cheminfichier[200];

      ptr_fic = fopen(CHEMIN, "r");

      if (ptr_fic != NULL)
      {
            fscanf(ptr_fic, "-%d | %s\n", &element_temp.id, cheminfichier);

            element_temp.descripteur_image = Pack_Descripteur_image(erreur_image, cheminfichier, config.Nb_Bit_Fort);
            if (*erreur_image == 0)
            {
                  dscr_image = emPILE_image(dscr_image, element_temp);

                  while (!feof(ptr_fic))
                  {
                        fscanf(ptr_fic, "-%d | %s\n", &element_temp.id, cheminfichier);
                        element_temp.descripteur_image = Pack_Descripteur_image(erreur_image, cheminfichier, config.Nb_Bit_Fort);
                        if (*erreur_image == 0)
                        {
                              dscr_image = emPILE_image(dscr_image, element_temp);
                        }
                        else
                              break;
                  }
            }
      }
      else
      {
            *erreur = 7;
      }
      fclose(ptr_fic);

      strcpy(CHEMIN, "../liste_base/liste_base_image/RGB");
      FILE *fichier = NULL;
      fichier = fopen(CHEMIN, "r");

      if (fichier != NULL)
      {
            fscanf(fichier, "-%d | %s\n", &element_temp.id, cheminfichier);

            element_temp.descripteur_image = Pack_Descripteur_image(erreur_image, cheminfichier, config.Nb_Bit_Fort);
            if (*erreur_image == 0)
            {
                  dscr_image = emPILE_image(dscr_image, element_temp);

                  while (!feof(fichier))
                  {
                        fscanf(fichier, "-%d | %s\n", &element_temp.id, cheminfichier);
                        element_temp.descripteur_image = Pack_Descripteur_image(erreur_image, cheminfichier, config.Nb_Bit_Fort);
                        if (*erreur_image == 0)
                        {
                              dscr_image = emPILE_image(dscr_image, element_temp);
                        }
                        else
                              break;
                  }
            }
      }
      else
      {
            *erreur = 7;
      }
      fclose(fichier);
      return dscr_image;
}

//____________________________________________
// DEPILE LES DESCRIPTEURS AUDIO DANS LE FICHIER BASE_DESCRIPTEUR
//____________________________________________
void depiler_descripteur_image(PILE_image dscr_image, int erreur_image, int *erreur)
{
      ELEMENT_image elementsupp;
      FILE *fichier = NULL;
      fichier = fopen("../base_descripteur/base_descripteur_image", "w");
      int total = 0;
      if (erreur_image == 0)
      {
            if (fichier != NULL)
            {
                  while (dscr_image != NULL)
                  {
                        dscr_image = dePILE_image(dscr_image, &elementsupp);
                        //______________________________
                        // AFFICHAGE ELEMENT DANS FICHIER
                        //________________________________
                        fprintf(fichier, "-%d\n", elementsupp.id);
                        for (int i = 0; i < elementsupp.descripteur_image.Nb_Ligne; i++)
                        {
                              // Permet d'afficher q'un certain nombre de valeur
                              fprintf(fichier, "%d %d\n", elementsupp.descripteur_image.Bilan[i][0], elementsupp.descripteur_image.Bilan[i][1]);

                              total = total + elementsupp.descripteur_image.Bilan[i][1];
                        }
                        for (int i = 0; i < elementsupp.descripteur_image.Nb_Ligne; i++)
                        {
                              free(elementsupp.descripteur_image.Bilan[i]);
                        }
                        free(elementsupp.descripteur_image.Bilan);
                  }
            }
            else
            {
                  *erreur = 7;
            }
      }

      fclose(fichier);
}

//____________________________________________
// EMPILE LEs DESCRIPTEUR AUDIO AVEC leur ID DANS UNE PILE
//____________________________________________
PILE_texte base_descript_empiler_texte(PILE_texte dscr_texte, int *erreur, CONFIG config)
{

      int Erreur = 0;
      FILE *ptr_fic = NULL;
      ELEMENT_texte element_temp;
      IMAGE img;
      char CHEMIN[100] = "../liste_base/liste_base_texte";
      char cheminfichier[200];

      ptr_fic = fopen(CHEMIN, "r");

      if (ptr_fic != NULL)
      {
            fscanf(ptr_fic, "-%d | %s\n", &element_temp.id, cheminfichier);
            element_temp.descripteur_texte = descripteur_texte_finale(cheminfichier, config.Nb_Mots_Cle, element_temp.descripteur_texte);

            dscr_texte = emPILE_texte(dscr_texte, element_temp);

            while (!feof(ptr_fic))
            {
                  fscanf(ptr_fic, "-%d | %s\n", &element_temp.id, cheminfichier);
                  element_temp.descripteur_texte = descripteur_texte_finale(cheminfichier, config.Nb_Mots_Cle, element_temp.descripteur_texte);
                  dscr_texte = emPILE_texte(dscr_texte, element_temp);
            }
      }
      else
      {
            *erreur = 7;
      }
      fclose(ptr_fic);
      return dscr_texte;
}

//____________________________________________test
// DEPILE LES DESCRIPTEURS AUDIO DANS LE FICHIER BASE_DESCRIPTEUR
//____________________________________________
void depiler_descripteur_texte(PILE_texte dscr_texte, int *erreur, CONFIG config)
{
      ELEMENT_texte elementsupp;
      FILE *fichier = NULL;
      fichier = fopen("../base_descripteur/base_descripteur_texte", "w");
      int total = 0;
      if (fichier != NULL)
      {
            while (dscr_texte != NULL)
            {
                  dscr_texte = dePILE_texte(dscr_texte, &elementsupp);
                  //______________________________
                  // AFFICHAGE ELEMENT DANS FICHIER
                  //________________________________
                  fprintf(fichier, "-%d\n", elementsupp.id);
                  // affichage descripteur
                  for (int x = 0; x < config.Nb_Mots_Cle; x++)
                  {
                        fprintf(fichier, "%s    |    %d\n", elementsupp.descripteur_texte.tab_mot[x], elementsupp.descripteur_texte.tab_app[x]);
                  }

                  free(elementsupp.descripteur_texte.tab_mot);
                  free(elementsupp.descripteur_texte.tab_app);
            }
      }
      else
      {
            *erreur = 7;
      }
      fclose(fichier);
}

//____________________________________________
// Recupere le chemin de tous les fichiers audio, image, texte et le depile dans les fichiers liste_base_audio/image/texte
//____________________________________________
void recuperer_path_tous_fichiers(int *Erreurtexte, int *Erreuraudio, int *Erreurimage)
{
      PILE piletexte_path = init_PILE();
      PILE pileimage_path = init_PILE();
      PILE pileaudio_path = init_PILE();
      String path;
      int deb = 0;
      //_________________
      // TEXTE
      //_________________
      strcpy(path, "../DATA_FIL_ROUGE_DEV/Textes/");
      recup_path(&piletexte_path, deb, path, "texte", Erreurtexte);
      depiler_path(&piletexte_path, "../liste_base/liste_base_texte", Erreurtexte);

      //_________________
      // AUDIO
      //_________________
      strcpy(path, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/");
      recup_path(&pileaudio_path, deb, path, "audio", Erreuraudio);
      depiler_path(&pileaudio_path, "../liste_base/liste_base_audio", Erreuraudio);

      //_________________
      // IMAGE
      //_________________
      strcpy(path, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB/");
      recup_path(&pileimage_path, deb, path, "image", Erreurimage);
      deb = (pileimage_path->element.id) + 1;
      depiler_path(&pileimage_path, "../liste_base/liste_base_image/RGB", Erreurimage);
      strcpy(path, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB/");
      recup_path(&pileimage_path, deb, path, "image", Erreurimage);
      depiler_path(&pileimage_path, "../liste_base/liste_base_image/NB", Erreurimage);
}

void indexation_generale_ferme(CONFIG config, int *Erreurimage, int *Erreuraudio, int *Erreurtexte, int *Erreur)
{
      recuperer_path_tous_fichiers(Erreurtexte, Erreuraudio, Erreurimage);

      PILE_image pileimage = NULL;
      pileimage = base_descript_empiler_image(pileimage, Erreur, Erreurimage, config);
      depiler_descripteur_image(pileimage, *Erreurimage, Erreur);

      PILE_audio descripteur_audio = NULL;
      descripteur_audio = base_descript_empiler_audio(descripteur_audio, Erreur, Erreuraudio, config);
      depiler_descripteur_audio(descripteur_audio, Erreur, *Erreuraudio);

      // PILE_texte piletexte = NULL;
      // piletexte = base_descript_empiler_texte(piletexte, Erreurtexte, config);
      // depiler_descripteur_texte(piletexte, Erreurtexte, config);
}

void indexation_ouverte(CONFIG config, String type, int *Erreurimage, int *Erreuraudio, int *Erreurtexte, int *Erreur)
{

      String recupchemin;
      String commande;

      String cheminliste;
      String cheminDATA;
      if (strcmp(type, "rgb") == 0)
      {
            strcpy(cheminliste, "../liste_base/liste_base_image/RGB");
            strcpy(cheminDATA, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB/*.txt");
      }
      if (strcmp(type, "nb") == 0)
      {
            strcpy(cheminliste, "../liste_base/liste_base_image/NB");
            strcpy(cheminDATA, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB/*.txt");
      }
      if (strcmp(type, "texte") == 0)
      {
            strcpy(cheminliste, "../liste_base/liste_base_texte");
            strcpy(cheminDATA, "../DATA_FIL_ROUGE_DEV/Textes");
      }
      if (strcmp(type, "audio") == 0)
      {
            strcpy(cheminliste, "../liste_base/liste_base_audio");
            strcpy(cheminDATA, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/*.txt");
      }

      strcpy(commande, "ls -ltur ");
      strcat(commande, cheminDATA);
      strcat(commande, "> traitement/fic_temp");
      system(commande);

      strcpy(commande, "cut -d '/' -f 5 traitement/fic_temp > traitement/fic");
      system(commande);

      strcpy(commande, "cut -d '/' -f 5 ");
      strcat(commande, cheminliste);
      strcat(commande, " > traitement/ListeDejaIndexeTemp");
      system(commande);

      strcpy(commande, "diff traitement/ListeDejaIndexeTemp traitement/fic  > traitement/diff");
      system(commande);

      FILE *fichier_first = NULL;
      PILE cheminnewfile = init_PILE();
      ELEMENT element_temp;
      String val;

      fichier_first = fopen("traitement/diff", "r");
      if (fichier_first != NULL)
      {
            if (fscanf(fichier_first, "%s", val) == EOF)
            {
                  printf("AUCUN FICHIER NA ETE AJOUTER ni SUPPRIMER dans %s\n", type);
                  fflush(stdout);
            }
            else
            {
                  while (!feof(fichier_first))
                  {
                        fscanf(fichier_first, "%s", val);
                        if (strstr("> ", val))
                        {
                              fscanf(fichier_first, "%s", val);
                              printf("%s   FIN\n", val);
                              fflush(stdout);
                              printf("AVANT AJOUT FICHIER: \ttype: %s val: %s\n",type,val);
                              fflush(stdout);
                              ajoutfichier(config, type, val, Erreur);
                              //  appeler fonction ajout d'un fichier
                        }
                        if (strstr("< ", val))
                        {
                              fscanf(fichier_first, "%s", val);
                              printf("%s   FIN\n",val);
                              fflush(stdout);
                              // appeler fonction pour supprimer
                        }
                  }
            }
      }
      else
      {
            *Erreur = 7;
      }
      fclose(fichier_first);
}

void ajoutfichier(CONFIG config, String type, String chemin, int *Erreur)
{

      String cheminliste;
      String cheminDATA;
      if (strcmp(type, "rgb") == 0)
      {
            strcpy(cheminliste, "../liste_base/liste_base_image/RGB");
            strcpy(cheminDATA, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB/");
      }
      if (strcmp(type, "nb") == 0)
      {
            strcpy(cheminliste, "../liste_base/liste_base_image/NB");
            strcpy(cheminDATA, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB/");
      }
      if (strcmp(type, "texte") == 0)
      {
            strcpy(cheminliste, "../liste_base/liste_base_texte");
            strcpy(cheminDATA, "../DATA_FIL_ROUGE_DEV/Textes/");
      }
      if (strcmp(type, "audio") == 0)
      {
            strcpy(cheminliste, "../liste_base/liste_base_audio");
            strcpy(cheminDATA, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/");
      }

      // ajout fichier dans liste_base
      int id = recupererDernierID(type, Erreur);

      FILE *fichier = NULL;
      String temp;

      fichier = fopen("traitement/fic", "w");
      ELEMENT elementsupp;
      strcpy(temp, cheminDATA);
      strcat(temp, chemin);
      printf("CHEMIN : %s ", temp);

      if (fichier != NULL)
      {
            fprintf(fichier, "\n-%d |%s", id, temp);
      }

      else
      {
            *Erreur = 7;
      }
      fclose(fichier);

      String commande;

      strcpy(commande, "cat traitement/fic >> ");
      strcat(commande, cheminliste);
      system(commande);
      //__________________________________
      // ajout descripteur dans la base
      //__________________________________

      if (strcmp(type, "rgb") == 0 || strcmp(type, "nb") == 0)
      {
            DESCRIPTEUR_IMAGE descripteur_image;
            int total;

            descripteur_image = Pack_Descripteur_image(Erreur, temp, config.Nb_Bit_Fort);

            FILE *fichier2 = NULL;

            fichier2 = fopen("traitement/fic", "w");
            if (fichier2 != NULL)
            {
                  fprintf(fichier2, "-%d\n", id);
                  for (int i = 0; i < descripteur_image.Nb_Ligne; i++)
                  {
                        // Permet d'afficher q'un certain nombre de valeur
                        fprintf(fichier2, "%d %d\n", descripteur_image.Bilan[i][0], descripteur_image.Bilan[i][1]);

                        total = total + descripteur_image.Bilan[i][1];
                  }
                  for (int i = 0; i < descripteur_image.Nb_Ligne; i++)
                  {
                        free(descripteur_image.Bilan[i]);
                  }
                  free(descripteur_image.Bilan);
            }
            fclose(fichier2);
            strcpy(commande, "cat traitement/fic >> ../base_descripteur/base_descripteur_image");
      }

      if (strcmp(type, "texte") == 0)
      {
            DESCRIPTEUR_TEXTE descripteur_texte;
            descripteur_texte = descripteur_texte_finale(temp, config.Nb_Mots_Cle, descripteur_texte);

            FILE *fichier2 = NULL;

            fichier2 = fopen("traitement/fic", "w");
            if (fichier2 != NULL)
            {
                  fprintf(fichier2, "-%d\n", id);
                  for (int x = 0; x < config.Nb_Mots_Cle; x++)
                  {
                        fprintf(fichier, "\n%s    |    %d", descripteur_texte.tab_mot[x], descripteur_texte.tab_app[x]);
                  }

                  free(descripteur_texte.tab_mot);
                  free(descripteur_texte.tab_app);
            }
            fclose(fichier2);
            strcpy(commande, "cat traitement/fic >> ../base_descripteur/base_descripteur_texte");
      }

      if (strcmp(type, "audio") == 0)
      {

            descri_audio descripteur;
            descripteur = Descripteur_audio(config.Nb_Fenetre, config.Intervale, temp, Erreur);

            FILE *fichieraudio = NULL;

            fichieraudio = fopen("traitement/fic", "w");
            if (fichieraudio != NULL)
            {
                  fprintf(fichieraudio, "-%d %d\n", id, descripteur.ligne);
                  for (unsigned i = 0; i < descripteur.ligne; ++i)
                  {
                        for (unsigned j = 0; j < descripteur.colonne; ++j)
                        {
                              fprintf(fichieraudio, " %d ", descripteur.tab[i][j]);
                        }
                        fprintf(fichieraudio, "\r\n");
                  }
            }
            fclose(fichieraudio);

            for (int i = 0; i < descripteur.ligne; i++) // creation des colonne du tableau
            {
                  free(descripteur.tab[i]);
            }
            free(descripteur.tab);

            strcpy(commande, "cat traitement/fic >> ../base_descripteur/base_descripteur_audio");
            system(commande);
      }
}

int recupererDernierID(String type, int *Erreur)
{
      FILE *fichier2;
      int id[2];
      int id_finale =0;
      String commande;

      if (strcmp(type, "rgb") == 0 || strcmp(type, "nb") == 0)
      {
            strcpy(commande,"wc -l ../liste_base/liste_base_image/RGB > traitement/id");
            system(commande);
            strcpy(commande,"wc -l ../liste_base/liste_base_image/NB >> traitement/id");
            system(commande);           
            fichier2 = fopen("traitement/id", "r");
            if (fichier2 != NULL)
            {     
                  for (int i=0 ; i<2;i++)
                        {
                            fscanf(fichier2, "%d %*s", &(id[i]));  
                        } 
            }
            else
            {
                  *Erreur = 7;
            }
            fclose(fichier2);
            id_finale= id[0]+id[1];
            return id_finale;
      }

      if (strcmp(type, "texte") == 0)
      {
            FILE *fichier3;
            strcpy(commande,"wc -l ../liste_base/liste_base_texte > traitement/id");
            system(commande);
            fichier3 = fopen("traitement/id", "r");
            if (fichier2 != NULL)
            {
                  fscanf(fichier3, "%d ", &id_finale);
            }
            else
            {
                  *Erreur = 7;
            }
            fclose(fichier3);

            return id_finale ;
      }

      if (strcmp(type, "audio") == 0)
      {
            FILE *fichier3;
            strcpy(commande,"wc -l ../liste_base/liste_base_audio > traitement/id");
            system(commande);
            fichier3 = fopen("traitement/id", "r");
            if (fichier2 != NULL)
            {
                  fscanf(fichier3, "%d ", &id_finale);
            }
            else
            {
                  *Erreur = 7;
            }
            fclose(fichier3);

            return id_finale ;
      }
      return id_finale ;
}

void indexation(CONFIG config, int *Erreurimage, int *Erreuraudio, int *Erreurtexte, int *Erreur)
{
      FILE *fichier_texte = NULL;
      String val;

      String path;
      int deb = 0;

      // fichier_texte = fopen("../liste_base/liste_base_texte", "r");
      // if (fichier_texte != NULL)
      // {
      //       if (fscanf(fichier_texte, "%s", val) == EOF)
      //       {
      //             indexation_texte(config,Erreur, Erreurtexte);
      //             fclose(fichier_texte);
      //       }
      //       else
      //       {
      //             fclose(fichier_texte);
      //             indexation_ouverte(config, "texte", Erreurimage, Erreuraudio, Erreurtexte, Erreur);
      //       }
      // }
      // else
      // {
      //       *Erreur = 7;
      // }
      FILE *fichier_nb = NULL;
      deb = 0;

      fichier_nb = fopen("../liste_base/liste_base_image/NB", "r");
      if (fichier_nb != NULL)
      {
            if (fscanf(fichier_nb, "%s", val) == EOF)
            {
                  indexation_image(config, Erreur, Erreurimage);
                  fclose(fichier_nb);
            }
            else
            {
                  fclose(fichier_nb);
                  indexation_ouverte(config, "nb", Erreurimage, Erreuraudio, Erreurtexte, Erreur);
            }
      }
      else
      {
            *Erreur = 7;
      }
      FILE *fichier_rgb = NULL;
      deb = 0;

      fichier_rgb = fopen("../liste_base/liste_base_image/RGB", "r");
      if (fichier_rgb != NULL)
      {
            if (fscanf(fichier_rgb, "%s", val) == EOF)
            {
                  indexation_image(config, Erreur, Erreurimage);
                  fclose(fichier_rgb);
            }
            else
            {
                  fclose(fichier_rgb);
                  indexation_ouverte(config, "rgb", Erreurimage, Erreuraudio, Erreurtexte, Erreur);
            }
      }
      else
      {
            *Erreur = 7;
      }
      FILE *fichier_son = NULL;
      deb = 0;

      fichier_son = fopen("../liste_base/liste_base_audio", "r");
      if (fichier_son != NULL)
      {
            if (fscanf(fichier_son, "%s", val) == EOF)
            {
                  indexation_audio(config, Erreur, Erreuraudio);
                  fclose(fichier_son);
            }
            else
            {
                  fclose(fichier_son);
                  indexation_ouverte(config, "audio", Erreurimage, Erreuraudio, Erreurtexte, Erreur);
            }
      }
      else
      {
            *Erreur = 7;
      }
}

void indexation_audio(CONFIG config, int *Erreur, int *Erreuraudio)
{
      int deb = 0;
      String path;
      //___________________________________________________
      // indexation de tous les fichiers audios
      //___________________________________________________
      PILE pileaudio_path = init_PILE();
      //___________________________________________________
      // remplier liste_base_audio
      //___________________________________________________
      strcpy(path, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/");
      recup_path(&pileaudio_path, deb, path, "audio", Erreuraudio);
      depiler_path(&pileaudio_path, "../liste_base/liste_base_audio", Erreuraudio);
      //___________________________________________________
      // remplier base_descripteur_audio
      //___________________________________________________
      PILE_audio descripteur_audio = NULL;
      printf("avant empile");
      fflush(stdout);
      descripteur_audio = base_descript_empiler_audio(descripteur_audio, Erreur, Erreuraudio, config);
      printf("HELLOOOOO");
      fflush(stdout);
      depiler_descripteur_audio(descripteur_audio, Erreur, *Erreuraudio);
      printf("apresdepil");
      fflush(stdout);
}
void indexation_texte(CONFIG config, int *Erreur, int *Erreurtexte)
{
      int deb = 0;
      String path;
      //___________________________________________________
      // indexation de tous les fichiers textes
      //___________________________________________________
      PILE piletexte_path = init_PILE();
      //___________________________________________________
      // remplier liste_base_texte
      //___________________________________________________
      strcpy(path, "../DATA_FIL_ROUGE_DEV/Textes/");
      recup_path(&piletexte_path, deb, path, "texte", Erreurtexte);
      depiler_path(&piletexte_path, "../liste_base/liste_base_texte", Erreurtexte);
      //___________________________________________________
      // remplier base_descripteur_texte
      //___________________________________________________
      PILE_texte piletexte = NULL;
      piletexte = base_descript_empiler_texte(piletexte, Erreurtexte, config);
      depiler_descripteur_texte(piletexte, Erreurtexte, config);
}
void indexation_image(CONFIG config, int *Erreur, int *Erreurimage)
{
      int deb = 0;
      String path;
      //___________________________________________________
      // indexation de tous les fichiers images
      //___________________________________________________

      //___________________________________________________
      // remplier liste_base_image
      //___________________________________________________
      PILE pileimage_path = init_PILE();
      strcpy(path, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB/");
      recup_path(&pileimage_path, deb, path, "image", Erreurimage);
      deb = (pileimage_path->element.id) + 1;
      depiler_path(&pileimage_path, "../liste_base/liste_base_image/RGB", Erreurimage);
      strcpy(path, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB/");
      recup_path(&pileimage_path, deb, path, "image", Erreurimage);
      depiler_path(&pileimage_path, "../liste_base/liste_base_image/NB", Erreurimage);
      //___________________________________________________
      // remplier base_descripteur_image
      //___________________________________________________
      PILE_image pileimage = NULL;
      pileimage = base_descript_empiler_image(pileimage, Erreur, Erreurimage, config);
      depiler_descripteur_image(pileimage, *Erreurimage, Erreur);

      printf("FIN IMAGE");
      fflush(stdout);
}