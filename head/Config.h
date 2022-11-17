#ifndef CONFIG_H
#define CONFIG_H
#include <stdlib.h>
#include <stdio.h>

#define MAX_UTILISATEUR 5
#define MAX_CHAINE 100

typedef struct
{
    char chaine[MAX_CHAINE];
}String;

typedef struct
{ 
    int nb_mots_cle;
    int similariter;
    int niveau;
    String nom_utilisateur[MAX_UTILISATEUR];
    String nom_admin[MAX_UTILISATEUR];
    String mdp_utilisateur[MAX_UTILISATEUR];
    String mdp_admin[MAX_UTILISATEUR];

}CONFIG;

CONFIG Lire_CONFIG();
void afficher_CONFIG(CONFIG config);

#endif