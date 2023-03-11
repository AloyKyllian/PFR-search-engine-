/**
 * Fait par Kyllian Aloy
 * 
 * Le 23/01/2023
 * 
*/
#include"descripteur_audio.h"

int main()
{
    int erreur;
    descri_audio tableau;
    int config_fenetre=2048;
    int config_intervalle=32;
    char chemin[100]="../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/jingle_fi.txt";

    tableau=Descripteur_audio(config_fenetre,config_intervalle,chemin,&erreur);
    
    for (unsigned i = 0; i < tableau.ligne; ++i)
    {
        for (unsigned j = 0; j < tableau.colonne; ++j)
        {
            printf(" |%3d| ",tableau.tab[i][j]);
        }
        printf("\r\n");
    }

    for (int i = 0; i < tableau.ligne; i++)//creation des colonne du tableau
    {
        free(tableau.tab[i]);
    }
    free(tableau.tab);
}