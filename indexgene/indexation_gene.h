#ifndef indexation_gene_h
#define indexation_gene_h

#include "../Element/element.h"
#include "../Pile/Pile.h"
#include "../Gestion-Config/Config.h"

void depiler_path(PILE *pourchemin, String type, int *Erreur);
void recup_path(PILE *pourchemin, int deb, String path, String type, int *Erreur);
void lire_chemin(PILE *pourchemin, String type, int *erreur);

PILE_audio base_descript_empiler_audio(PILE_audio dscr, int *erreur, int *erreur_audio, CONFIG config);
void depiler_descripteur_audio(PILE_audio dscr_audio, int *erreur, int erreur_audio);

PILE_image base_descript_empiler_image(PILE_image dscr_image, int *erreur, int *erreur_image, CONFIG config);
void depiler_descripteur_image(PILE_image dscr_image, int erreur_image, int *erreur);

PILE_texte base_descript_empiler_texte(PILE_texte dscr_texte, int *erreur, CONFIG config);
void depiler_descripteur_texte(PILE_texte dscr_texte, int *erreur, CONFIG config);

void indexation_audio(CONFIG config, int *Erreur, int *Erreur_audio);
void indexation_texte(CONFIG config, int *Erreur, int *Erreur_texte);
void indexation_image(CONFIG config, int *Erreur, int *Erreur_image);

void recuperer_path_tous_fichiers(int *Erreurtexte, int *Erreuraudio, int *Erreurimage);

void indexation_generale_ferme(CONFIG config, int *Erreurimage, int *Erreuraudio, int *Erreurtexte, int *Erreur);
void indexation_ouverte(CONFIG config, String type, int *Erreurimage, int *Erreuraudio, int *Erreurtexte, int *Erreur);

void indexation(CONFIG config, int *Erreurimage, int *Erreuraudio, int *Erreurtexte, int *Erreur);

void ajoutfichier(CONFIG config, String type, String chemin, int *Erreur);
void Supprimer_Descripteur(int *Erreur, char Nom_Fichier[], char type_fichier[]);
int recupererDernierID(String type, int *Erreur);

#endif