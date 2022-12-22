#include "../head/Comparaison-image.h"

void main()
{
    IMAGE img_1;
    IMAGE img_2;
    IMAGE img_3;
    DESCRIPTEUR_IMAGE di_1;
    DESCRIPTEUR_IMAGE di_2;
    DESCRIPTEUR_IMAGE di_3;
    int Erreur;
    int similariter;

    img_1 = Lire_image(&Erreur,"../../Descripteur-image/DATA_FIL_ROUGE_DEV/TEST_RGB/01.txt");
    img_1 = Pre_traitement(&Erreur,img_1,2);
    di_1 = Creation_Discripteur(&Erreur,img_1,2);

    img_2 = Lire_image(&Erreur,"../../Descripteur-image/DATA_FIL_ROUGE_DEV/TEST_RGB/01.txt");
    img_2 = Pre_traitement(&Erreur,img_2,2);
    di_2 = Creation_Discripteur(&Erreur,img_2,2);

    img_3 = Lire_image(&Erreur,"../../Descripteur-image/DATA_FIL_ROUGE_DEV/TEST_RGB/02.txt");
    img_3 = Pre_traitement(&Erreur,img_3,2);
    di_3 = Creation_Discripteur(&Erreur,img_3,2);

    Comparaison_image(di_1,di_2,&similariter);
    printf("Test fichier identique : Identique = %d", similariter);

    Comparaison_image(di_1,di_3,&similariter);
    printf("\nTest fichier non identique : Identique = %d", similariter);
}