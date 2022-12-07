#include <stdint.h>
#include <stdio.h>
#include "Global.h"

char Descripteur_test(int nb_fenetre,int intervalle){
    float val;
    FILE *fichier = NULL;



    while(fscanf(fichier,"%f",&val)!=NULL){

        printf("%f",val);

    }


}