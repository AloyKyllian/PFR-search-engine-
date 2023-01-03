#ifndef indexation_gene_h
#define indexation_gene_h

#include "../Element/element.h"
#include "../Pile/Pile.h"
#include "../Gestion-Config/Config.h"


    void depiler_path ( PILE *pourchemin, String type, String *Erreur);
    void recup_path(PILE *pourchemin, int deb, String path, String type, String *Erreur);
    void lire_chemin (PILE *pourchemin, String type, String * erreur);
   PILE_audio base_descript_empiler_audio (PILE_audio dscr,String * erreur);

#endif