#ifndef indexation_gene_h
#define indexation_gene_h

#include "../Element/element.h"
#include "../Pile/Pile.h"
#include <errno.h>
typedef struct Estruct_empiler
{   String CHEMIN;
    String nom_fic;
} struct_empiler;

void depiler_path ( PILE *pourchemin, String type, String *Erreur);
void recup_path( PILE *pourchemin, int deb, String path,String type, String *Erreur);


#endif