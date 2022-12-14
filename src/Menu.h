#ifndef Menu_H_INCLUS    
 #define Menu_H_INCLUS   


#include<stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Etat :
//MENUS PRINCIPAUX
#define Menu_general '1'
#define Menu_Admin '2'
#define Menu_Configuration '22'
#define Menu_Visualisation '23'
#define Menu_Utilisateur '3'
#define Menu_texte '31'
#define Menu_image '32'
#define Menu_audio '33'
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
#define Niveau '3'
#define Nombre_de_fenetre '4'
#define Intervalle_de_temps '5'

//Visualisation descripeteur
//Menu Utilisateur
#define texte '1'
#define image '2'
#define audio '3'

//Menu recherche texte
#define Recherche_mots_cle '1'
#define Recherche_par_comparaison '2'
#define Retour 'R'

//Menu recherche image
#define Recherche_nom_couleur '1'

//Menu recherche audio
#define Recherche_comparaison_audio '1'
char choix;
#endif