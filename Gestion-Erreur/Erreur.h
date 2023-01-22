#ifndef ERREUR_H
#define ERREUR_H
#include "../Gestion-Config/Global.h"
#include <stdbool.h>
#include <string.h>
/* Exemple d'utilsation
void main()
{
    String phrase;
    Afficher_Erreur(0,"../Erreur.txt",&phrase);
    printf("%s",phrase);
}
*/
// Stocke la phrase d'erreur dans Phrase
void Afficher_Erreur(int Erreur,char Path[], char Phrase[]);

#endif