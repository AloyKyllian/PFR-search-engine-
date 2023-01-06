#include "indexation_gene.h"

int main()
{
    char path[100];
    int Erreurtexte, Erreuraudio;
    int Erreurimage;
    recuperer_path_tous_fichiers(&Erreurtexte, &Erreuraudio, &Erreurimage);

    CONFIG config;
    config = Lire_CONFIG(&Erreurimage);

    PILE_audio descripteur_audio = NULL;
    descripteur_audio = base_descript_empiler_audio(descripteur_audio, &Erreuraudio, config);
    depiler_descripteur_audio(descripteur_audio, &Erreuraudio);

    PILE_image pileimage = NULL;
    int erreur, erreur_image,erreur_empiler;
    pileimage = base_descript_empiler_image( pileimage, &erreur, &erreur_image,  config);
    depiler_descripteur_image(pileimage, &Erreurimage);

    ELEMENT_texte element_temp;
    printf("HELLO AVANT TEXTE");
    fflush(stdout);
    element_temp.descripteur_texte = descripteur_texte_finale("../DATA_FIL_ROUGE_DEV/Textes/29-Ligue_des_champions___Lyon.xml", 5, element_temp.descripteur_texte);
    printf("HELLO AVANT TEXTE");
    fflush(stdout);
    // MARCHE PAS
    //_____________
    for (int x = 0; x < 5; x++)
    {
        printf("%s    |    %d\n", element_temp.descripteur_texte.tab_mot[x], element_temp.descripteur_texte.tab_app[x]);
    }
    //_______________
    PILE_texte piletexte = NULL;
    piletexte = base_descript_empiler_texte(piletexte, &Erreurimage, config);
    depiler_descripteur_texte(piletexte, &Erreurimage, config);

    return 0;
}