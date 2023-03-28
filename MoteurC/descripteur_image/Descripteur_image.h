/**
 * Fait par Loic Maignan
 * 
 * Le 23/01/2023
 * 
*/
#ifndef DESCRIPTEUR_IMAGE_H
#define DESCRIPTEUR_IMAGE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
Exemple pour cree un descripteur :

    DESCRIPTEUR_IMAGE descripteur_image;
    int Erreur;
    descripteur_image = Pack_Descripteur_image(&Erreur,Path,Nb_Bit_Fort);
    if(Erreur!=0)
    {
        // Afficer Erreur
    }
*/

typedef struct
{
    int Nb_Ligne;
    int Nb_Colonne;
    int Nb_composante;
    int **adr_Matrice;
} IMAGE;

typedef struct
{
    int Nb_Ligne;
    int Nb_Colonne;
    int **Bilan;
} DESCRIPTEUR_IMAGE;


/**
 * @brief
 * Cette fonction lit une image à partir d'un fichier. 
 * Elle prend en entrée un pointeur vers un entier (Erreur) pour stocker le code d'erreur, et un tableau de caractères (Path) contenant le chemin d'accès au fichier. 
 * Elle retourne une structure IMAGE qui contient le nombre de lignes, de colonnes, et de composantes de la matrice image. La fonction utilise fopen pour ouvrir le fichier, et fscanf pour lire les informations sur l'image. 
 * Si l'ouverture du fichier réussit, la fonction alloue de la mémoire pour la matrice d'image en utilisant malloc, et copie les données de l'image dans la matrice en utilisant fscanf. 
 * Si une erreur se produit, le code d'erreur est stocké dans la variable Erreur.
 * 
 * @param Path
 * @param Erreur
 * @return IMAGE
 */
IMAGE Lire_image(int *Erreur, char Path[]);

/**
 * @brief
 * Cette fonction traite une image en utilisant une certaine quantité de bits (Nb_Bit_Fort) pour chaque composante couleur (rouge, vert et bleu). 
 * Elle alloue de la mémoire pour une nouvelle matrice de pixels et la remplit avec les pixels traités, puis libère l'espace mémoire utilisé par la matrice d'image d'origine. 
 * Enfin, elle affecte la nouvelle matrice traitée à la structure d'image. 
 * La fonction renvoie la structure d'image modifiée et modifie une variable d'erreur en cas d'échec d'allocation de mémoire pour la nouvelle matrice.
 * 
 * @param Path
 * @param Erreur
 * @return IMAGE
 */
IMAGE Pre_traitement(int *Erreur, IMAGE img, int Nb_Bit_Fort);

/**
 * @brief
 * Cette fonction crée un descripteur d'image en allouant de la mémoire pour un tableau 2D, puis remplit ce tableau en comptant le nombre de valeurs dans la matrice d'image d'entrée. 
 * La fonction retourne le descripteur créé et un indicateur d'erreur. 
 * Les entrées sont un pointeur vers un entier pour l'indicateur d'erreur, l'image d'entrée et le nombre de bits forts pour la conversion en nombre entier.
 * 
 * @param Erreur
 * @param img
 * @param Nb_Bit_Fort
 * @return DESCRIPTEUR_IMAGE
 */
DESCRIPTEUR_IMAGE Creation_Discripteur(int *Erreur, IMAGE img, int Nb_Bit_Fort);

/**
 * @brief
 * La fonction lit une image en appelant la fonction "Lire_image", puis vérifie si tout est ok. 
 * Si tout est ok, elle effectue le prétraitement de l'image en appelant la fonction "Pre_traitement" et vérifie encore si tout est ok. 
 * Si tout est toujours ok, la fonction crée un descripteur d'image en appelant la fonction "Creation_Discripteur".
 * Enfin, la fonction retourne le descripteur d'image créé.
 * 
 * @param Erreur
 * @param Path
 * @param Nb_Bit_Fort
 * @return DESCRIPTEUR_IMAGE
 */
DESCRIPTEUR_IMAGE Pack_Descripteur_image(int *Erreur, char Path[],int Nb_Bits_Fort);

#endif