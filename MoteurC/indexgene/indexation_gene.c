//
// AUTEUR :
//          YASMINE ALLAL
// DERNIERE VERSION :
//    15/01/2023
//
// Fonction Supprimer_Descripteur developpe par Loic Maignan

#include "indexation_gene.h"
#include "../chemin.h"

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
      char CHEMIN[100] = LISTE_BASE_AUD;
      char cheminfichier[200];

      ptr_fic = fopen(CHEMIN, "r");
      if (ptr_fic != NULL)
      {
            while (!feof(ptr_fic))
            {
                  // recuperer lid et son chemin
                  fscanf(ptr_fic, "-%d |%s\n", &element_temp.id, cheminfichier);
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
      fichier = fopen(BASE_AUD, "w");

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
      char CHEMIN[100] = LISTE_BASE_NB;
      char cheminfichier[200];

      ptr_fic = fopen(CHEMIN, "r");

      if (ptr_fic != NULL)
      {
            while (!feof(ptr_fic))
            {
                  // lire lid et son chemin
                  fscanf(ptr_fic, "-%d |%s\n", &element_temp.id, cheminfichier);
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
      strcpy(CHEMIN, LISTE_BASE_RGB);
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
      fichier = fopen(BASE_IMG, "w");
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
      char CHEMIN[100] = LISTE_BASE_TXT;
      char cheminfichier[200];

      ptr_fic = fopen(CHEMIN, "r");

      if (ptr_fic != NULL)
      {
            while (!feof(ptr_fic))
            {
                  // recupere ID et CHEMIN
                  
                  fscanf(ptr_fic, "-%d |%s\n", &element_temp.id, cheminfichier);
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
      fichier = fopen(BASE_TXT, "w");
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
      int deb = 1;
      //_________________
      // TEXTE
      //_________________
      strcpy(path, PATH_TEXTE);
      recup_path(&piletexte_path, deb, path, "texte", Erreurtexte);
      depiler_path(&piletexte_path, LISTE_BASE_TXT, Erreurtexte);

      //_________________
      // AUDIO
      //_________________
      strcpy(path, PATH_AUDIO);
      recup_path(&pileaudio_path, deb, path, "audio", Erreuraudio);
      depiler_path(&pileaudio_path, LISTE_BASE_AUD, Erreuraudio);

      //_________________
      // IMAGE
      //_________________
      strcpy(path, PATH_RGB);
      recup_path(&pileimage_path, deb, path, "image", Erreurimage);
      deb = (pileimage_path->element.id) + 1;
      depiler_path(&pileimage_path, LISTE_BASE_RGB, Erreurimage);
      strcpy(path, PATH_NB);
      recup_path(&pileimage_path, deb, path, "image", Erreurimage);
      depiler_path(&pileimage_path, LISTE_BASE_NB, Erreurimage);
}

void indexation_ouverte(CONFIG config, String type, int *Erreurimage, int *Erreuraudio, int *Erreurtexte, int *Erreur)
{

      String recupchemin;
      String commande;

      String cheminliste;
      String cheminDATA;
      if (strcmp(type, "rgb") == 0)
      {
            strcpy(cheminliste, LISTE_BASE_RGB);
            strcpy(cheminDATA, PATH_RGB);
            strcat(cheminDATA, "*.txt");
      }
      if (strcmp(type, "nb") == 0)
      {
            strcpy(cheminliste, LISTE_BASE_NB);
            strcpy(cheminDATA, PATH_NB);
            strcat(cheminDATA, "*.txt");
      }
      if (strcmp(type, "texte") == 0)
      {
            strcpy(cheminliste, LISTE_BASE_TXT);
            strcpy(cheminDATA, PATH_TEXTE);
            strcat(cheminDATA, "*.txt");
      }
      if (strcmp(type, "audio") == 0)
      {
            strcpy(cheminliste, LISTE_BASE_AUD);
            strcpy(cheminDATA, PATH_AUDIO);
            strcat(cheminDATA, "*.txt");
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
      if (strcmp(type, "nb") == 0 || strcmp(type, "rgb") == 0 || strcmp(type, "audio") == 0)
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
            }
            else
            {
                  while (!feof(fichier_first))
                  {
                        fscanf(fichier_first, "%s", val);
                        if (strstr("> ", val))
                        {
                              fscanf(fichier_first, "%s", val);
                              ajoutfichier(config, type, val, Erreur);
                              //  appeler fonction ajout d'un fichier
                        }
                        if (strstr("< ", val))
                        {
                              fscanf(fichier_first, "%s", val);
                              Supprimer_Descripteur(Erreur, val, type, config.Intervale);
                              //  appeler fonction pour supprimer
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
            strcpy(cheminliste, LISTE_BASE_RGB);
            strcpy(cheminDATA, PATH_RGB);
      }
      if (strcmp(type, "nb") == 0)
      {
            strcpy(cheminliste, LISTE_BASE_NB);
            strcpy(cheminDATA, PATH_NB);
      }
      if (strcmp(type, "texte") == 0)
      {
            strcpy(cheminliste, LISTE_BASE_TXT);
            strcpy(cheminDATA, PATH_TEXTE);
      }
      if (strcmp(type, "audio") == 0)
      {
            strcpy(cheminliste, LISTE_BASE_AUD);
            strcpy(cheminDATA, PATH_AUDIO);
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
            strcpy(commande, "cat ../traitement/fic >> ../../DATA_FIL_ROUGE_DEV/base_descripteur/base_descripteur_image");
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
            strcpy(commande, "cat ../traitement/fic >> ../../DATA_FIL_ROUGE_DEV/base_descripteur/base_descripteur_texte");
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

            strcpy(commande, "cat ../traitement/fic >> ../../DATA_FIL_ROUGE_DEV/base_descripteur/base_descripteur_audio");
            system(commande);
      }
}

void Supprimer_Descripteur(int *Erreur, char Nom_Fichier[], char type_fichier[], int intervale)
{
      // Ouverture du fichier correspondant au type du fichier a supprimer
      FILE *fichier = NULL;

      if (strcmp("texte", type_fichier) == 0)
      {
            fichier = fopen(LISTE_BASE_TXT, "r");
      }
      else if (strcmp("audio", type_fichier) == 0)
      {
            fichier = fopen(LISTE_BASE_AUD, "r");
      }
      else if (strcmp("nb", type_fichier) == 0)
      {
            fichier = fopen(LISTE_BASE_NB, "r");
      }
      else if (strcmp("rgb", type_fichier) == 0)
      {
            fichier = fopen(LISTE_BASE_RGB, "r");
      }
      // Recopiage de l'ancienne liste_base mais sans le fichier à supprimer
      if (fichier != NULL)
      {
            int tmp;
            int id_ASupprimer;
            char path[1000];

            FILE *nvfile = NULL;
            // Creation d'un fichier temporaire
            nvfile = fopen("../liste_base/tmp.txt", "w");
            if (nvfile != NULL)
            {
                  bool a_faire_une_fois = false;
                  while (fscanf(fichier, "-%d %s\n", &tmp, &path) != EOF)
                  {
                        if (strstr(path, Nom_Fichier) != NULL)
                        {
                              // Memorisation de l'id du fichier à supprimer
                              id_ASupprimer = -tmp;
                        }
                        else
                        {
                              if (a_faire_une_fois == false)
                              {
                                    fprintf(nvfile, "-%d %s", tmp, path);
                                    a_faire_une_fois = true;
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

                  // Si c'est un fichier texte va supprimer le descripteur associer à l'id
                  if (strcmp("texte", type_fichier) == 0)
                  {
                        // Remplace l'ancienne liste base par la nouvelle avec le descripteur supprimer
                        remove(LISTE_BASE_TXT);
                        rename("../liste_base/tmp.txt", LISTE_BASE_TXT);

                        fichier = fopen(PATH_TEXTE, "r");
                        nvfile = fopen("../../DATA_FIL_ROUGE_DEV/base_descripteur/tmp.txt", "w");
                        if (fichier != NULL && nvfile != NULL)
                        {
                              char val_lue[50];
                              int cpt_aff = 0;
                              int id_lue = 0;
                              bool a_faire_une_fois = false;

                              while (1)
                              {
                                    // Si fichier vide on arrete de le lire
                                    if (fscanf(fichier, "%s", &val_lue) == EOF)
                                    {
                                          break;
                                    }
                                    // Recopie de l'id
                                    if (atoi(val_lue) < 0)
                                    {
                                          id_lue = atoi(val_lue);
                                          if (id_lue != id_ASupprimer)
                                          {
                                                if (a_faire_une_fois == false)
                                                {
                                                      a_faire_une_fois = true;
                                                      fprintf(nvfile, "%s", val_lue);
                                                      fscanf(fichier, "%s", &val_lue);
                                                }
                                                else
                                                {
                                                      fprintf(nvfile, "\n%s", val_lue);
                                                      fscanf(fichier, "%s", &val_lue);
                                                }
                                          }
                                    }
                                    // detection du descripteur a supprimer donc si different recopiage de l'ancien descripteur dans le nouveau
                                    if (id_lue != id_ASupprimer)
                                    {
                                          if (cpt_aff == 0)
                                          {
                                                fprintf(nvfile, "\n%s    ", val_lue);
                                                cpt_aff++;
                                          }
                                          else if (cpt_aff == 1)
                                          {
                                                fprintf(nvfile, "%s    ", val_lue);
                                                cpt_aff++;
                                          }
                                          else
                                          {
                                                fprintf(nvfile, "%s", val_lue);
                                                cpt_aff = 0;
                                          }
                                    }
                              }
                              fclose(fichier);
                              fclose(nvfile);
                              remove(PATH_TEXTE);
                              rename("../../DATA_FIL_ROUGE_DEV/base_descripteur/tmp.txt", PATH_TEXTE);
                        }
                        else
                        {
                              *Erreur = 7;
                        }
                  }
                  // Si c'est un audio texte va supprimer le descripteur associer à l'id
                  else if (strcmp("audio", type_fichier) == 0)
                  {
                        // Remplace l'ancienne liste base par la nouvelle avec le descripteur supprimer
                        remove(LISTE_BASE_AUD);
                        rename("../liste_base/tmp.txt", LISTE_BASE_AUD);

                        fichier = fopen(BASE_AUD, "r");
                        nvfile = fopen("../../DATA_FIL_ROUGE_DEV/base_descripteur/tmp.txt", "w");
                        if (fichier != NULL && nvfile != NULL)
                        {
                              int val_lue;
                              int cpt_aff = 0;
                              int id_lue = 0;
                              bool a_faire_une_fois = false;

                              while (1)
                              {
                                    // Lecture de l'ancien base descripteur tant que le fichier n'est pa vide
                                    if (fscanf(fichier, "%d", &val_lue) == EOF)
                                    {
                                          break;
                                    }
                                    if (val_lue < 0)
                                    {
                                          id_lue = val_lue;
                                          if (id_lue != id_ASupprimer)
                                          {
                                                if (a_faire_une_fois == false)
                                                {
                                                      // Lecture et ecriture dans la nouvelle base
                                                      a_faire_une_fois = true;
                                                      fprintf(nvfile, "%d ", val_lue);
                                                      fscanf(fichier, "%d", &val_lue);
                                                      fprintf(nvfile, "%d", val_lue);
                                                      fscanf(fichier, "%d", &val_lue);
                                                }
                                                else
                                                {
                                                      fprintf(nvfile, "\n%d ", val_lue);
                                                      fscanf(fichier, "%d", &val_lue);
                                                      fprintf(nvfile, "%d", val_lue);
                                                      fscanf(fichier, "%d", &val_lue);
                                                }
                                          }
                                    }
                                    // detection du descripteur a supprimer donc si different recopiage de l'ancien descripteur dans le nouveau
                                    if (id_lue != id_ASupprimer)
                                    {
                                          if (cpt_aff == 0)
                                          {
                                                fprintf(nvfile, "\n%d  ", val_lue);
                                                cpt_aff++;
                                          }
                                          else if (cpt_aff < intervale)
                                          {
                                                fprintf(nvfile, "%d  ", val_lue);
                                                cpt_aff++;
                                                if (cpt_aff == 32)
                                                {
                                                      cpt_aff = 0;
                                                }
                                          }
                                    }
                              }
                              fclose(fichier);
                              fclose(nvfile);
                              remove(BASE_AUD);
                              rename("../../DATA_FIL_ROUGE_DEV/base_descripteur/tmp.txt", BASE_AUD);
                        }
                        else
                        {
                              *Erreur = 7;
                        }
                  }
                  // Si c'est un fichier image noir et blanc va supprimer le descripteur associer à l'id
                  else if (strcmp("nb", type_fichier) == 0)
                  {

                        remove(LISTE_BASE_NB);
                        rename("../liste_base/tmp.txt", LISTE_BASE_NB);

                        fichier = fopen(BASE_IMG, "r");
                        nvfile = fopen("../../DATA_FIL_ROUGE_DEV/base_descripteur/tmp.txt", "w");
                        if (fichier != NULL && nvfile != NULL)
                        {
                              bool a_faire_une_fois = false;
                              int val_lue;
                              int id_lue = 0;
                              bool alt = false;

                              while (1)
                              {
                                    // Lecture de l'ancien base descripteur tant que le fichier n'est pa vide
                                    if (fscanf(fichier, "%d", &val_lue) == EOF)
                                    {
                                          break;
                                    }

                                    if (val_lue < 0)
                                    {
                                          id_lue = val_lue;
                                          if (id_lue != id_ASupprimer)
                                          {
                                                if (a_faire_une_fois == false)
                                                {
                                                      // Lecture et ecriture dans la nouvelle base
                                                      a_faire_une_fois = true;
                                                      fprintf(nvfile, "%d", val_lue);
                                                      fscanf(fichier, "%d", &val_lue);
                                                }
                                                else
                                                {
                                                      fprintf(nvfile, "\n%d", val_lue);
                                                      fscanf(fichier, "%d", &val_lue);
                                                }
                                          }
                                    }
                                    // detection du descripteur a supprimer donc si different recopiage de l'ancien descripteur dans le nouveau
                                    if (id_lue != id_ASupprimer)
                                    {
                                          if (alt == false)
                                          {
                                                fprintf(nvfile, "\n%d ", val_lue);
                                                alt = true;
                                          }
                                          else
                                          {
                                                fprintf(nvfile, "%d", val_lue);
                                                alt = false;
                                          }
                                    }
                              }
                              fclose(fichier);
                              fclose(nvfile);
                              remove(BASE_IMG);
                              rename("../../DATA_FIL_ROUGE_DEV/base_descripteur/tmp.txt", BASE_IMG);
                        }
                        else
                        {
                              *Erreur = 7;
                        }
                  }
                  // Si c'est un fichier image rgb va supprimer le descripteur associer à l'id
                  else if (strcmp("rgb", type_fichier) == 0)
                  {
                        // Remplace l'ancienne liste base par la nouvelle avec le descripteur supprimer
                        remove(LISTE_BASE_RGB);
                        rename("../liste_base/tmp.txt", LISTE_BASE_RGB);

                        fichier = fopen(BASE_IMG, "r");
                        nvfile = fopen("../../DATA_FIL_ROUGE_DEV/base_descripteur/tmp.txt", "w");
                        if (fichier != NULL && nvfile != NULL)
                        {
                              bool a_faire_une_fois = false;
                              int val_lue;
                              int id_lue = 0;
                              bool alt = false;

                              while (1)
                              {
                                    // Lecture de l'ancien base descripteur tant que le fichier n'est pa vide
                                    if (fscanf(fichier, "%d", &val_lue) == EOF)
                                    {
                                          break;
                                    }

                                    if (val_lue < 0)
                                    {
                                          id_lue = val_lue;
                                          if (id_lue != id_ASupprimer)
                                          {
                                                if (a_faire_une_fois == false)
                                                {
                                                      // Lecture et ecriture dans la nouvelle base
                                                      a_faire_une_fois = true;
                                                      fprintf(nvfile, "%d", val_lue);
                                                      fscanf(fichier, "%d", &val_lue);
                                                }
                                                else
                                                {
                                                      fprintf(nvfile, "\n%d", val_lue);
                                                      fscanf(fichier, "%d", &val_lue);
                                                }
                                          }
                                    }
                                    // detection du descripteur a supprimer donc si different recopiage de l'ancien descripteur dans le nouveau
                                    if (id_lue != id_ASupprimer)
                                    {
                                          if (alt == false)
                                          {
                                                fprintf(nvfile, "\n%d ", val_lue);
                                                alt = true;
                                          }
                                          else
                                          {
                                                fprintf(nvfile, "%d", val_lue);
                                                alt = false;
                                          }
                                    }
                              }
                              fclose(fichier);
                              fclose(nvfile);
                              remove(BASE_IMG);
                              rename("../../DATA_FIL_ROUGE_DEV/base_descripteur/tmp.txt", BASE_IMG);
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
            fichier1 = fopen(LISTE_BASE_RGB, "r");
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
            fichier2 = fopen(LISTE_BASE_NB, "r");
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
            return id_finale + 1;
      }

      if (strcmp(type, "texte") == 0)
      {
            FILE *fichier;
            fichier = fopen(LISTE_BASE_TXT, "r");
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
            fichier3 = fopen(LISTE_BASE_AUD, "r");
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

      // IMAGE __NB
      FILE *fichier_nb = NULL;
      deb = 0;
      String commande;
      int a = 0;

      fichier_nb = fopen(LISTE_BASE_NB, "r");
      if (fichier_nb != NULL)
      {
            if (fscanf(fichier_nb, "%s", val) == EOF)
            {
                  indexation_image(config, Erreur, Erreurimage);
                  a = 1;
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
      // IMAGE __ RGB
      if (a == 0)
      {
            FILE *fichier_rgb = NULL;
            deb = 0;

            fichier_rgb = fopen(LISTE_BASE_RGB, "r");
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
      }

      // AUDIO
      FILE *fichier_son = NULL;
      deb = 0;

      fichier_son = fopen(LISTE_BASE_AUD, "r");
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

      // TEXTE
      fichier_texte = fopen(LISTE_BASE_TXT, "r");
      if (fichier_texte != NULL)
      {
            if (fscanf(fichier_texte, "%s", val) == EOF)
            {
                  indexation_texte(config, Erreur, Erreurtexte);
                  fclose(fichier_texte);
            }
            else
            {
                  fclose(fichier_texte);
                  indexation_ouverte(config, "texte", Erreurimage, Erreuraudio, Erreurtexte, Erreur);
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
      int deb = 1;
      String path;
      //___________________________________________________
      // indexation de tous les fichiers audios
      //___________________________________________________
      PILE pileaudio_path = init_PILE();
      //___________________________________________________
      // remplier liste_base_audio
      //___________________________________________________
      strcpy(path, PATH_AUDIO);
      recup_path(&pileaudio_path, deb, path, "audio", Erreuraudio);
      depiler_path(&pileaudio_path, LISTE_BASE_AUD, Erreuraudio);
      //___________________________________________________
      // remplier base_descripteur_audio
      //___________________________________________________
      PILE_audio descripteur_audio = NULL;
      descripteur_audio = base_descript_empiler_audio(descripteur_audio, Erreur, Erreuraudio, config);
      depiler_descripteur_audio(descripteur_audio, Erreur, *Erreuraudio);
}
void indexation_texte(CONFIG config, int *Erreur, int *Erreurtexte)
{
      int deb = 1;
      String path;
      //___________________________________________________
      // indexation de tous les fichiers textes
      //___________________________________________________
      PILE piletexte_path = init_PILE();
      //___________________________________________________
      // remplier liste_base_texte
      //___________________________________________________
      strcpy(path, PATH_TEXTE);
      recup_path(&piletexte_path, deb, path, "texte", Erreurtexte);
      depiler_path(&piletexte_path, LISTE_BASE_TXT, Erreurtexte);
      //___________________________________________________
      // remplier base_descripteur_texte
      //___________________________________________________
      PILE_texte piletexte = NULL;
      piletexte = base_descript_empiler_texte(piletexte, Erreurtexte, config);
      depiler_descripteur_texte(piletexte, Erreurtexte, config);
}
void indexation_image(CONFIG config, int *Erreur, int *Erreurimage)
{
      int deb = 1;
      String path;
      //___________________________________________________
      // indexation de tous les fichiers images
      //___________________________________________________

      //___________________________________________________
      // remplier liste_base_image
      //___________________________________________________
      PILE pileimage_path = init_PILE();
      strcpy(path, PATH_RGB);
      recup_path(&pileimage_path, deb, path, "image", Erreurimage);
      deb = (pileimage_path->element.id) + 1;
      depiler_path(&pileimage_path, LISTE_BASE_RGB, Erreurimage);
      strcpy(path, PATH_NB);
      recup_path(&pileimage_path, deb, path, "image", Erreurimage);
      depiler_path(&pileimage_path, LISTE_BASE_NB, Erreurimage);
      //___________________________________________________
      // remplier base_descripteur_image
      //___________________________________________________
      PILE_image pileimage = NULL;
      pileimage = base_descript_empiler_image(pileimage, Erreur, Erreurimage, config);
      depiler_descripteur_image(pileimage, *Erreurimage, Erreur);
}