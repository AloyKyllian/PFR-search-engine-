#include "indexation_gene.h"

int main()
{
     char path [100];
     String Erreurtexte, Erreuraudio, Erreurimage;
     PILE piletexte=init_PILE();
    PILE pileimage=init_PILE();
     PILE pileaudio=init_PILE();
     int deb=0;
    PILE_audio descripteur_audio=NULL;
    //_________________
    //TEXTE
    //_________________
    strcpy(path,"../DATA_FIL_ROUGE_DEV/Textes/");
    recup_path( &piletexte,deb,path,"texte", &Erreurtexte);
    depiler_path ( &piletexte, "texte", &Erreurtexte);
    //_________________
    //AUDIO
    //_________________
    strcpy(path,"../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/");
    recup_path(&pileaudio,deb,path,"audio", &Erreuraudio);
    affichePILE(pileaudio);
    depiler_path ( &pileaudio, "audio", &Erreurtexte);
    //_________________
    //IMAGE
    //_________________
    strcpy(path,"../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB/");
    recup_path(&pileimage,deb,path,"", &Erreurimage);
    deb= pileimage->element.id;
    strcpy(path,"../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB/");
    recup_path(&pileimage,deb,path,"", &Erreurimage);
    affichePILE(pileimage);
    depiler_path ( &pileimage, "image", &Erreurimage);
    //_________________
    //lire chemin test
    //_________________
     printf("______________________\n recuperer chemin texte dans une pile\n");
     lire_chemin (&piletexte, "texte", &Erreurtexte);
     affichePILE(piletexte);
     printf("______________________\naudio\n");
     lire_chemin (&pileaudio, "audio", &Erreurtexte);
     affichePILE(pileaudio);
    //__________________________________
    //stocker descripteur dans une pile
    //__________________________________
    base_descript_empiler_audio (&descripteur_audio);
    affichePILE_audio(descripteur_audio);
    return 0;
}