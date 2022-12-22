#ifndef ERREUR_H
#define ERREUR_H

typedef char String[100];
/* Exemple d'utilsation
void main()
{
    String phrase;
    Afficher_Erreur(0,"../Erreur.txt",&phrase);
    printf("%s",phrase);
}
*/
// Stocke la phrase d'erreur dans Phrase
void Afficher_Erreur(int Erreur,char Path[], String* Phrase);



#endif