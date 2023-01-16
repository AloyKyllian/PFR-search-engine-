#include "comparaison.h"

int main()
{


//exemple de code pour utiliser la fonction comparaison

//recuperer les valeurs de config
int config_fenetre=2048;
int config_intervale=32;
int config_seuil=75;
//creation du tableau 
tab_similaire *tab;
int erreur;

//utilisation de ma fonction
tab = comparaison_audio(config_seuil,config_fenetre,config_intervale,"../descripteur_a_compare.txt","../descripteur_texte_type.txt");

//affichage

for (unsigned int j = 0; tab[j].pourcentage>=config_seuil && tab[j].pourcentage<=100  ; j++)
{
    printf(" %f         %i\n ", tab[j].pourcentage,tab[j].id);
}

    free(tab);


/*

    tab_similaire *Tab;
    int erreur;
    int Nb_ligne;

    Tab = Comparaison_descripteur_image(&erreur, "Recueil_descripteur.txt", "../descripteur_image/DATA_FIL_ROUGE_DEV/TEST_RGB/01.txt", 2, &Nb_ligne);
    
    printf("Test de comparaison de 1 image a %d autres", Nb_ligne);
    for (int i = 0; i < Nb_ligne; i++)
    {
        printf("\nId: %d Pourcentage: %f", Tab[i].id, Tab[i].pourcentage);
    }


*/
/*












    int* Erreur;





    comparaison_texte(10,"../Textes/03-Mimer_un_signal_nerveux_pour.xml","michel.txt",Erreur,0);
    */
}
