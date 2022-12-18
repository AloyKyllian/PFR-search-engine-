#include "../head/Pile.h"

//initialisation pile
PILE init_PILE()
{    return NULL;
}
//affichage pile
void affichePILE(PILE pile)
{  
    int i;
    PILE temp= pile;
      if(PILE_estVide(pile)==1)
          {printf("\n---\n---\n");}
       else
       {
           printf("\nAffichage de la pile:\n");
           do
           {
               printf("\n---\n");
               affiche_ELEMENT((*temp).element);
               temp= (*temp).suiv;
               printf(" \n---\n");
           }while(temp!=NULL);
       }
}
//tester si pile vide
int PILE_estVide(PILE pile)
{  if (pile==NULL) return 1;
   return 0;
}


//empiler pile
 PILE emPILE(PILE pile, ELEMENT element)
{
    PILE temp=(PILE)malloc(sizeof(Cellule));
     if(temp!=NULL)
     {
          affect_ELEMENT(&(temp->element), element);
         (*temp).suiv=pile;
         return temp;
     }
    return pile;
}

//depiler pile
PILE dePILE(PILE pile, ELEMENT *elementsupp)
{
    // si la pile n'est pas vide
    if(PILE_estVide(pile)==0)
    {
        //on garde lelement supprimé
        affect_ELEMENT(elementsupp, pile->element);
        // si on doit depiler une ou plusieurs cellules, on créé une nouvelle pile "aux" qui va pointer vers la cellule suivate de la pile et apres on doit free la pile
        PILE aux=pile->suiv;
        free(pile);
        return aux;
    }
    //si la pile était vide, on renvoie celle ci
    return pile;
}        
    