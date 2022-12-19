#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int FichierExist(char chemin[100])
{   FILE * fichier = fopen(chemin, "r+");
 
	if (fichier == NULL)
	{
    	
        return -1;

	}
	else
	{
    	printf("Le fichier existe et on le referme aussitôt");
    	fclose(fichier);
        return 1;
	}
}

int VerifExtension(char chemin[100],char extension[4]){
    extension=strstr(chemin,"xml");
            if (extension==NULL)
                return -1;
            else
                 return 1;
}