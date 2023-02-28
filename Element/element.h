/**
 * Fait par Yassmine Allal
 * 
 * Le 23/01/2023
 * 
*/
#ifndef element_h
#define element_h

#include <string.h>
#include "../descripteur_audio/descripteur_audio.h"
#include "../descripteur_image/Descripteur_image.h"
#include "../descripteur_texte/descripteur_texte.h"
#include "../Gestion-Config/Global.h"


typedef struct 
{
    int id;
    String CHEMIN;
}ELEMENT;

typedef struct 
{
    descri_audio descripteur;
    int id;
}ELEMENT_audio;

typedef struct 
{
    DESCRIPTEUR_IMAGE descripteur_image;
    int id;
}ELEMENT_image;

typedef struct 
{
    DESCRIPTEUR_TEXTE descripteur_texte;
    int id;
}ELEMENT_texte;

void affect_ELEMENT_image(ELEMENT_image *elemaffect, ELEMENT_image e2);
void affiche_ELEMENT_image(ELEMENT_image element);

void affiche_ELEMENT(ELEMENT element);
void affect_ELEMENT(ELEMENT *elemaffect, ELEMENT e2);

void affect_ELEMENT_audio(ELEMENT_audio *elemaffect, ELEMENT_audio e2);
void affiche_ELEMENT_audio(ELEMENT_audio element);

void affect_ELEMENT_texte(ELEMENT_texte *elemaffect, ELEMENT_texte e2);
//void affiche_ELEMENT_audio(ELEMENT_audio element);
#endif