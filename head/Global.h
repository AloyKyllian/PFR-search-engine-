#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_UTILISATEUR 5
#define MAX_CHAINE 100

typedef struct
{
    char chaine[MAX_CHAINE];
}String;

void viderBuffer();

#endif