#ifndef DESCRIPTEUR_TEXTE_H
#define DESCRIPTEUR_TEXTE_H

#include <stdint.h>
#include <stdio.h>
#include "../head/Global.h"
#include <string.h>
#include <ctype.h>

typedef struct 
{
    String *tab_mot;
    int *tab_app;
    int index;
}tab_total;

int comptemot(char* mot_lu);


#endif