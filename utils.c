#include "includes.h"
//Lecture d un entier securisee
int lire_entier_securise() {
    char buffer[64], *endptr;
    int val;
    while (1) {
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Erreur de lecture. Réessayez : ");
            continue;
        }
        val = (int)strtol(buffer, &endptr, 10);
        if (endptr == buffer || *endptr != '\n') {
            printf("❌ Entrée invalide. Entrez un entier : ");
            continue;
        }
        return val;
    }
}
//Lecture d un flottant securisee
float lire_flottant_securise() {
    char buffer[64], *endptr;
    float val;
    while (1) {
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Erreur de lecture. Réessayez : ");
            continue;
        }
        val = strtof(buffer, &endptr);
        if (endptr == buffer || *endptr != '\n') {
            printf("❌ Entrée invalide. Entrez un nombre réel : ");
            continue;
        }
        return val;
    }
}
//Lecture d une chaine securisee
void lire_chaine_securise(char *buffer, int taille) {
    if (fgets(buffer, taille, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
        else
            while (getchar() != '\n');
    }
}
