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
 

    descripteur_audio= base_descript_empiler_audio ( descripteur_audio, &Erreurtexte);
    depiler_descripteur_audio ( descripteur_audio, &Erreurimage);

    int Erreur=NULL;
      FILE *ptr_fic = NULL;
      ELEMENT_image element;
      int total=0;
      IMAGE img;
      char CHEMIN [100] =  "../DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB/63.txt";
      char cheminfichier [200];
      CONFIG config;
      config=Lire_CONFIG(&Erreurimage);
      PILE_image pileimage=NULL;
           img = Lire_image(&Erreur,CHEMIN);
             img = Pre_traitement(&Erreur,img,8);
             element.descripteur_image = Creation_Discripteur(&Erreur,img,config.Nb_Bit_Fort);
            
    
    for(int i = 0; i < element.descripteur_image.Nb_Ligne; i++ )
    {
        // Permet d'afficher q'un certain nombre de valeur
        if( (i % (int)(0.1 *element.descripteur_image.Nb_Colonne)) == 0)
        {
            printf("Val n°%d = %d Quantity = %d\n",i,element.descripteur_image.Bilan[i][0],element.descripteur_image.Bilan[i][1]);
        }
       
        total = total+element.descripteur_image.Bilan[i][1];
    }
    printf("\nTotal de valeur = %d\n",total);
    // pileimage= base_descript_empiler_image( pileimage,  &Erreurimage);
     //depiler_descripteur_image(  pileimage, &Erreurimage);


/*


    //_________________
    //TEXTE
    //_________________
    strcpy(path,"../DATA_FIL_ROUGE_DEV/Textes/");
    
    recup_path( &piletexte_path,deb,path,"texte", &Erreurtexte);
    fflush(stdout);
    affichePILE(piletexte_path);
    printf("hello");
    fflush(stdout);
    //depiler_path ( &piletexte_path, "texte", &Erreurtexte);
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
    printf("helololo\n");
    fflush(stdout);
     descripteur_audio=base_descript_empiler_audio (descripteur_audio, &Erreuraudio);
     affichePILE_audio(descripteur_audio);
     PILE_image pileimage=NULL;
     pileimage= base_descript_empiler_image( pileimage,  &Erreurimage);
     printf("Verification dans le main que le id est empiler\n");
     while (pileimage!=NULL)
     {
        printf("%d \n",pileimage->element.id);
        pileimage=pileimage->suiv;
     }
    return 0;
    */
}