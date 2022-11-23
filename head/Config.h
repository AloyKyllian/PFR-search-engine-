#ifndef CONFIG_H
#define CONFIG_H
#include <stdlib.h>
#include <stdio.h>
#include "../head/Global.h"


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
void Afficher_CONFIG(CONFIG config);

CONFIG Lire_mot_cle(CONFIG config);
CONFIG Lire_similariter(CONFIG config);
CONFIG Lire_niveau(CONFIG config);
bool Presence_utilisateur(CONFIG config);
CONFIG Ajouter_utilisateur(CONFIG config);
CONFIG Ajouter_administrateur(CONFIG config);
CONFIG Supprimer_utilisateur(CONFIG config);
CONFIG Supprimer_administrateur(CONFIG config);
void Ecrire_CONFIG(CONFIG config);
CONFIG Modifier_info_utilisateur(CONFIG config);


#endif