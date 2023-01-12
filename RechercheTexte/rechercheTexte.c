#include "./rechercheTexte.h"

void rechercheTexte(char *mot, char *chemin,tab_Res *tabResultat,int *nb, int *erreur,int nombre_mot_cle){
    FILE *fp;
	FILE *fres;
	//char* tabRes[100][2];
	system("touch ../fichierRes.txt");
	system("touch ../fichierRestrie.txt");
	char* cat="echo ";
	char *commande=(char*)malloc(100);
	char *commande1=(char*)malloc(100);
	char *commande2=(char*)malloc(100);
	char *commande3=(char*)malloc(100);
	char *commande4=(char*)malloc(100);
	//system("echo  00 00 > ./fichierRes.txt");
	int max=0;//pour trier le tableau en ordre decroissant
	int nb_occu;
	int ID;
	int sizemotS;
	int sizeChaine;
	int j=0;//pour mettre une chaine avec le nombre occurence
	int l=0;//pour remplir le tableau resultat
	//tab_Res *tabResultat=malloc(100*sizeof(tab_Res));
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
				}
		}
	}
	else{
    		*erreur=7;}
	fclose(fp);

	//donner le droit d'ecriture dans le fichier resultat afin de trier ensuite
	strcat(commande1,"chmod g+w fichierRes.txt");
	//printf("commande %s:\n",commande1);
	system(commande1);
	free(commande1);
	//trier dans l'ordre decroissant  et les stocker dans un fichier
	strcat(commande2,"sort -k2nr,2nr ./fichierRes.txt >> ./fichierRestrie.txt");
	//printf("commande %s:\n",commande2);
	system(commande2);
	free(commande2);
	//supprimer le fichier avec les resultat de la recherche dans la base des descripteur
	strcat(commande3,"rm ./fichierRes.txt");
	system(commande3);
	free(commande3);
	fres=fopen("./fichierRestrie.txt","rt");
	if(fres!=NULL){
		while(fscanf(fres,"%d %d",&ID,&nb_occu)!=EOF){
			//printf("test : ID=%d, nb=%d\n",ID,nb_occu);
			//stocker le resultat dans un tableau si le nombre d'occurence est plus grand que le seuil qu'on a pris dans le config
			if(nb_occu>=nombre_mot_cle){
				tabResultat[l].id=ID;
				tabResultat[l].nb_occurence=nb_occu;
				l++;}
		}
	}
	else{
			*erreur=7;
		}
	fclose(fres);
	//stocker la taille du tableau pour le lire dans l'affichage
	*nb=l;
	//supprimer le fichier avec les resultat trier
	strcat(commande4,"rm ./fichierRestrie.txt");
	system(commande4);
	free(commande4);
	free(IDstring);
	free(chaine);
	free(nbO);
	free(motS);
}