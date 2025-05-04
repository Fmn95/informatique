#include "includes.h"

int generer_id_unique(const Animal animaux[], int nb) {
    int max = 0;
    for (int i = 0; i < nb; i++) {
        if (animaux[i].id > max) max = animaux[i].id;
    }
    return max + 1;
}

void ajouter_animal(Animal animaux[], int *nb) {
    if (*nb >= MAX_ANIMAUX) {
        printf("⚠️  Le refuge est plein !\n");
        return;
    }

    Animal a;
    a.id = generer_id_unique(animaux, *nb);
    printf("Nom : ");
    lire_chaine_securise(a.nom, TAILLE_CHAINE);
    printf("Espèce (chien, chat, hamster, autruche) : ");
    lire_chaine_securise(a.espece, TAILLE_CHAINE);
    printf("Année de naissance : ");
    a.annee_naissance = lire_entier_securise();
    printf("Poids (kg) : ");
    a.poids = lire_flottant_securise();
    printf("Commentaire (facultatif) : ");
    lire_chaine_securise(a.commentaire, TAILLE_CHAINE);

    animaux[*nb] = a;
    (*nb)++;
    printf("Animal ajouté avec succès.\n");
}
