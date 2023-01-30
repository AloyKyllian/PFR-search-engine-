/**
 * Fait par Loic Maignan
 * 
 * Le 23/01/2023
 * 
*/
#include "Global.h"

void viderBuffer()
{
    int c;
    while ((c=getchar()) != EOF && c != '\n'); 
}
