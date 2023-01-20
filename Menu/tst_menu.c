//premier fichier main
#include<stdint.h>
#include <stdio.h>
#include "Menu.h"

int main(){
    char choix[100];
    CONFIG config;
    printf("\nDebut de la Phase d'initialisation\n");
    int erreurConfig=0, erreurIndex=0, erreurTexte=0, erreurImage=0, erreurAudio=0;
    config=Lire_CONFIG(&erreurConfig);
    indexation(config, &erreurImage, &erreurAudio, &erreurTexte, &erreurIndex);
    printf("\nFin de la Phase d'initialisation\n");
    //affichage erreur
    if(erreurConfig==0){
        do{
            MAE(&config,choix,&erreurImage, &erreurAudio, &erreurTexte, &erreurIndex);
        }while(1);
    }
}