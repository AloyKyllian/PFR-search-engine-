#include "indexation_gene.h"

int main()
{
    char path[100];
    int Erreurtexte, Erreuraudio;
    int Erreurimage;
    PILE piletexte_path = init_PILE();
    PILE pileimage_path = init_PILE();
    PILE pileaudio_path = init_PILE();
    int deb = 0;

    
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
        //  printf("______________________\n recuperer chemin texte dans une pile\n");
        //  lire_chemin (&piletexte_path, "texte", &Erreurtexte);
        //  affichePILE(piletexte_path);
        //  printf("______________________\n recuperer chemin image dans une pile\n");
        //  lire_chemin (&pileimage_path, "image", &Erreurimage);
        //  affichePILE(pileimage_path);
        //  printf("______________________\nrecup chemin audio\n");
        //  lire_chemin (&pileaudio_path, "audio", &Erreuraudio);
        //  affichePILE(pileaudio_path);
       

        //__________________________________
        //stocker descripteur dans une pile
        //__________________________________
            CONFIG config;
    config = Lire_CONFIG(&Erreurimage);

    PILE_audio descripteur_audio = NULL;
    descripteur_audio = base_descript_empiler_audio(descripteur_audio, &Erreuraudio,config);
    depiler_descripteur_audio(descripteur_audio, &Erreuraudio);

    PILE_image pileimage = NULL;
    pileimage= base_descript_empiler_image( pileimage,  &Erreurimage,config);
    depiler_descripteur_image(  pileimage, &Erreurimage);

    ELEMENT_texte element_temp;
    printf("HELLO AVANT TEXTE");
    fflush(stdout);
    element_temp.descripteur_texte=descripteur_texte_finale("../DATA_FIL_ROUGE_DEV/Textes/29-Ligue_des_champions___Lyon.xml",5,element_temp.descripteur_texte);
    printf("HELLO AVANT TEXTE"); 
    fflush(stdout);
    //MARCHE PAS
    //_____________
     for(int x=0;x<5 ;x++)
                    {
                         printf("%s    |    %d\n",element_temp.descripteur_texte.tab_mot[x],element_temp.descripteur_texte.tab_app[x]);         
                    }
    //_______________
    PILE_texte piletexte = NULL;
     piletexte= base_descript_empiler_texte( piletexte,  &Erreurimage,config);
     depiler_descripteur_texte(  piletexte, &Erreurimage,config);
        
        return 0;
        
}