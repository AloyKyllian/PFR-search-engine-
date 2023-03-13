//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    22/01/2023
//
#ifndef Menu_H_INCLUS
#define Menu_H_INCLUS
#include "../Connexion/Connexion.h"
#include "../Gestion-Config/Config.h"
#include "../Menu/FichierExist.h"
#include "../RechercheMot/rechercheMot.h"
#include "../indexgene/indexation_gene.h"
#include "../comparaison/comparaison.h"
#include "../LireResultatRecherche/LireResultat.h"
#include "../Gestion-Erreur/Erreur.h"
#include "../../JNA/JNA.h"

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
void MAE(CONFIG *config, char choix[100], int *erreurImage, int *erreurAudio, int *erreurTexte, int *erreurIndex);

// Etat :
// MENUS PRINCIPAUX
#define Menu_general '1'
#define Menu_Admin '2'
#define Menu_Configuration '3'
#define Menu_Visualisation '4'
#define Menu_Utilisateur '5'
#define Menu_texte '6'
#define Menu_image '7'
#define Menu_audio '8'
// Menu General
#define Administrateur '1'
#define Utilisateur '2'
#define Quitter 'Q'
#define Deconnexion 'Q'

// Menu Admin
#define Indexation '1'
#define Configuration '2'
#define Visualisation '3'
#define Retour_Utilisateur '4'

// Menu configuration
#define Nombre_de_mot_cle '1'
#define Similarité '2'
#define Nombre_de_bits '3'
#define Nombre_de_fenetre '4'
#define Intervalle_de_temps '5'
#define seuil '6'

// Visualisation descripeteur
// Menu Utilisateur
#define texte '1'
#define image '2'
#define audio '3'

// Menu recherche texte
#define Recherche_mots_cle '1'
#define Recherche_par_comparaison_Texte '2'
#define Retour 'R'

// Menu recherche image
#define Recherche_comparaison_Image '1'

// Menu recherche audio
#define Recherche_comparaison_Audio '1'

//
#define oui '1'
#define non '2'

#define AutreFichier '1'

#endif