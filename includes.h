#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ANIMAUX 50
#define TAILLE_CHAINE 100

typedef struct {
    int id;
    char nom[TAILLE_CHAINE];
    char espece[TAILLE_CHAINE];
    int annee_naissance;
    float poids;
    char commentaire[TAILLE_CHAINE];
} Animal;

// Fonctions principales
void ajouter_animal(Animal[], int*);
void rechercher_animaux(const Animal[], int);
void adopter_animal(Animal[], int*);

// Variantes
void afficher_par_tranche_age(const Animal[], int);
void calculer_nettoyage_hebdomadaire(const Animal[], int);

// Utilitaires
int lire_entier_securise();
float lire_flottant_securise();
void lire_chaine_securise(char*, int);
int get_current_year();
void afficher_menu();

#endif
