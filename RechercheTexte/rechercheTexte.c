#include "./rechercheTexte.h"

void rechercheTexte(char *mot, char *chemin){
    FILE *fp;
	//String tabRes[][]=(String)malloc(int size)
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