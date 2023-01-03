#include "Pile.h"

//initialisation pile
PILE init_PILE()
{    return NULL;
}
PILE_audio init_PILE_audio()
{
    return NULL;
}
//affichage pile
void affichePILE(PILE pile)
{  
    int i;
    PILE temp= pile;
      if(PILE_estVide(pile)==1)
          {printf("VIDE\n\n");}
       else
       {
           printf("\nAffichage de la pile:\n");
           do
           {
               affiche_ELEMENT((*temp).element);
               temp= (*temp).suiv;
           }while(temp!=NULL);
       }
}
void affichePILE_audio(PILE_audio pile)
{  
    int i;
    PILE_audio temp= pile;
      if(pile==NULL)
          {printf("VIDE\n\n");}
       else
       {
           printf("\nAffichage de la pile:\n");
           do
           {
               affiche_ELEMENT_audio(temp->element);
               temp= temp->suiv;
           }while(temp!=NULL);
       }
}

void affichePILE_image(PILE_image pile)
{  
    int i;
    PILE_image temp= pile;
      if(pile==NULL)
          {printf("VIDE\n\n");}
       else
       {
           printf("\nAffichage de la pile:\n");
           do
           {
               affiche_ELEMENT_image(temp->element);
               temp= temp->suiv;
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
         temp->suiv=pile;
         return temp;
     }
    return pile;
}

//empiler pile
 PILE_audio emPILE_audio(PILE_audio pile, ELEMENT_audio element)
{
    PILE_audio temp=(PILE_audio)malloc(sizeof(Cellule_audio));
     if(temp!=NULL)
     {
         affect_ELEMENT_audio(&(temp->element), element);
         temp->suiv=pile;
         return temp;
     }
    return pile;
}

//depiler pile
PILE dePILE(PILE pile, ELEMENT *elementsupp)
{
    // si la pile n'est pas vide
    if(pile!=NULL)
    {
        //on garde lelement supprimé
        affect_ELEMENT(elementsupp, pile->element);
        // si on doit depiler une ou plusieurs cellules, on créé une nouvelle pile "aux" qui va pointer vers la cellule suivate de la pile et apres on doit free la pile
        PILE aux=pile;
        pile=pile->suiv;
        free(aux);
        return pile;
    }
    //si la pile était vide, on renvoie celle ci
    return pile;
}        

//depiler pile
PILE_audio dePILE_audio(PILE_audio pile, ELEMENT_audio *elementsupp)
{
    // si la pile n'est pas vide
    if(pile!=NULL)
    {
        //on garde lelement supprimé
        affect_ELEMENT_audio(elementsupp, pile->element);
        // si on doit depiler une ou plusieurs cellules, on créé une nouvelle pile "aux" qui va pointer vers la cellule suivate de la pile et apres on doit free la pile
        PILE_audio aux=pile->suiv;
        free(pile);
        return aux;
    }
    //si la pile était vide, on renvoie celle ci
    return pile;
}        
PILE_image emPILE_image(PILE_image pile, ELEMENT_image element)
{
    PILE_image temp=(PILE_image)malloc(sizeof(Cellule_image));
     if(temp!=NULL)
     {
          affect_ELEMENT_image(&(temp->element), element);
         temp->suiv=pile;
         return temp;
     }
    return pile;
};
PILE_image dePILE_image(PILE_image pile, ELEMENT_image *elementsupp)
{
        // si la pile n'est pas vide
    if(pile!=NULL)
    {
        //on garde lelement supprimé
        affect_ELEMENT_image(elementsupp, pile->element);
        // si on doit depiler une ou plusieurs cellules, on créé une nouvelle pile "aux" qui va pointer vers la cellule suivate de la pile et apres on doit free la pile
        PILE_image aux=pile->suiv;
        free(pile);
        return aux;
    }
    //si la pile était vide, on renvoie celle ci
    return pile;
};
    