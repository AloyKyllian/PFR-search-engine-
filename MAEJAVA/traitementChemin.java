package MAEJAVA;

public class traitementChemin
{
    public static void recupCheminPourAffichage(String type, String chemin)
    {
        
    }
}




/*recup_CheminPour_Affichage 
void recup_CheminPour_Affichage(char *type, char *chemin)
{
    char *extension = strrchr(chemin, '.');
    if (extension != NULL && strcmp(type, "rgb") == 0)
    {
        strcpy(extension, ".jpg");
    }
    if (extension != NULL && strcmp(type, "texte") == 0)
    {
        strcpy(extension, ".txt");
    }
    if (extension != NULL && strcmp(type, "nb") == 0)
    {
        strcpy(extension, ".bmp");
    }
    if (extension != NULL && strcmp(type, "audio") == 0)
    {
        strcpy(extension, ".wav");
    }
}

visualiser_fichier ??
FICHIER EXIST
int FichierExist(char chemin[100])
{   //Ouverture du fichier en mode lecture/écriture
    FILE * fichier = fopen(chemin, "r+");
 //Vérification de l'existence du fichier
	if (fichier == NULL)
	{
        return -1; //Retourner une valeur négative en cas d'erreur
	}
	else
	{
    	fclose(fichier);
        return 1;//Retourner une valeur positive en cas de succès
	}
}

VerifExtension
/*
//Fonction pour vérifier l'extension d'un fichier

int VerifExtension(char chemin[100],char extension[4]){
    char *i = strrchr(chemin, '.'); // recherche le dernier point dans le chemin
    if(i != NULL) {
        i++; // on passe le point
        //Comparaison de l'extension avec celle passée en paramètre
        if(strcmp(i, extension) == 0) {
            return 1;
        }
    }
    //Retourner une valeur négative en cas d'erreur
    return -1;
}



recherche image :
chemin=/chemin/fichier.txt
verifExtension(chemin,bmp)
// image deux extensions bmp jpg


*/