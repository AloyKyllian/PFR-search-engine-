#include "../head/indexation_gene.h"

int main()
{
    char path [100] = "DATA_FIL_ROUGE_DEV/Textes/";
    String Erreur;
    receuillefichiers doctexte;
   // receuillefichiers docimage;
    receuillefichiers docaudio;
    recup_path_texte(&doctexte,path, &Erreur);
    for(int i =0;i<10;i++)
    {
        printf("%s\n",doctexte[i].CHEMIN );
        printf("%s\n",doctexte[i].nom_fic );
        printf("%d\n",doctexte[i].id );
    }
    strcpy(path,"DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON/");
    recup_path_img_audio(&docaudio,path, &Erreur);
    for(int i =0;i<2;i++)
    {
        printf("chemin : %s\n",docaudio[i].CHEMIN );
        printf("nom %s\n",docaudio[i].nom_fic );
        printf("id %d\n",docaudio[i].id );
    }
    strcpy(path,"DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_NB/");
    recup_path_img_audio(&docaudio,path, &Erreur);
    for(int i =0;i<2;i++)
    {
        printf("chemin : %s\n",docaudio[i].CHEMIN );
        printf("nom %s\n",docaudio[i].nom_fic );
        printf("id %d\n",docaudio[i].id );
    }
    return 0;
}