#include "rechercheMot.h"

void rechercheMot(char *mot, char *chemin, tab_similaire *tabResultat, int nb_mot, int *nbElTab, int *erreur)
{
	FILE *fp;
	FILE *fres;
	system("touch fichierRes.txt");
	system("touch fichierRestrie.txt");
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
	fp = fopen(chemin, "rt");
	if (fp != NULL)
	{
		while (fscanf(fp, "%s", chaine) != EOF && atoi(chaine) < 0)
		{

			strcpy(IDstring, chaine);

			for (int i = 0; i < nb_mot; i++)
			{
				fscanf(fp, "%s    |    %s", chaine, nb_occu);
				if (strcmp(chaine, mot) == 0)
				{
					// printf("chaine= %s son nombre d'occurence : %s et ID=%s\n", chaine, nb_occu, IDstring);
					// stocker les donnee dans un fichier pour les trier avec la commande sort de linux
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
		*erreur = 7;
	}
	fclose(fp);

	// donner le droit d'ecriture dans le fichier resultat afin de trier ensuite
	strcpy(commande1, "chmod g+w fichierRes.txt");
	system(commande1);

	// trier dans l'ordre decroissant  et les stocker dans un fichier
	strcpy(commande2, "sort -k2nr,2nr ./fichierRes.txt >> ./fichierRestrie.txt");
	system(commande2);

	// supprimer le fichier avec les resultat de la recherche dans la base des descripteur
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
		*erreur = 7;
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