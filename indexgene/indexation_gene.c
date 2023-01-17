//
// AUTEUR :
//          YASMINE ALLAL
// DERNIERE VERSION :
//    15/01/2023
//
// Fonction Supprimer_Descripteur developpe par Loic Maignan

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
      // -l affichage detaille
      // -tu pour affichage chronologique
      strcpy(commande, "ls -ltu ");
      strcat(commande, path);

      if (strcmp(type, "texte") == 0) // recuperer chemin pour fichier texte
            strcat(commande, " > fic_temp");
      else // recuperer chemin pour fichier .txt audio et image
            strcat(commande, " | grep \".txt\" > fic_temp");

      /* Execution de la commande ls -ltu ... > fic_temp*/
      /* pour texte ajouter "| grep \".txt\" > fic_temp" */
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
                  // concatener le path avec nom_fic pour avoir le chemin de chaque fichier
                  strcpy(chemin, path);
                  strcat(chemin, nom_fic);
                  // assign an id to each file
                  element.id = deb;
                  strcpy(element.CHEMIN, chemin);

                  // empile lelement dans une pile
                  //  element avec lid et le chemin du fichier
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

void depiler_path(PILE *pourchemin, char *path, int *erreur)
{
      ELEMENT elementsupp;
      FILE *fichier = NULL;
      /**
       * ouvrir le fichier liste_base/liste_base_ ... (texte, audio, nb our rgb)
       * depile la pile des chemins avec lid
       * lecris dans le fichier
       */
      fichier = fopen(path, "w");

      if (fichier != NULL)
      {
            while ((*pourchemin)->suiv != NULL)
            {
                  *pourchemin = dePILE(*pourchemin, &elementsupp);
                  fprintf(fichier, "-%d |%s\n", elementsupp.id, elementsupp.CHEMIN);
            }
            /**
             * pour le dernier element empile on ne saute pas de ligne
             */
            *pourchemin = dePILE(*pourchemin, &elementsupp);
            fprintf(fichier, "-%d |%s", elementsupp.id, elementsupp.CHEMIN);
      }
      else
      {
            *erreur = 7;
      }
      fclose(fichier);
}

PILE_audio base_descript_empiler_audio(PILE_audio dscr_audio, int *erreur, int *erreur_audio, CONFIG config)
{
      int id = 0;
      int ligne = 0;
      FILE *ptr_fic = NULL;
      ELEMENT_audio element_temp;

      // le chemin du fichier pour recuperer lid et son chemin
      char CHEMIN[100] = "../liste_base/liste_base_audio";
      char cheminfichier[200];

      ptr_fic = fopen(CHEMIN, "r");
      if (ptr_fic != NULL)
      {
            while (!feof(ptr_fic))
            {
                  // recuperer lid et son chemin
                  fscanf(ptr_fic, "-%d | %s\n", &element_temp.id, cheminfichier);
                  // recupere le descripteur avec la fonction developpé par Aloy Kyllian
                  element_temp.descripteur = Descripteur_audio(config.Nb_Fenetre, config.Intervale, cheminfichier, erreur_audio);
                  // si elle ne renvoie pas d'erreur on empile l'element
                  if (*erreur_audio == 0)
                        dscr_audio = emPILE_audio(dscr_audio, element_temp);
                  // sinon sortir de la boucle et renvoie l'erreur au main
                  else
                        break;
            }
      }
      else
      {
            *erreur = 7;
      }
      fclose(ptr_fic);
      return dscr_audio;
}

void depiler_descripteur_audio(PILE_audio dscr_audio, int *erreur, int erreur_audio)
{
      ELEMENT_audio elementsupp;
      FILE *fichier = NULL;
      bool first = true;

      // chemin ou depiler le fichier
      fichier = fopen("../base_descripteur/base_descripteur_audio", "w");

      // si la fonction empiler descripteur audio s'est  bien passé, on le depile sur le fichier base_descripteur
      if (erreur_audio == 0)
      {
            if (fichier != NULL)
            {
                  // depile la pile jusqu'elle soit vide
                  while (dscr_audio != NULL)
                  {

                        dscr_audio = dePILE_audio(dscr_audio, &elementsupp);

                        //______________________________
                        // AFFICHAGE DESCRIPTEUR ET ID DANS FICHIER

                        //__affichage id
                        // ne pas sauter de ligne que pour le premier fichier ajoute
                        if (first == true)
                        {
                              fprintf(fichier, "-%d %d\n", elementsupp.id, elementsupp.descripteur.ligne);
                              first = false;
                        }
                        else
                              fprintf(fichier, "\n-%d %d\n", elementsupp.id, elementsupp.descripteur.ligne);

                        //__affichage du descripteur
                        for (unsigned i = 0; i < elementsupp.descripteur.ligne; ++i)
                        {
                              for (unsigned j = 0; j < elementsupp.descripteur.colonne; ++j)
                              {
                                    fprintf(fichier, " %d ", elementsupp.descripteur.tab[i][j]);
                              }
                              // ne pas sauter de ligne pour le dernier ajoute
                              if (i < elementsupp.descripteur.ligne - 1)
                                    fprintf(fichier, "\r\n");
                        }

                        // free les elements du descripteur audio
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

PILE_image base_descript_empiler_image(PILE_image dscr_image, int *erreur, int *erreur_image, CONFIG config)
{
      FILE *ptr_fic = NULL;
      ELEMENT_image element_temp;

      // le chemin du fichier pour recuperer lid et son chemin dans le dossier NB
      char CHEMIN[100] = "../liste_base/liste_base_image/NB";
      char cheminfichier[200];

      ptr_fic = fopen(CHEMIN, "r");

      if (ptr_fic != NULL)
      {
            while (!feof(ptr_fic))
            {
                  // lire lid et son chemin
                  fscanf(ptr_fic, "-%d | %s\n", &element_temp.id, cheminfichier);
                  // recupere le descripteur avec la fonction developpé par Loic Maignan
                  element_temp.descripteur_image = Pack_Descripteur_image(erreur_image, cheminfichier, config.Nb_Bit_Fort);
                  if (*erreur_image == 0)
                  {
                        dscr_image = emPILE_image(dscr_image, element_temp);
                  }
                  else
                        break;
            }
      }

      else
      {
            *erreur = 7;
      }
      fclose(ptr_fic);

      // le chemin du fichier pour recuperer lid et son chemin dans le dossier RGB
      strcpy(CHEMIN, "../liste_base/liste_base_image/RGB");
      FILE *fichier = NULL;
      fichier = fopen(CHEMIN, "r");

      if (fichier != NULL)
      {
            while (!feof(fichier))
            {
                  // recupere lid et le chemin
                  fscanf(fichier, "-%d | %s\n", &element_temp.id, cheminfichier);
                  // recupere le descripteur avec la fonction developpé par Loic Maignan
                  element_temp.descripteur_image = Pack_Descripteur_image(erreur_image, cheminfichier, config.Nb_Bit_Fort);
                  if (*erreur_image == 0)
                  {
                        dscr_image = emPILE_image(dscr_image, element_temp);
                  }
                  else
                        break;
            }
      }
      else
      {
            *erreur = 7;
      }
      fclose(fichier);
      return dscr_image;
}

void depiler_descripteur_image(PILE_image dscr_image, int erreur_image, int *erreur)
{
      ELEMENT_image elementsupp;
      FILE *fichier = NULL;
      bool first = true;
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
                        // AFFICHAGE DESCRIPTEUR et ID DANS FICHIER

                        // AFFICHAGE ID

                        // Ne pas sauter de ligne si c'est le premier affiché
                        if (first == true)
                        {
                              fprintf(fichier, "-%d\n", elementsupp.id);
                              first = false;
                        }
                        else
                              fprintf(fichier, "\n-%d\n", elementsupp.id);

                        int i;

                        // AFFICHAGE DESCRIPTEUR
                        for (i = 0; i < elementsupp.descripteur_image.Nb_Ligne - 1; i++)
                        {
                              // Permet d'afficher q'un certain nombre de valeur
                              fprintf(fichier, "%d %d\n", elementsupp.descripteur_image.Bilan[i][0], elementsupp.descripteur_image.Bilan[i][1]);
                              total = total + elementsupp.descripteur_image.Bilan[i][1];
                        }

                        fprintf(fichier, "%d %d", elementsupp.descripteur_image.Bilan[i][0], elementsupp.descripteur_image.Bilan[i][1]);
                        total = total + elementsupp.descripteur_image.Bilan[i][1];

                        // free les elements du descripteur image
                        for (i = 0; i < elementsupp.descripteur_image.Nb_Ligne; i++)
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
            while (!feof(ptr_fic))
            {
                  // recupere ID et CHEMIN
                  fscanf(ptr_fic, "-%d | %s\n", &element_temp.id, cheminfichier);
                  // recupere le descripteur avec la fonction developpé par Hugo Lestrade
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

void depiler_descripteur_texte(PILE_texte dscr_texte, int *erreur, CONFIG config)
{
      ELEMENT_texte elementsupp;
      FILE *fichier = NULL;
      bool first = true;
      fichier = fopen("../base_descripteur/base_descripteur_texte", "w");
      int total = 0;
      if (fichier != NULL)
      {
            while (dscr_texte != NULL)
            {
                  dscr_texte = dePILE_texte(dscr_texte, &elementsupp);
                  //______________________________
                  // AFFICHAGE DESCRIPTEUR ET ID DANS FICHIER

                  // afficher ID
                  fprintf(fichier, "-%d\n", elementsupp.id);
                  // affichage descripteur
                  for (int x = 0; x < config.Nb_Mots_Cle; x++)
                  {
                        fprintf(fichier, "%s    |    %d\n", elementsupp.descripteur_texte.tab_mot[x], elementsupp.descripteur_texte.tab_app[x]);
                  }

                  // free les tableaux du descripteur texte
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
            strcpy(cheminDATA, "../DATA_FIL_ROUGE_DEV/Textes/*.xml");
      }
      if (strcmp(type, "audio") == 0)
      {
            strcpy(cheminliste, "../liste_base/liste_base_audio");
            strcpy(cheminDATA, "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/*.txt");
      }

      strcpy(commande, "ls -ltur ");
      strcat(commande, cheminDATA);
      strcat(commande, "> ../traitement/fic_temp");
      system(commande);

      if (strcmp(type, "texte") == 0)
      {
            strcpy(commande, "cut -d '/' -f 4 ../traitement/fic_temp > ../traitement/fic");
            system(commande);

            strcpy(commande, "cut -d '/' -f 4 ");
            strcat(commande, cheminliste);
            strcat(commande, " > ../traitement/ListeDejaIndexeTemp");
            system(commande);
      }
      else
      {
            strcpy(commande, "cut -d '/' -f 5 ../traitement/fic_temp > ../traitement/fic");
            system(commande);

            strcpy(commande, "cut -d '/' -f 5 ");
            strcat(commande, cheminliste);
            strcat(commande, " > ../traitement/ListeDejaIndexeTemp");
            system(commande);
      }

      strcpy(commande, "diff ../traitement/ListeDejaIndexeTemp ../traitement/fic  > ../traitement/diff");
      system(commande);

      FILE *fichier_first = NULL;
      PILE cheminnewfile = init_PILE();
      ELEMENT element_temp;
      String val;

      fichier_first = fopen("../traitement/diff", "r");
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
                              printf("Ajout : %s   FIN\n", val);
                              fflush(stdout);
                              printf("AVANT AJOUT FICHIER: \ttype: %s val: %s\n", type, val);
                              fflush(stdout);
                              ajoutfichier(config, type, val, Erreur);
                              //  appeler fonction ajout d'un fichier
                        }
                        if (strstr("< ", val))
                        {
                              fscanf(fichier_first, "%s", val);
                              printf("Suppr :%s   FIN\n", val);
                              fflush(stdout);
                              //Supprimer_Descripteur(Erreur, val, type);
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

void indexation_generale_ferme(CONFIG config, int *Erreurimage, int *Erreuraudio, int *Erreurtexte, int *Erreur)
{     
      recuperer_path_tous_fichiers(Erreurtexte, Erreuraudio, Erreurimage);

      PILE_image pileimage = NULL;
      pileimage = base_descript_empiler_image(pileimage, Erreur, Erreurimage, config);
      depiler_descripteur_image(pileimage, *Erreurimage, Erreur);

      PILE_audio descripteur_audio = NULL;
      descripteur_audio = base_descript_empiler_audio(descripteur_audio, Erreur, Erreuraudio, config);
      depiler_descripteur_audio(descripteur_audio, Erreur, *Erreuraudio);

      PILE_texte piletexte = NULL;
      piletexte = base_descript_empiler_texte(piletexte, Erreurtexte, config);
      depiler_descripteur_texte(piletexte, Erreurtexte, config);
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

      fichier = fopen("../traitement/fic", "w");
      ELEMENT elementsupp;

      // temp contient le chemin du fichier obtenue en concatenant le path et son titre
      strcpy(temp, cheminDATA);
      strcat(temp, chemin);

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

      strcpy(commande, "cat ../traitement/fic >> ");
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
            printf("\n\tID FANS AJOUT FICHIER : %d\n", id);

            fichier2 = fopen("../traitement/fic", "w");
            if (fichier2 != NULL)
            {

                  fprintf(fichier2, "\n-%d\n", id);

                  int i;
                  for (i = 0; i < descripteur_image.Nb_Ligne - 1; i++)
                  {
                        // Permet d'afficher q'un certain nombre de valeur
                        fprintf(fichier2, "%d %d\n", descripteur_image.Bilan[i][0], descripteur_image.Bilan[i][1]);

                        total = total + descripteur_image.Bilan[i][1];
                  }
                  fprintf(fichier2, "%d %d", descripteur_image.Bilan[i][0], descripteur_image.Bilan[i][1]);
                  total = total + descripteur_image.Bilan[i][1];

                  // free les tableaus utilisés dans descripteur audio
                  for (i = 0; i < descripteur_image.Nb_Ligne; i++)
                  {
                        free(descripteur_image.Bilan[i]);
                  }
                  free(descripteur_image.Bilan);
            }
            fclose(fichier2);
            strcpy(commande, "cat ../traitement/fic >> ../base_descripteur/base_descripteur_image");
            system(commande);
      }

      if (strcmp(type, "texte") == 0)
      {
            DESCRIPTEUR_TEXTE descripteur_texte;
            descripteur_texte = descripteur_texte_finale(temp, config.Nb_Mots_Cle, descripteur_texte);

            FILE *fichier = NULL;

            fichier = fopen("../traitement/fic", "w");
            if (fichier != NULL)
            {
                        fprintf(fichier, "\n-%d", id);

                  for (int x = 0; x < config.Nb_Mots_Cle; x++)
                  {
                        fprintf(fichier, "\n%s    |    %d", descripteur_texte.tab_mot[x], descripteur_texte.tab_app[x]);
                  }

                  free(descripteur_texte.tab_mot);
                  free(descripteur_texte.tab_app);
            }
            fclose(fichier);
            strcpy(commande, "cat ../traitement/fic >> ../base_descripteur/base_descripteur_texte");
            system(commande);
      }

      if (strcmp(type, "audio") == 0)
      {

            bool first = true;
            descri_audio descripteur;
            descripteur = Descripteur_audio(config.Nb_Fenetre, config.Intervale, temp, Erreur);

            FILE *fichieraudio = NULL;

            fichieraudio = fopen("../traitement/fic", "w");
            if (fichieraudio != NULL)
            {

                  fprintf(fichieraudio, "\n-%d %d\n", id, descripteur.ligne);
                  for (unsigned i = 0; i < descripteur.ligne; ++i)
                  {
                        for (unsigned j = 0; j < descripteur.colonne; ++j)
                        {
                              fprintf(fichieraudio, " %d ", descripteur.tab[i][j]);
                        }
                        if (i < descripteur.ligne - 1)
                              fprintf(fichieraudio, "\r\n");
                  }
            }
            fclose(fichieraudio);

            for (int i = 0; i < descripteur.ligne; i++) // creation des colonne du tableau
            {
                  free(descripteur.tab[i]);
            }
            free(descripteur.tab);

            strcpy(commande, "cat ../traitement/fic >> ../base_descripteur/base_descripteur_audio");
            system(commande);
      }
}

void Supprimer_Descripteur(int *Erreur, char Nom_Fichier[], char type_fichier[])
{
      FILE *fichier = NULL;

      if (strcmp("texte", type_fichier) == 0)
      {
            fichier = fopen("../liste_base/liste_base_texte", "r");
      }
      else if (strcmp("audio", type_fichier) == 0)
      {
            fichier = fopen("../liste_base/liste_base_audio", "r");
      }
      else if (strcmp("nb", type_fichier) == 0)
      {
            fichier = fopen("../liste_base/liste_base_image/NB", "r");
      }
      else if (strcmp("rgb", type_fichier) == 0)
      {
            fichier = fopen("../liste_base/liste_base_image/RGB", "r");
      }

      if (fichier != NULL)
      {
            int tmp;
            int id;
            char path[1000];

            FILE *nvfile = NULL;
            nvfile = fopen("../liste_base/tmp.txt", "w");
            if (nvfile != NULL)
            {
                  int seul = 0;
                  while (fscanf(fichier, "-%d %s\n", &tmp, &path) != EOF)
                  {
                        if (strstr(path, Nom_Fichier) != NULL)
                        {
                              id = -tmp;
                        }
                        else
                        {
                              if (seul == 0)
                              {
                                    fprintf(nvfile, "-%d %s", tmp, path);
                                    seul++;
                              }
                              else
                              {
                                    fprintf(nvfile, "\n-%d %s", tmp, path);
                              }
                        }
                  }
                  fclose(nvfile);
                  fclose(fichier);
                  nvfile = NULL;
                  fichier = NULL;

                  if (strcmp("texte", type_fichier) == 0)
                  {
                        remove("../liste_base/liste_base_texte");
                        rename("../liste_base/tmp.txt", "../liste_base/liste_base_texte");

                        fichier = fopen("../base_descripteur/base_descripteur_texte", "r");
                        nvfile = fopen("../base_descripteur/tmp.txt", "w");
                        if (fichier != NULL && nvfile != NULL)
                        {
                              int tmp1;

                              char mot_lue[20];
                              char idc[10000];

                              sprintf(idc, "%d", id);

                              while (fscanf(fichier, "%s", &mot_lue) != EOF)
                              {
                                    if (strcmp(idc, mot_lue) != 0)
                                    {
                                          fprintf(nvfile, "%s\n", mot_lue);
                                          int alt = 0;
                                          while (fscanf(fichier, "%s", &mot_lue) != EOF && atoi(mot_lue) >= 0)
                                          {
                                                if (alt == 0)
                                                {
                                                      alt++;
                                                      fprintf(nvfile, "%s\t", mot_lue);
                                                }
                                                else if (alt == 1)
                                                {
                                                      alt++;
                                                      fprintf(nvfile, "%s\t", mot_lue);
                                                }
                                                else
                                                {
                                                      alt = 0;
                                                      fprintf(nvfile, "%s\n", mot_lue);
                                                }
                                          }
                                          fseek(fichier, -strlen(mot_lue), SEEK_CUR);
                                    }
                                    else
                                    {
                                          while (fscanf(fichier, "%s", &mot_lue) != EOF && atoi(mot_lue) >= 0)
                                                ;
                                          fseek(fichier, -strlen(mot_lue), SEEK_CUR);
                                    }
                              }
                              fclose(fichier);
                              fclose(nvfile);
                              remove("../base_descripteur/base_descripteur_texte");
                              rename("../base_descripteur/tmp.txt", "../base_descripteur/base_descripteur_texte");
                        }
                        else
                        {
                              *Erreur = 7;
                        }
                  }
                  else if (strcmp("audio", type_fichier) == 0)
                  {
                        remove("../liste_base/liste_base_audio");
                        rename("../liste_base/tmp.txt", "../liste_base/liste_base_audio");

                        fichier = fopen("../base_descripteur/base_descripteur_audio", "r");
                        nvfile = fopen("../base_descripteur/tmp.txt", "w");
                        if (fichier != NULL && nvfile != NULL)
                        {

                              int tmp1;
                              int uneseulefois = 0;

                              while (fscanf(fichier, "%d", &tmp) != EOF)
                              {
                                    if (id != tmp)
                                    {
                                          if (uneseulefois == 0)
                                          {
                                                fprintf(nvfile, "%d ", tmp);
                                                fscanf(fichier, "%d", &tmp);
                                                fprintf(nvfile, "%d", tmp);
                                                uneseulefois++;
                                          }
                                          else
                                          {
                                                fprintf(nvfile, "\n%d ", tmp);
                                                fscanf(fichier, "%d", &tmp);
                                                fprintf(nvfile, "%d", tmp);
                                          }

                                          int alt = 0;
                                          while (fscanf(fichier, "%d", &tmp) != EOF && tmp >= 0)
                                          {
                                                if (alt == 0)
                                                {
                                                      alt++;
                                                      fprintf(nvfile, "\n%d  ", tmp);
                                                }
                                                else if (alt < 32)
                                                {
                                                      alt++;
                                                      fprintf(nvfile, "%d  ", tmp);
                                                      if (alt == 32)
                                                      {
                                                            alt = 0;
                                                      }
                                                }
                                          }
                                          char number[10000];
                                          sprintf(number, "%d", tmp);
                                          fseek(fichier, -strlen(number), SEEK_CUR);
                                    }
                                    else
                                    {
                                          while (fscanf(fichier, "%d", &tmp) != EOF && tmp >= 0)
                                                ;
                                          char number[10000];
                                          sprintf(number, "%d", tmp);
                                          fseek(fichier, -strlen(number), SEEK_CUR);
                                    }
                              }
                              fclose(fichier);
                              fclose(nvfile);
                              remove("../base_descripteur/base_descripteur_audio");
                              rename("../base_descripteur/tmp.txt", "../base_descripteur/base_descripteur_audio");
                        }
                        else
                        {
                              *Erreur = 7;
                        }
                  }
                  else if (strcmp("nb", type_fichier) == 0)
                  {
                        remove("../liste_base/liste_base_image/NB");
                        rename("../liste_base/tmp.txt", "../liste_base/liste_base_image/NB");

                        fichier = fopen("../base_descripteur/base_descripteur_image", "r");
                        nvfile = fopen("../base_descripteur/tmp.txt", "w");
                        if (fichier != NULL && nvfile != NULL)
                        {

                              int tmp1;

                              while (fscanf(fichier, "%d", &tmp) != EOF)
                              {
                                    if (id != tmp)
                                    {
                                          fprintf(nvfile, "\n%d", tmp);
                                          int alt = 0;
                                          while (fscanf(fichier, "%d", &tmp) != EOF && tmp >= 0)
                                          {
                                                if (alt == 0)
                                                {
                                                      alt++;
                                                      fprintf(nvfile, "\n%d ", tmp);
                                                }
                                                else
                                                {
                                                      alt--;
                                                      fprintf(nvfile, "%d", tmp);
                                                }
                                          }
                                          char number[10000];
                                          sprintf(number, "%d", tmp);
                                          fseek(fichier, -strlen(number), SEEK_CUR);
                                    }
                                    else
                                    {
                                          while (fscanf(fichier, "%d", &tmp) != EOF && tmp >= 0)
                                                ;
                                          char number[10000];
                                          sprintf(number, "%d", tmp);
                                          fseek(fichier, -strlen(number), SEEK_CUR);
                                    }
                              }
                              fclose(fichier);
                              fclose(nvfile);
                              remove("../base_descripteur/base_descripteur_image");
                              rename("../base_descripteur/tmp.txt", "../base_descripteur/base_descripteur_image");
                        }
                        else
                        {
                              *Erreur = 7;
                        }
                  }
                  else if (strcmp("rgb", type_fichier) == 0)
                  {
                        remove("../liste_base/liste_base_image/RGB");
                        rename("../liste_base/tmp.txt", "../liste_base/liste_base_image/RGB");

                        fichier = fopen("../base_descripteur/base_descripteur_image", "r");
                        nvfile = fopen("../base_descripteur/tmp.txt", "w");
                        if (fichier != NULL && nvfile != NULL)
                        {

                              int tmp1;

                              while (fscanf(fichier, "%d", &tmp) != EOF)
                              {
                                    if (id != tmp)
                                    {
                                          fprintf(nvfile, "\n%d", tmp);
                                          int alt = 0;
                                          while (fscanf(fichier, "%d", &tmp) != EOF && tmp >= 0)
                                          {
                                                printf("%d \n", tmp);
                                                if (alt == 0)
                                                {
                                                      alt++;
                                                      fprintf(nvfile, "\n%d ", tmp);
                                                }
                                                else
                                                {
                                                      alt--;
                                                      fprintf(nvfile, "%d", tmp);
                                                }
                                          }
                                          char number[10000];
                                          sprintf(number, "%d", tmp);
                                          fseek(fichier, -strlen(number), SEEK_CUR);
                                    }
                                    else
                                    {
                                          while (fscanf(fichier, "%d", &tmp) != EOF && tmp >= 0)
                                                ;
                                          char number[10000];
                                          sprintf(number, "%d", tmp);
                                          fseek(fichier, -strlen(number), SEEK_CUR);
                                    }
                              }
                              fclose(fichier);
                              fclose(nvfile);
                              remove("../base_descripteur/base_descripteur_image");
                              rename("../base_descripteur/tmp.txt", "../base_descripteur/base_descripteur_image");
                        }
                        else
                        {
                              *Erreur = 7;
                        }
                  }
            }
            else
            {
                  *Erreur = 7;
            }
      }
      else
      {
            *Erreur = 7;
      }
}

int recupererDernierID(String type, int *Erreur)
{
      // FONCTIONNEMENT
      /** exemple sur image
       * lire tous les ids present sur les fichiers liste_base/image/NB et liste_base/image/RGB et garder la plus grande valeur
       */
      int id_finale = 0;
      int id_temp = 0;
      String commande;

      if (strcmp(type, "rgb") == 0 || strcmp(type, "nb") == 0)
      {
            FILE *fichier1;
            fichier1 = fopen("../liste_base/liste_base_image/RGB", "r");
            if (fichier1 != NULL)
            {
                  while (fscanf(fichier1, "-%d |%*s\n", &id_temp) != EOF)
                  {
                        fflush(stdout);
                        if (id_finale < id_temp)
                        {
                              id_finale = id_temp;
                        }
                  }
            }
            else
            {
                  *Erreur = 7;
            }
            fclose(fichier1);

            FILE *fichier2;
            fichier2 = fopen("../liste_base/liste_base_image/NB", "r");
            if (fichier2 != NULL)
            {
                  while (fscanf(fichier2, "-%d |%*s\n", &id_temp) != EOF)
                  {
                        fflush(stdout);
                        if (id_finale < id_temp)
                        {
                              id_finale = id_temp;
                        }
                  }
            }
            else
            {
                  *Erreur = 7;
            }
            fclose(fichier2);
            printf("ID FINALE : %d", id_finale);
            return id_finale + 1;
      }

      if (strcmp(type, "texte") == 0)
      {
            FILE *fichier;
            fichier = fopen("../liste_base/liste_base_texte", "r");
            if (fichier != NULL)
            {
                  while (fscanf(fichier, "-%d |%*s\n", &id_temp) != EOF)
                  {
                        if (id_finale < id_temp)
                        {
                              id_finale = id_temp;
                        }
                  }
            }
            else
            {
                  *Erreur = 7;
            }
            fclose(fichier);

            return id_finale + 1;
      }

      if (strcmp(type, "audio") == 0)
      {
            FILE *fichier3;
            fichier3 = fopen("../liste_base/liste_base_audio", "r");
            if (fichier3 != NULL)
            {
                  while (fscanf(fichier3, "-%d |%*s\n", &id_temp) != EOF)
                  {
                        if (id_finale < id_temp)
                        {
                              id_finale = id_temp;
                        }
                  }
            }
            else
            {
                  *Erreur = 7;
            }
            fclose(fichier3);
      }
      return id_finale + 1;
}

void indexation(CONFIG config, int *Erreurimage, int *Erreuraudio, int *Erreurtexte, int *Erreur)
{
      // FONCTIONNEMENT :
      /**
       * si le fichier liste_base/liste_base_type ( type = texte, audio, nb ou rgb) EST VIDE lancer indexation de tous les fichiers type
       * sinon
       * si il ya un fichier en plus
       *  l'indexe et le rajouter liste_base et ajouter son descripteur dans descripteur_base
       * sinon
       * le supprimer dans liste_base et descripteur_base
       */
      FILE *fichier_texte = NULL;
      String val;

      String path;
      int deb = 0;

      // TEXTE
      fichier_texte = fopen("../liste_base/liste_base_texte", "r");
      if (fichier_texte != NULL)
      {
            if (fscanf(fichier_texte, "%s", val) != EOF)
            {
                  fclose(fichier_texte);
                  indexation_ouverte(config, "texte", Erreurimage, Erreuraudio, Erreurtexte, Erreur);
            }
            else
            {
                  indexation_texte(config, Erreur, Erreurtexte);
                  fclose(fichier_texte);
            }
      }
      else
      {
            *Erreur = 7;
      }
      // IMAGE __NB
      FILE *fichier_nb = NULL;
      deb = 0;
      String commande;

      fichier_nb = fopen("../liste_base/liste_base_image/NB", "r");
      if (fichier_nb != NULL)
      {
            if (fscanf(fichier_nb, "%s", val) != EOF)
            {
                   fclose(fichier_nb);
                  indexation_ouverte(config, "nb", Erreurimage, Erreuraudio, Erreurtexte, Erreur);
            }
            else
            {
                  indexation_image(config, Erreur, Erreurimage);
                  fclose(fichier_nb);
            }
      }
      else
      {
            *Erreur = 7;
      }
      // IMAGE __ RGB
      FILE *fichier_rgb = NULL;
      deb = 0;

      fichier_rgb = fopen("../liste_base/liste_base_image/RGB", "r");
      if (fichier_rgb != NULL)
      {
            if (fscanf(fichier_rgb, "%s", val) != EOF)
            {
                  fclose(fichier_rgb);
                  indexation_ouverte(config, "rgb", Erreurimage, Erreuraudio, Erreurtexte, Erreur);
            }
            else
            {
                  indexation_image(config, Erreur, Erreurimage);
                  fclose(fichier_rgb);
            }
      }
      else
      {
            *Erreur = 7;
      }

      // AUDIO
      FILE *fichier_son = NULL;
      deb = 0;

      fichier_son = fopen("../liste_base/liste_base_audio", "r");
      if (fichier_son != NULL)
      {
            if (fscanf(fichier_son, "%s", val) != EOF)
            {
            fclose(fichier_son);
                  indexation_ouverte(config, "audio", Erreurimage, Erreuraudio, Erreurtexte, Erreur);
            }
            else
            {
                  
                  indexation_audio(config, Erreur, Erreuraudio);
                  fclose(fichier_son);
            }
      }
      else
      {
            *Erreur = 7;
      }
      // strcpy(commande, "rm ../traitement/diff");
      // system(commande);
      // strcpy(commande, "rm ../traitement/fic_temp");
      // system(commande);
      // strcpy(commande, "rm ../traitement/ListeDejaIndexeTemp");
      // system(commande);
      // strcpy(commande, "rm ../traitement/fic");
      // system(commande);
      // strcpy(commande, "rm ../traitement/fichieraindexe");
      // system(commande);
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
      printf("\t INDEXATION TOUS FICHIERS AUDIO\navant empile");
      fflush(stdout);
      descripteur_audio = base_descript_empiler_audio(descripteur_audio, Erreur, Erreuraudio, config);
      printf("\napres empiler");
      fflush(stdout);
      depiler_descripteur_audio(descripteur_audio, Erreur, *Erreuraudio);
      printf("\napresdepil\nFIN AUDIO");
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

      printf("FIN IMAGE\n");
      fflush(stdout);
}