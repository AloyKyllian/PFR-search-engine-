#include "rechercheMot.h"

int main(){
	char *mot=(char*)malloc(26);
	int nbMotCle=10,erreur;
	int nombre_mot_cle=10,nbElementTabRes;
	tab_Res *tabResultat=malloc(100*sizeof(tab_Res));
	char *chemin="../base_descripteur/base_descripteur_texte";
	printf("test recherche par mot clé\n");
	printf("Veuillez entrer le mot que vous souhaitez recherché\n");
	scanf("%s",mot);
	rechercheMot(mot,chemin,tabResultat,nbMotCle,&nbElementTabRes,&erreur);
	if(erreur==7){
		printf("/n");
	}
	else{
	for(int k=0;k<nbElementTabRes;k++){
		printf("ID=%d, nb=%d\n",tabResultat[k].id,tabResultat[k].nb_occurence);
	}}
    return 0;
}