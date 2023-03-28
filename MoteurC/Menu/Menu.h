//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    22/01/2023
//
#ifndef Menu_H
#define Menu_H

#include <stdlib.h>
#include <stdio.h>

#include "../Gestion-Config/Config.h"
#include "../RechercheMot/rechercheMot.h"
#include "../indexgene/indexation_gene.h"
#include "../comparaison/comparaison.h"
#include "../Gestion-Erreur/Erreur.h"
#include "ecrireCJava.h"

/**
 * @brief
 *La fonction MAE gère les différents menus de l'application, permettant à un utilisateur ou un administrateur de naviguer entre les différentes options.
 Il y a un menu général, un menu administrateur, un menu utilisateur et des sous-menus pour la recherche de fichiers de différents types (texte, image, audio).
 Le menu général permet de choisir entre les options de connexion en tant qu'administrateur ou utilisateur, et de quitter le programme.
 Le menu administrateur permet aux utilisateurs connectés en tant qu'administrateur de gérer les utilisateurs et les fichiers.
 Le menu utilisateur permet aux utilisateurs de rechercher des fichiers par mot-clé ou par comparaison de textes, de visualiser les résultats de la recherche et de retourner au menu précédent ou de quitter le programme.
 * @param config
 * @param choix
 * @param erreurImage
 * @param erreurAudio
 * @param erreurTexte
 * @param erreurIndex
 */
typedef struct
{
    char entiere[100];
    char fonction[100];
} chaine_typ;
//void MAE(CONFIG *config, char choix[100], int *erreurImage, int *erreurAudio, int *erreurTexte, int *erreurIndex);
chaine_typ lire_fichier();
void choixfonction();

#endif