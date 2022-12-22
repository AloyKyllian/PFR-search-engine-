#include "../head/Comparaison-image.h"

void Comparaison_image(DESCRIPTEUR_IMAGE Nv_Des, DESCRIPTEUR_IMAGE Ac_Des, int* Similariter)
{
    int cptligne;

    if(Nv_Des.Nb_Ligne < Ac_Des.Nb_Ligne)
    {
        for( cptligne = 0; cptligne < Nv_Des.Nb_Ligne;cptligne++)
        {
            if(Nv_Des.Bilan[cptligne][1] == Ac_Des.Bilan[cptligne][1])
            {
                *Similariter++;
            }
        }
    }
    else
    {
        for(cptligne = 0; cptligne < Ac_Des.Nb_Ligne;cptligne++)
        {
            if(Nv_Des.Bilan[cptligne][1] == Ac_Des.Bilan[cptligne][1])
            {
                *Similariter++;
            }
        }
    }
    *Similariter = *Similariter/cptligne*100;
}