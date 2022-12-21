#include "../head/indexation_gene.h"

int main()
{
    char path [100];
    String Erreurtexte, Erreuraudio, Erreurimage;
    STR texte,image,audio;
    texte.taille=0;
    audio.taille=0;
    image.taille=0;

    //_________________
    //TEXTE
    //_________________
    strcpy(path,"DATA_FIL_ROUGE_DEV/Textes/");
    recup_path_texte(&texte,texte.taille,path, &Erreurtexte);
    //_________________
    //AUDIO
    //_________________
    strcpy(path,"DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/");
    recup_path_img_audio(&audio,image.taille,path, &Erreuraudio);
    //_________________
    //IMAGE
    //_________________
    strcpy(path,"DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_RGB/");
    recup_path_img_audio(&image,image.taille,path, &Erreurimage);
    strcpy(path,"DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB/");
    recup_path_img_audio(&image,image.taille,path, &Erreurimage);

    return 0;
}