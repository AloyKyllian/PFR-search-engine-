#include<stdint.h>
#include <stdio.h>
#include "../LireResultatRecherche/LireResultat.h"

int main(){
    tabRes *tabResultat=malloc(100*sizeof(tabRes));
    String type="texte";
    tabResultat[0].id=-6;
	tabResultat[0].pourcentage=35;
    tabResultat[1].id=-9;
	tabResultat[1].pourcentage=30;
    tabResultat[2].id=-10;
	tabResultat[2].pourcentage=20;
    LireResultat(tabResultat,3,type);
return 0;
}