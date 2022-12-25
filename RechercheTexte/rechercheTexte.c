#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "Config.h"


/*typedef struct 
{
    String *tab_mot;
    int *tab_app;
    int index;
}tab_total;*/

void rechercheTexte(String tab[], int nb_mot_cle, char* cheminDesc){
    int ID;
    String tabRes[nb_mot_cle][2];
    String mot;
    String nb_mot;
    FILE *fichier =NULL;
    //ouvrir fichier descripteur
    fichier=fopen(cheminDesc,"r");
    
    while (fscanf(fichier,"%d",&ID)!=EOF)
    {
        if(ID<0){
                for(int i=0;i<nb_mot_cle;i++){
                    tab[i][0]=ID;
                    if(strstr(tab[i],fscanf(fichier,"%s",&mot))!=NULL){
                        tabRes[i][1] = fscanf(fichier, "%s", &nb_mot);
                    }
                    else
                        tabRes[i][1]="0";
            }
        }
        
    }
    


}





void main (){

printf("hello world");

}