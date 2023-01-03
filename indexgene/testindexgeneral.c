#include "indexation_gene.h"

int main()
{
     char path [100];
     String Erreurtexte, Erreuraudio, Erreurimage;
     PILE piletexte_path=init_PILE();
     PILE pileimage_path=init_PILE();
     PILE pileaudio_path=init_PILE();
     int deb=0;
    PILE_audio descripteur_audio=NULL;
    //_________________
    //TEXTE
    //_________________
    strcpy(path,"../DATA_FIL_ROUGE_DEV/Textes/");
    recup_path( &piletexte_path,deb,path,"texte", &Erreurtexte);
    depiler_path ( &piletexte_path, "texte", &Erreurtexte);
    //_________________
    //AUDIO
    //_________________
    strcpy(path,"../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/");
    recup_path(&pileaudio_path,deb,path,"audio", &Erreuraudio);
    affichePILE(pileaudio_path);
    depiler_path ( &pileaudio_path, "audio", &Erreuraudio);
    //_________________
    //IMAGE
    //_________________
    strcpy(path,"../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB/");
    recup_path(&pileimage_path,deb,path,"image", &Erreurimage);
    deb= pileimage_path->element.id;
    affichePILE(pileimage_path);
    strcpy(path,"../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB/");
    recup_path(&pileimage_path,deb,path,"image", &Erreurimage);
    affichePILE(pileimage_path);
    depiler_path ( &pileimage_path, "image", &Erreurimage);
    //_________________
    //lire chemin test
    //_________________
     printf("______________________\n recuperer chemin texte dans une pile\n");
     lire_chemin (&piletexte_path, "texte", &Erreurtexte);
     affichePILE(piletexte_path);
     printf("______________________\n recuperer chemin image dans une pile\n");
     lire_chemin (&pileimage_path, "image", &Erreurimage);
     affichePILE(pileimage_path);
     printf("______________________\nrecup chemin audio\n");
     lire_chemin (&pileaudio_path, "audio", &Erreuraudio);
     affichePILE(pileaudio_path);
     printf("IFGLUYGFLYUGF");
    //__________________________________
    //stocker descripteur dans une pile
    //__________________________________
    printf("helololo");
    base_descript_empiler_audio (&descripteur_audio);
    affichePILE_audio(descripteur_audio);
    return 0;
}