#include "../Global/Global.h"

void viderBuffer()
{
    int c;
    while ((c=getchar()) != EOF && c != '\n'); 
}
