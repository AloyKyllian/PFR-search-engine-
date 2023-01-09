#include "./rechercheTexte.h"
int main(){
	char *mot=(char*)malloc(26);
	char *chemin="des.txt";
	printf("test recherche par mot clé\n");
	chemin="des.txt";
	printf("Veuillez entrer le mot que vous souhaitez recherché\n");
	scanf("%s",mot);
	rechercheTexte(mot,chemin);
    return 0;
}
