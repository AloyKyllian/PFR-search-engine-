//premier fichier main
#include<stdint.h>
#include <stdio.h>
#include "Menu.h"

int main(){
    char choix[100];
    CONFIG config;
    int erreurConfig=0, erreurIndex=0, erreurTexte=0, erreurImage=0, erreurAudio=0;
    config=Lire_CONFIG(&erreurConfig);
    indexation_generale_ferme(config, erreurImage, erreurAudio, erreurTexte, erreurIndex);
    //affichage erreur
    if(erreurConfig==0){
        do{
        MAE(config,choix);
        }while(1);
    }
}