#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "Config.h"


void rechercheTexte(char *mot,char* chemin){
    FFILE *fp;
    fp = fopen("des.txt", "rt");
	char* ID=(char*)malloc(100);
	char* chaine=(char*)malloc(100);
	char* res=(char*)malloc(100);

	if (fp != NULL){ 
		while(fscanf(fp,"%s",chaine)!=EOF){
			//printf("lecture chaine =%s\n",chaine);
			
			res=strpbrk(chaine,"-");
			//printf("res=%s\n",res); 
	    		if(res!=NULL){
	    			//printf("res de if=%s\n",res);
	    			strcpy(ID,res);
	    			//printf("ID=%s\n",ID);
	    		}
	    		//printf("test ID=%s\n",ID);
		    	if (strstr(chaine,mot) !=NULL){
		    		printf("chaine= %s et titre=%s\n",chaine,ID);}
		    	}
		    	}
	else{
    		printf("Impossible d'ouvrir le fichier\n");}
	fclose(fp);

}


void main (){

printf("hello world");

}