/**
 * Fait par Loic Maignan, Hugo Lestrade, Kyllian Aloy
 * 
 * Le 23/01/2023
 * 
*/

#include "comparaison.h"

int main()
{

//exemple de code pour utiliser la fonction comparaison

/////////////////////////////////////////////AUDIO////////////////////////////////////////

//recuperer les valeurs de config
int config_fenetre=2048;
int config_intervale=32;
int config_seuil=75;
    int Nb_ligne;
//creation du tableau 
tab_similaire *tab_audio;
int erreur;


//utilisation de ma fonction
tab_audio = comparaison_audio(config_fenetre,config_intervale,"../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/jingle_fi.txt","../base_descripteur/base_descripteur_audio",&erreur ,&Nb_ligne);

//affichage

for (unsigned int j = 0; tab_audio[j].pourcentage>=0 && j<Nb_ligne ; j++)
{
    printf("tab audion Id: %d Pourcentage: %f\n", tab_audio[j].id, tab_audio[j].pourcentage);
}

    free(tab_audio);

printf("\n\n");

/////////////////////////////////////////////IMAGE///////////////////
    tab_similaire *Tab_image;

    Tab_image = Comparaison_descripteur_image(&erreur, "../base_descripteur/base_descripteur_image", "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB/51.txt", 2, &Nb_ligne);

    for (int i = 0; Tab_image[i].pourcentage>=10 && i<Nb_ligne ; i++)
    {
        printf("tab image Id: %d Pourcentage: %f\n", Tab_image[i].id, Tab_image[i].pourcentage);
    }


    free(Tab_image);



printf("\n\n");

/////////////////////////////////////////////TEXTE////////////////////////////////////////


    int* Erreur;


   tab_similaire *Tab_texte;

    Tab_texte = comparaison_texte(666,"../DATA_FIL_ROUGE_DEV/Textes/03-Mimer_un_signal_nerveux_pour.xml","../base_descripteur/base_descripteur_texte",Erreur,&Nb_ligne);


        for (int i = 0; Tab_texte[i].pourcentage>=0.2 && i<Nb_ligne   ; i++)
    {
        printf("tab texte Id: %d Pourcentage: %f\n", Tab_texte[i].id, Tab_texte[i].pourcentage);
    }

    free(Tab_texte);

    
}
