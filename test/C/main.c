#include <stdio.h>
#include "JNA.h"

int main()
{

  int JNA=0,cpt=0;
    do
    {
        JNA=getMain();
        if (JNA == 1)
        {
            cpt++;
            
            printf("JNA :%i",JNA);
            printf("cpt :%i",cpt);
            passerLaMain();
        }

    } while (1);

}