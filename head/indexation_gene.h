#ifndef indexation_gene_h
#define indexation_gene_h

#include "element.h"
#include "../head/Global.h"

typedef struct Estruct_empiler
{   String CHEMIN;
    String nom_fic;
} struct_empiler;

// 1 // fonction pour recuperer chemin d'acces de chaque type de fichier et stocker resultat dans un tableau
              // appeler trois fois main pour chaque type de fichier
              // avoir trois tableaux de string
void recup_path_img_audio( STR *str, int deb,String path, String *Erreur);
void recup_path_texte( STR *str, int deb , String path, String *Erreur);

// 2 // fonction recuperer leurs structures et lempiler dans une pile
             //appeler leur fonctions descripteur
              //empiler resultat
              //appeler fonctions trois fois pour avoir le resultat

// 3 // fonction depiler dans un fichier texte
            // depiler les piles empiler dans un fichier texte
            // avoir le receuil des descripteurs

// 4 // fonction pour link les ids et les chemins d'acces


#endif