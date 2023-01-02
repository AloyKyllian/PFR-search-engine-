#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "Config.h"


void rechercheTexte(char *mot,char* chemin){
    FILE *fp;
	FILE *grepFic;
	system("touch ../PFRtestMenu/grepRes.txt");
	char* grep="grep -rliw ";
	//char* mot="soleil";
	//char* chemin=" ./descripteur_texte";
	char* commande=(char*)malloc(200);
	char* chaine=(char*)malloc(200);
	char* motCh=(char*)malloc(20);
	strcpy(commande,grep);
	strcat(commande,mot);
	strcat(commande,chemin);
	strcat(commande," > ./grepRes.txt");
	//printf("la commande %s\n", commande);
	system(commande);
	free(commande);

    //resultat finale de la recherche, pour avoir le nom des fichiers 
	fp=fopen("./grepRes.txt","rt");
	if(fp!=NULL){
	    while(!feof(fp)){
            

	  } 
	 }
   	 fclose(fp); 
	
    


}





void main (){

printf("hello world");

}