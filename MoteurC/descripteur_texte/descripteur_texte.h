/**
 * Fait par Hugo Lestrade
 * 
 * Le 23/01/2023
 * 
*/
#ifndef DESCRIPTEUR_TEXTE_H
#define DESCRIPTEUR_TEXTE_H

#include <stdint.h>
#include <stdbool.h>
#include "../Gestion-Config/Global.h"
#include <string.h>
#include <ctype.h>

typedef struct 
{
String *tab_mot;
int *tab_app;
int index;
}DESCRIPTEUR_TEXTE;


/**
 * @brief
 *
 * Auteur : Hugo Lestrade
 * Cette fonction récupère un mot en paramètre d'entrée.
 * Elle commence par transformer toutes les lettres majuscules en minuscules.
 * Puis en fonction de ceux qu'il faut nettoyer dans le mot ( une balise, une ponctuation ou tout caractère empéchant la lecture du mot)
 * Elle entre dans une condition différente pour chaque élément à nettoyer.
 * Enfin elle retourne le mot propre.
 *
 * @param mot_lu[100]
 * @return char*
 */
char *nettoyage(char mot_lu[100]);

/**
 * @brief
 *
 * Auteur : Hugo Lestrade
 * Cette fonction récupère le mot que retourne la fonction nettoyage.
 * Elle ouvre ensuite un fichier qui contient tous les mots bannis qu'on ne souhaite pas garder comme les mots de liaisons "le , la ..."
 * Elle remplit un tableau avec ces différents mots.
 * Puis elle cherche si le mot en entrée est présent dans le tableau des mots bannis grâce à la fonction strcmp
 * Si c'est le cas elle renvoie un boolean à False pour indiquer qu'il ne faut pas garder ce mot
 *
 * @param mot
 * @return bool
 */
bool filtrage(char* mot);

/**
 * @brief
 *
 * Auteur : Hugo Lestrade
 * Cette fonction récupère le nombre de mot du texte, le mot que retourne la fonction "nettoyage" et un tableau fait d'une structure déclarer précédemment.
 * Cette fonction à pour but de répertorier tous les mots du texte avec leur nombre d'apparition.
 * Dans un premier temps elle vérifie si le mot est déjà présent dans le tableau.
 * Si ce n'est pas le cas on l'ajoute et on initialise son compteur à 1
 * Si c'est le cas on incrémente son compteur associé de 1
 * Pour finir la fonction renvoie le tableau complet
 *
 * @param nbr_mot
 * @param mot
 * @param tab
 * @return DESCRIPTEUR_TEXTE
 */
DESCRIPTEUR_TEXTE descripteur_texte( int nbr_mot, char* mot,DESCRIPTEUR_TEXTE tab);

/**
 * @brief
 *
 * Auteur : Hugo Lestrade
 * Cette fonction récupère le nombre de mot-clé souhaité par l'utilisateur dans le fichier config 
 * Elle récupère le tableau retourné par la fonction "descripteur_texte" et un tableau avec un taille équivalente au nombre de mot-clé et du même type que le tableau de "descripteur_texte".
 * Cette fonction sert à récupérer les mots les plus cités dans le tableau de "descripteur_texte", le nombre de mots dépendant du nombre de mot-clés souhaité
 * Elle regarde donc quel mot est le plus cité grâce à son compteur et l'ajoute dans le tableau.
 * Puis le compteur de chaque mot incorporé est mis à 0 pour éviter qu'il ne perturbe la fonction.
 * 
 * @param nbr_occ
 * @param tab
 * @param tab_occ_finale
 * @return DESCRIPTEUR_TEXTE
 */
DESCRIPTEUR_TEXTE tab_occ(int nbr_occ,DESCRIPTEUR_TEXTE tab,DESCRIPTEUR_TEXTE tab_occ_finale);

/**
 * @brief
 *
 * Auteur : Hugo Lestrade
 * Cette fonction récupère le chemin du fichier texte à ouvrir, le nombre de mot-clé souhaité par l'utilisateur dans le fichier config et le tableau renvoyer
 * Mais également le tableau qui copiera le tableau retourné par la fonction "tab_occ".
 * Cette fonction sert à organiser toutes les fonctions cités au-dessus.
 * Elle va donc ouvrir les fichiers nécessaires, allouer les espaces mémoires pour les tableaux et déclarer puis configurer les divers paramètrees d'entrées des autres fonctions.
 * Elle va ensuite les appeler dans le bon ordre et les associer entre elles.
 * 
 * @param chemin_fichier
 * @param nbr_occ
 * @param tab_renvoyer
 * @return DESCRIPTEUR_TEXTE
 */
DESCRIPTEUR_TEXTE descripteur_texte_finale(char* chemin_fichier,int nbr_occ,DESCRIPTEUR_TEXTE tab_renvoyer);





#endif