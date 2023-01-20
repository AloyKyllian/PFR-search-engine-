#ifndef Menu_H_INCLUS
#define Menu_H_INCLUS
#include "../Connexion/Connexion.h"
#include "../Gestion-Config/Config.h"
#include "../Menu/FichierExist.h"
#include "../RechercheMot/rechercheMot.h"
#include "../indexgene/indexation_gene.h"
#include "../comparaison/comparaison.h"

void MAE(CONFIG config,char choix[100], interreurImage, int erreurAudio, interreurTexte, int *erreurIndex);
//Etat :
//MENUS PRINCIPAUX
#define Menu_general '1'
#define Menu_Admin '2'
#define Menu_Configuration '3'
#define Menu_Visualisation '4'
#define Menu_Utilisateur '5'
#define Menu_texte '6'
#define Menu_image '7'
#define Menu_audio '8'
//Menu General
#define Administrateur '1'
#define Utilisateur '2'
#define Quitter 'Q'
#define Deconnexion 'Q'


//Menu Admin
#define Indexation '1'
#define Configuration '2'
#define Visualisation '3'
#define Retour_Utilisateur '4'

//Menu configuration 
#define Nombre_de_mot_cle '1'
#define Similarité '2'
#define Nombre_de_bits '3'
#define Nombre_de_fenetre '4'
#define Intervalle_de_temps '5'

//Visualisation descripeteur
//Menu Utilisateur
#define texte '1'
#define image '2'
#define audio '3'

//Menu recherche texte
#define Recherche_mots_cle '1'
#define Recherche_par_comparaison_Texte '2'
#define Retour 'R'

//Menu recherche image
#define Recherche_comparaison_Image '1'

//Menu recherche audio
#define Recherche_comparaison_Audio '1'

//
#define oui '1'
#define non '2'

#define AutreFichier '1'


#endif