//
// AUTEUR :
//          YOUSSERA ACHACHERA
// DERNIERE VERSION :
//    16/01/2023
//

#include "rechercheMot.h"

void rechercheMot(char *mot, char *chemin, tab_similaire *tabResultat, int nb_mot, int *nbElTab, int *erreur)
{
	FILE *fp;
	FILE *fres;
	system("touch fichierRes.txt");		// Création d'un fichier temporaire pour stocker les résultats de la recherche
	system("touch fichierRestrie.txt"); // Création d'un autre fichier temporaire pour stocker les résultats triés
	char *echo = "echo ";
	char *commande = (char *)malloc(100);
	char *commande1 = (char *)malloc(100);
	char *commande2 = (char *)malloc(100);
	char *commande3 = (char *)malloc(100);
	char *commande4 = (char *)malloc(100);
	char *nb_occu = (char *)malloc(10);
	int ID;
	int nombre_occurence;
	int l = 0; // pour remplir le tableau resultat
	char *IDstring = (char *)malloc(5);
	char *chaine = (char *)malloc(100);
	fp = fopen(chemin, "rt"); // ouverture du fichier de descripteurs en mode lecture
	if (fp != NULL)
	{ // on lit ligne par ligne le fichier descripteur texte passer en parametre et si on rencontre un numero negatif on le stock comme ID
		while (fscanf(fp, "%s", chaine) != EOF && atoi(chaine) < 0)
		{
			strcpy(IDstring, chaine);
			for (int i = 0; i < nb_mot; i++)
			{ // on commence a parcourir les mots du descripteur ainsi que leurs nombre d'occurence
				fscanf(fp, "%s    |    %s", chaine, nb_occu);
				if (strcmp(chaine, mot) == 0) // des que le mot recherché est trouvé on stock son nombre d'occurence
				{
					// Stockage des données dans un fichier pour trier ensuite avec la commande sort de Linux
					strcpy(commande, echo);
					strcat(commande, IDstring);
					strcat(commande, " ");
					strcat(commande, nb_occu);
					strcat(commande, " >> fichierRes.txt");
					system(commande);
				}
			}
		}
	}
	else
	{
		*erreur = 7; // Erreur lors de l'ouverture du fichier
	}
	fclose(fp);

	// Donner les droits d'écriture sur le fichier de résultats pour trier ensuite
	strcpy(commande1, "chmod g+w fichierRes.txt");
	system(commande1);

	// Trier les résultats dans l'ordre décroissant et stocker dans un fichier
	strcpy(commande2, "sort -k2nr,2nr ./fichierRes.txt >> ./fichierRestrie.txt");
	system(commande2);

	// Suppression du fichier temporaire de résultats
	strcpy(commande3, "rm fichierRes.txt");
	system(commande3);
	fres = fopen("fichierRestrie.txt", "rt");
	if (fres != NULL)
	{
		while (fscanf(fres, "%d %d", &ID, &nombre_occurence) != EOF)
		{
			// stocker le resultat dans un tableau si le nombre d'occurence est plus grand que le seuil qu'on a pris dans le config
			tabResultat[l].id = ID;
			tabResultat[l].pourcentage = nombre_occurence;
			l++;
			
		}
	}
	else
	{
		*erreur = 7; // Erreur lors de l'ouverture du fichier
	}
	fclose(fres);
	*nbElTab = l;
	// supprimer le fichier avec les resultat trier
	strcpy(commande4, "rm fichierRestrie.txt");
	system(commande4);
	free(nb_occu);
	free(commande4);
	free(IDstring);
	free(chaine);
	free(commande3);
	free(commande2);
	free(commande1);
	free(commande);	
}