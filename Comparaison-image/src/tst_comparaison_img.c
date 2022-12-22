#include "../head/Comparaison-image.h"

void main()
{
    IMAGE img_1;
    IMAGE img_2;
    DESCRIPTEUR_IMAGE di_1;
    DESCRIPTEUR_IMAGE di_2;
    int Erreur;
    int similariter;

    img_1 = Lire_image(&Erreur,"../../Descripteur-image/DATA_FIL_ROUGE_DEV/TEST_RGB/01.txt");
    img_1 = Pre_traitement(&Erreur,img_1,2);
    di_1 = Creation_Discripteur(&Erreur,img_1,2);

    img_2 = Lire_image(&Erreur,"../../Descripteur-image/DATA_FIL_ROUGE_DEV/TEST_RGB/01.txt");
    img_2 = Pre_traitement(&Erreur,img_1,2);
    di_2 = Creation_Discripteur(&Erreur,img_1,2);

    Comparaison_image(di_1,di_2,&similariter);
    printf("%d", similariter);
}