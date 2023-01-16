#ifndef indexation_gene_h
#define indexation_gene_h

#include "../Element/element.h"
#include "../Pile/Pile.h"
#include "../Gestion-Config/Config.h"

//empile le chemin et affecter un id a chaque fichier
void recup_path(PILE *pourchemin, int deb, String path, String type, int *Erreur);
// depiler le chemin de le fichier liste_base_texte ou liste _base_audio ou liste_base_image
void depiler_path(PILE *pourchemin, String type, int *Erreur);
//remplir les fichiers list_base pour chaque fichier
void recuperer_path_tous_fichiers(int *Erreurtexte, int *Erreuraudio, int *Erreurimage);

//_____
//AUDIO
//_____
// EMPILE LEs DESCRIPTEUR AUDIO AVEC leur ID DANS UNE PILE
PILE_audio base_descript_empiler_audio(PILE_audio dscr, int *erreur, int *erreur_audio, CONFIG config);
// DEPILE LES DESCRIPTEURS AUDIO DANS LE FICHIER BASE_DESCRIPTEUR
void depiler_descripteur_audio(PILE_audio dscr_audio, int *erreur, int erreur_audio);

//_____
//IMAGE
//_____
PILE_image base_descript_empiler_image(PILE_image dscr_image, int *erreur, int *erreur_image, CONFIG config);
void depiler_descripteur_image(PILE_image dscr_image, int erreur_image, int *erreur);

//_____
//TEXTE
//_____
PILE_texte base_descript_empiler_texte(PILE_texte dscr_texte, int *erreur, CONFIG config);
void depiler_descripteur_texte(PILE_texte dscr_texte, int *erreur, CONFIG config);

//INDEXATION FERME de chaque type de fichier
void indexation_audio(CONFIG config, int *Erreur, int *Erreur_audio);
void indexation_texte(CONFIG config, int *Erreur, int *Erreur_texte);
void indexation_image(CONFIG config, int *Erreur, int *Erreur_image);


//verifie si un fichier a ete ajoute 
// si un fichier a ete ajoute l'indexe 
void indexation_ouverte(CONFIG config, String type, int *Erreurimage, int *Erreuraudio, int *Erreurtexte, int *Erreur);


void indexation_generale_ferme(CONFIG config, int *Erreurimage, int *Erreuraudio, int *Erreurtexte, int *Erreur);

//si les fichiers liste_base sont vides lancer indexation ferme
//sinon si verifie si un fichier a ete ajoute pour lindexer 
//sinon ne rien faire
void indexation(CONFIG config, int *Erreurimage, int *Erreuraudio, int *Erreurtexte, int *Erreur);

//indexe un seul fichier 
// ajoute son id et chemin dans liste_base et ajoute son descripteur dans les base_descripteur
void ajoutfichier(CONFIG config, String type, String chemin, int *Erreur);
// supprime id et chemin dans liste_base et supprime le descripteur associé
void Supprimer_Descripteur(int *Erreur, char Nom_Fichier[], char type_fichier[]);
// recupere l'id a affecter
int recupererDernierID(String type, int *Erreur);

#endif