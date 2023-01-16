#include "comparaison.h"

int main()
{


//exemple de code pour utiliser la fonction comparaison

/////////////////////////////////////////////AUDIO////////////////////////////////////////

//recuperer les valeurs de config
int config_fenetre=2048;
int config_intervale=32;
int config_seuil=75;
//creation du tableau 
tab_similaire *tab_audio;
int erreur;



//utilisation de ma fonction
tab_audio = comparaison_audio(config_fenetre,config_intervale,"../descripteur_a_compare.txt","../descripteur_texte_type.txt",&erreur);

//affichage

for (unsigned int j = 0; tab_audio[j].pourcentage>=75 && tab_audio[j].pourcentage<=100  ; j++)
{
    printf("tab audion Id: %d Pourcentage: %f\n", tab_audio[j].id, tab_audio[j].pourcentage);
}

    free(tab_audio);

printf("\n\n");
/////////////////////////////////////////////IMAGE////////////////////////////////////////

    tab_similaire *Tab_image;
    int Nb_ligne;

    Tab_image = Comparaison_descripteur_image(&erreur, "Recueil_descripteur.txt", "../descripteur_image/DATA_FIL_ROUGE_DEV/TEST_RGB/01.txt", 2, &Nb_ligne);
    

    for (int i = 0; Tab_image[i].pourcentage>=75 && Tab_image[i].pourcentage<=100 ; i++)
    {
        printf("tab image Id: %d Pourcentage: %f\n", Tab_image[i].id, Tab_image[i].pourcentage);
    }


    free(Tab_image);



printf("\n\n");
/////////////////////////////////////////////TEXTE////////////////////////////////////////


    int* Erreur;


   tab_similaire *Tab_texte;

    Tab_texte = comparaison_texte(10,"../Textes/03-Mimer_un_signal_nerveux_pour.xml","michel.txt",Erreur);

        for (int i = 0; Tab_texte[i].pourcentage>=20 && Tab_texte[i].pourcentage<=100  ; i++)
    {
        printf("tab texte Id: %d Pourcentage: %f\n", Tab_texte[i].id, Tab_texte[i].pourcentage);
    }

    free(Tab_texte);
}
