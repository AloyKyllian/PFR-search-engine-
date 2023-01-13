#include "./rechercheMot.h"

int main(){
	char *mot=(char*)malloc(26);
	int l,erreur;
	int nombre_mot_cle=10;
	tab_Res *tabResultat=malloc(100*sizeof(tab_Res));
	char *chemin="des.txt";
	printf("test recherche par mot clé\n");
	chemin="des.txt";
	printf("Veuillez entrer le mot que vous souhaitez recherché\n");
	scanf("%s",mot);
	rechercheTexte(mot,chemin,tabResultat,&l,&erreur);
	if(erreur==7){
		printf("/n");
	}
	else{
	for(int k=0;k<l;k++){
		printf("ID=%d, nb=%d\n",tabResultat[k].id,tabResultat[k].nb_occurence);
	}}
    return 0;
}