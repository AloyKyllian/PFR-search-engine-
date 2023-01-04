#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../descript_audio/descript_audio.h"


void comparaison(int val_lu,descri_audio descripteur_comparé,int *ligne,int *colonne,int intervalle,descri_audio descri,float fenetre){

    int id=val_lu;
    float pourcentage;
    descripteur_comparé.size_x=*ligne;
    descripteur_comparé.size_y=intervalle;
    descri_audio descripteur_intervale;
    descripteur_intervale.tab = malloc(descri.size_x * sizeof(*descripteur_intervale.tab));//creation du tableau
    for (int i = 0; i <= descri.size_x; i++)
    {
        descripteur_intervale.tab[i] = malloc(descri.size_y * sizeof(**descripteur_intervale.tab));
    }
    
    for(int intnbr=0;intnbr<=descripteur_comparé.size_x-descri.size_x;intnbr++)
    {int comparateur=0;
        for (unsigned i = 0; i < descri.size_x; ++i)
        {
            for (unsigned j = 0; j < descri.size_y; ++j)
                {
                    if(descripteur_comparé.tab[i+intnbr][j]-descri.tab[i][j]>0)
                        comparateur+=descripteur_comparé.tab[i+intnbr][j]-descri.tab[i][j];
                    else
                        comparateur+=descri.tab[i][j]-descripteur_comparé.tab[i+intnbr][j];
                    //printf("%d   ",comparateur);
                }
                //printf("\r\n");
        }
        pourcentage=comparateur/(fenetre*4.)*100;
        pourcentage=100-pourcentage;
        printf("\n pourcentage : %f   \n",pourcentage);
    }

    *ligne=0;
    *colonne=0;



}




void comparaison_audio(int fenetre,int intervalle,char* chemin_descripteur_compare,char* chemin_descripteur_audio){


int erreur;

descri_audio descri;


    descri=Descripteur_audio(2048,32,"../descripteur_a_compare.txt",descri,&erreur);

//descri = Descripteur_audio(fenetre,intervalle,chemin_descripteur_compare,descri,&erreur);





    int nbr_val;
    int val_lu;
    FILE* fichier = NULL;
    fichier = fopen("../descrripteur_texte_type.txt", "r");
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
    int lig=0;
    int col=0;
    int bonneval=0;


    int ligne=0;
    int colonne=0;

    int fin;
    descri_audio descripteur_compare;
    descripteur_compare.tab = malloc(10000 * sizeof(*descripteur_compare.tab));//creation du tableau
    for (int i = 0; i <= 10000; i++)
    {
        descripteur_compare.tab[i] = malloc(intervalle * sizeof(**descripteur_compare.tab));
    }





    while(fin!=EOF)
    {
        fin=fscanf(fichier,"%d",&val_lu);
        if(val_lu<0 && val_lu!=-1)
        {
           comparaison( val_lu, descripteur_compare, &ligne, &colonne, intervalle, descri, fenetre);
        }
           

        if(val_lu>=0)
        {
            descripteur_compare.tab[ligne][colonne]=val_lu;
            //printf(" %d ",descripteur_compare.tab[ligne][colonne]);
            colonne++;
            if(colonne==32)
            {
                //printf("\n");
                colonne=0;
                ligne++;
            }
        }
}
fclose(fichier);
    descripteur_compare.size_x=ligne;
    descripteur_compare.size_y=intervalle;


comparaison( val_lu, descripteur_compare, &ligne, &colonne, intervalle, descri, fenetre);

}





void main (){



printf("hello");

int erreur;

//descri_audio mabite;


//mabite=Descripteur_audio(2048,32,"../descripteur_a_compare.txt",mabite,&erreur);


/*
    for (unsigned i = 0; i < mabite.size_x; ++i)
    {
        for (unsigned j = 0; j < mabite.size_y; ++j)
        {
            printf(" |%3d| ",mabite.tab[i][j]);
        }
        printf("\r\n");
    }

*/
comparaison_audio(2048,32,"../descripteur_a_comparé.txt","../descripteur_texte_type.txt");

/*

    descri_audio descri;
    descri.size_x=2;
    descri.size_y=32;
    descri.tab = malloc(2 * sizeof(*descri.tab));//creation du tableau
    for (int i = 0; i <= 2; i++)
    {
        descri.tab[i] = malloc(32 * sizeof(**descri.tab));
    }


                for (unsigned i = 0; i < descri.size_x; ++i)
            {
                for (unsigned j = 0; j < descri.size_y; ++j)
                    {
                        descri.tab[i][j]=64;
                    }
                    printf("\r\n");
            }

comparaison_audio(2048,32,descri,"f");

*/

}