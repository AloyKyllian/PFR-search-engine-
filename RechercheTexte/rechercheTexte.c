#include "./rechercheTexte.h"

void rechercheTexte(char *mot, char *chemin){
    FILE *fp;
	//char* tabRes[100][2];
	system("touch ../fichierRes.txt");
	char* cat="echo ";
	char *commande=(char*)malloc(100);
	//system("echo  00 00 > ./fichierRes.txt");
	int max=0;//pour trier le tableau en ordre decroissant
	int nb_occu;
	int ID;
	int sizemotS;
	int sizeChaine;
	int j=0;//pour mettre une chaine avec le nombre occurence
	int l=0;//pour remplir le tableau resultat
	tab_Res *tabResultat=malloc(100*sizeof(tab_Res));
	char* IDstring=(char*)malloc(5);
	char* chaine=(char*)malloc(100);
	char* nbO=(char*)malloc(5);
	char* motS=(char*)malloc(27);
	strcpy(motS,mot);
	strcat(motS,"|");
	sizemotS=strlen(motS);
	fp = fopen(chemin, "rt");
	if (fp != NULL){ 
		while(fscanf(fp,"%s",chaine)!=EOF){
				if(chaine[0]=='-'){
	    			strcpy(IDstring,chaine);
	    			//printf("ID=%s\n",IDstring);
	    		}
		    	if (strstr(chaine,motS) !=NULL){
		    		printf("chaine= %s et titre=%s\n",chaine,IDstring);
					sizeChaine=strlen(chaine);
					j=0;
					//stocker le nombre d'occurence dans une chaine a part
					//prendre que la partie du nombre d'occurence
					for(int i=sizemotS;i<=sizeChaine;i++){
						nbO[j]=chaine[i];
						j++;
					}
					
					//stocker les donnee dans un fichier pour les trier avec la commande sort de linux
					strcpy(commande,cat);
					strcat(commande,IDstring);
					strcat(commande," ");
					strcat(commande,nbO);
					strcat(commande," >> ./fichierRes.txt");
					//printf("la commande %s\n", commande);
					system(commande);
					free(commande);





















					
					//mettre le resultat dans un tableau dynamique
					//tabResultat[l].id=ID;
					//tabResultat[l].nb_occurence=nb_occu;

					 
					// transformer la chaine du nombre d'occurence en entier
					nb_occu=atoi(nbO);
					// transformer la chaine du ID en entier
					ID=atoi(IDstring);
		    	}}
		    	}
	else{
    		printf("Impossible d'ouvrir le fichier\n");}
	fclose(fp);
}