#include "../head/indexation_gene.h"

int main()
{
    char path [100] = "/Users/yasmine/programme1A/PFR/DATA_FIL_ROUGE_DEV/Textes/";
    String Erreur;
    receuillefichiers doctexte;
   // receuillefichiers docimage;
    receuillefichiers docaudio;
    recup_path(&doctexte,path, &Erreur);
    for(int i =0;i<10;i++)
    {
        printf("%s\n",doctexte[i].CHEMIN );
        printf("%s\n",doctexte[i].nom_fic );
        printf("%d\n",doctexte[i].id );
    }
    strcpy(path,"/Users/yasmine/programme1A/PFR/DATA_FIL_ROUGE_DEV/IMG_et_AUDIO/TEST_SON");
    recup_path(&docaudio,path, &Erreur);
    for(int i =0;i<3;i++)
    {
        printf("%s\n",docaudio[i].CHEMIN );
        printf("%s\n",docaudio[i].nom_fic );
        printf("%d\n",docaudio[i].id );
    }
    return 0;
}