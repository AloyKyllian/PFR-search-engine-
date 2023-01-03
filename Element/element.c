#include "element.h"

void affiche_ELEMENT(ELEMENT element)
{
      printf("%d | %s\n", element.id, element.CHEMIN);
}

void affiche_ELEMENT_audio(ELEMENT_audio element)
{
      printf("%d \n", element.id);
      for (unsigned i = 0; i < element.descripteur.size_x; ++i)
    {
        for (unsigned j = 0; j < element.descripteur.size_y; ++j)
        {
            printf(" |%3d| ",element.descripteur.tab[i][j]);
        }
        printf("\r\n");
    }
    fflush(stdout);
}

void affiche_ELEMENT_image(ELEMENT_image element)
{
//     int total=0;
// for(int i = 0; i < pow(2,Nb_Bit_Fort*img.Nb_composante); i++ )
//     {
//         // Permet d'afficher q'un certain nombre de valeur
//         if( (i % (int)(0.1 *pow(2,Nb_Bit_Fort*img.Nb_composante))) == 0)
//         {
//             printf("Val n°%d = %d Quantity = %d\n",i,element.descripteur_image.Bilan[i][0],element.descripteur_image.Bilan[i][1]);
//         }
       
//         total = total+element.descripteur_image.Bilan[i][1];
//     }
//     printf("\nTotal de valeur = %d\n",total);
};
void affect_ELEMENT_image(ELEMENT_image *elemaffect, ELEMENT_image e2)
{
    *elemaffect=e2;
};

void affect_ELEMENT(ELEMENT *elemaffect, ELEMENT e2)
{
    *elemaffect=e2;
}

void affect_ELEMENT_audio(ELEMENT_audio *elemaffect, ELEMENT_audio e2)
{
    *elemaffect=e2;
}
