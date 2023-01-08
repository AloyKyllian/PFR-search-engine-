#ifndef indexation_gene_h
#define indexation_gene_h

#include "../Element/element.h"
#include "../Pile/Pile.h"
#include "../Gestion-Config/Config.h"


    void depiler_path ( PILE *pourchemin, String type, int *Erreur);
    void recup_path(PILE *pourchemin, int deb, String path, String type, int *Erreur);
    void lire_chemin (PILE *pourchemin, String type, int * erreur);

   PILE_audio base_descript_empiler_audio (PILE_audio dscr,int * erreur,int *erreur_audio, CONFIG config);
   void depiler_descripteur_audio ( PILE_audio  dscr_audio, int * erreur,int erreur_audio);

   PILE_image base_descript_empiler_image(PILE_image dscr_image, int *erreur,int *erreur_image, CONFIG config);
   void depiler_descripteur_image(PILE_image dscr_image, int erreur_image, int *erreur);

   PILE_texte base_descript_empiler_texte( PILE_texte  dscr_texte, int * erreur, CONFIG config);
   void depiler_descripteur_texte( PILE_texte  dscr_texte, int * erreur, CONFIG config);

   void recuperer_path_tous_fichiers(int *Erreurtexte, int *Erreuraudio, int *Erreurimage);

#endif