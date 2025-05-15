#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
//Constantes globales
#define MAX_ANIMAUX 50
#define TAILLE_CHAINE 100
//Definition de la structure animal
typedef struct {
    int id;
    char nom[TAILLE_CHAINE];
    char espece[TAILLE_CHAINE];
    int annee_naissance;
    float poids;
    char commentaire[TAILLE_CHAINE];
} Animal;

//Fonctions principales
void ajouter_animal(Animal[], int*);
void rechercher_animaux(const Animal[], int);
void adopter_animal(Animal[], int*);

//Variantes
void afficher_par_tranche_age(const Animal[], int);
void calculer_nettoyage_hebdomadaire(const Animal[], int);

//Outils
int lire_entier_securise();
float lire_flottant_securise();
void lire_chaine_securise(char*, int);
int annee_courante();
void afficher_menu();

#endif
