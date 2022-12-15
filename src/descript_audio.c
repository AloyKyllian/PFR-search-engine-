#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "../head/Global.h"


int ** Descripteur_audio(int fenetre,int intervalle,char *chemin_fichier,int** tableau){//demander comment recuperer le chemin et nom du fichier
    double pas;
    int fe=0;//(nombre de fenetre)
    int nbr_val=0;
    int k;//(nbr_val_fenetre)
    int m;
    int i=0;
    double val;
    FILE* fichier = NULL;
    char c;

    //chemin_fichier="../son/jingle_fi.txt";
    fichier = fopen(chemin_fichier, "r");
    if(fichier==NULL){                           
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
    while(fscanf(fichier,"%lf",&val)!=EOF){
        nbr_val++;
    }
    k=(nbr_val/fenetre)+1;
    tableau = malloc(k * sizeof(*tableau));
    for (int i = 0; i < k; i++)
    {
        tableau[i] = malloc(intervalle * sizeof(**tableau));
    }

    for (unsigned i = 0; i < k; ++i)
    {
        for (unsigned j = 0; j < intervalle; ++j)
        {
            printf(" |%3d| ",tableau[i][j]);
        }
        printf("\r\n");
    }
    k=0;
    pas=2./intervalle;
    rewind(fichier);
    while(fscanf(fichier,"%lf",&val)!=EOF){

        if(i==fenetre)
        {
            i=0;
            k++;
        }

        if(nbr_val<=fenetre)
        {
            for(m=0;-1+m*pas<1;m++)
            {

                if(val>=pas*m-1 && val<pas*(m+1)-1)
                {

                    if(val<1&&val>-1&&m<intervalle)
                        tableau[k][m]++;
                }
                
            }
        }
          
        for(m=0;m<intervalle;m++)
        {
            if((val>=(pas*m-1)) && (val<(pas*(m+1)-1)))
            {
             
                if(val<1&&val>-1&&m<intervalle)
                    tableau[k][m]++;
            }
               
        }
        i++;
        nbr_val--;
    }
    fclose(fichier);


    for (unsigned i = 0; i < k; ++i)
    {
        for (unsigned j = 0; j < m; ++j)
        {
            printf(" |%3d| ",tableau[i][j]);
        }
        printf("\r\n");
    }
return tableau;
}




void main(){
  int **mabite;

    mabite=Descripteur_audio(2048,32,"../son/corpus_fi.txt",mabite);

    //printf("%d",mabite[5][15]);

}



