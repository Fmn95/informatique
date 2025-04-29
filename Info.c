#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANIMAUX 50
#define MAX_NOM 30
#define MAX_ESPECE 20
#define MAX_COMMENTAIRE 100

typedef struct {
    int id;
    char nom[MAX_NOM];
    char espece[MAX_ESPECE];
    int annee_naissance;
    float poids;
    char commentaire[MAX_COMMENTAIRE];
} Animal;

Animal chenil[MAX_ANIMAUX];
int nombre_animaux = 0;

void afficher_menu() {
    printf("\n--- Gestion du Chenil ---\n");
    printf("1. Ajouter un animal\n");
    printf("2. Rechercher un animal\n");
    printf("3. Supprimer un animal\n");
    printf("4. Afficher l'inventaire\n");
    printf("5. Quitter\n");
    printf("Choisissez une option: ");
}

void ajouter_animal() {
    if (nombre_animaux >= MAX_ANIMAUX) {
        printf("Le chenil est plein ! Impossible d'ajouter un nouvel animal.\n");
        return;
    }
    Animal a;
    a.id = nombre_animaux + 1;
    printf("Nom de l'animal: ");
    scanf("%s", a.nom);
    printf("Espèce: ");
    scanf("%s", a.espece);
    printf("Année de naissance: ");
    scanf("%d", &a.annee_naissance);
    printf("Poids (kg): ");
    scanf("%f", &a.poids);
    printf("Commentaire (facultatif): ");
    
    chenil[nombre_animaux++] = a;
    printf("Animal ajouté avec succès !\n");
}

void rechercher_animal() {
    char nom[MAX_NOM];
    printf("Entrez le nom de l'animal à rechercher: ");
    scanf("%s", nom);
    for (int i = 0; i < nombre_animaux; i++) {
        if (strcmp(chenil[i].nom, nom) == 0) {
            printf("ID: %d, Nom: %s, Espèce: %s, Année: %d, Poids: %.2f kg, Commentaire: %s\n",
                   chenil[i].id, chenil[i].nom, chenil[i].espece, chenil[i].annee_naissance,
                   chenil[i].poids, chenil[i].commentaire);
            return;
        }
    }
    printf("Animal non trouvé.\n");
}

void supprimer_animal() {
    int id;
    printf("Entrez l'ID de l'animal à supprimer: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < nombre_animaux; i++) {
        if (chenil[i].id == id) {
            found = 1;
            for (int j = i; j < nombre_animaux - 1; j++) {
                chenil[j] = chenil[j + 1];
            }
            nombre_animaux--;
            printf("Animal supprimé avec succès !\n");
            break;
        }
    }
    if (!found) {
        printf("Aucun animal avec cet ID.\n");
    }
}

void afficher_inventaire() {
    if (nombre_animaux == 0) {
        printf("Le chenil est vide.\n");
        return;
    }
    printf("\nInventaire du chenil:\n");
    for (int i = 0; i < nombre_animaux; i++) {
        printf("ID: %d, Nom: %s, Espèce: %s, Année: %d, Poids: %.2f kg, Commentaire: %s\n",
               chenil[i].id, chenil[i].nom, chenil[i].espece, chenil[i].annee_naissance,
               chenil[i].poids, chenil[i].commentaire);
    }
}

int main() {
    int choix;
    do {
        afficher_menu();
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouter_animal();
                break;
            case 2:
                rechercher_animal();
                break;
            case 3:
                supprimer_animal();
                break;
            case 4:
                afficher_inventaire();
                break;
            case 5:
                printf("Fermeture du programme.\n");
                break;
            default:
                printf("Option invalide, veuillez réessayer.\n");
        }
    } while (choix != 5);
    return 0;
}
