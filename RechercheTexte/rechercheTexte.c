#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../head/Config.h"


void rechercheTexte(char *mot, char *chemin){
    FILE *fp;
   
	char* ID=(char*)malloc(5);
	char* chaine=(char*)malloc(100);
	char* motS=(char*)malloc(27);
	strcpy(motS,mot);
	strcat(motS,"|");
	fp = fopen(chemin, "rt");
	if (fp != NULL){ 
		while(fscanf(fp,"%s",chaine)!=EOF){
				if(chaine[0]=='-'){
	    			strcpy(ID,chaine);
	    			//printf("ID=%s\n",ID);
	    		}
		    	if (strstr(chaine,motS) !=NULL){
		    		printf("chaine= %s et titre=%s\n",chaine,ID);}
					//mettre le resultat dans un tableau dynamique
		    	}
		    	}
	else{
    		printf("Impossible d'ouvrir le fichier\n");}
	fclose(fp);

}

void main(){
	char *mot=(char*)malloc(26);
	char *chemin="des.txt";
	printf("test recherche par mot clé\n");
	chemin="des.txt";
	printf("Veuillez entrer le mot que vous souhaitez recherché\n");
	scanf("%s",mot);
	rechercheTexte(mot,chemin);
}