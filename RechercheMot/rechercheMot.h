#ifndef RECHERCHEMOT_H
#define RECHERCHEMOT_H
#include "../Gestion-Config/Global.h"

typedef struct{
    int id;
    int nb_occurence;
}tab_Res;
void rechercheMot(char*,char*,tab_Res*,int,int*, int*);
#endif