#include "includes.h"
//Supprimer animal du refuge par son id
void adopter_animal(Animal animaux[], int *nb) {
    printf("ID de l’animal à adopter : ");
    int id = lire_entier_securise();
    for (int i = 0; i < *nb; i++) {
        if (animaux[i].id == id) {
            //Décale l id de chaque animal restant
            for (int j = i; j < *nb - 1; j++) {
                animaux[j] = animaux[j + 1];
            }
            (*nb)--;
            printf("✅ Animal adopté et retiré du refuge.\n");
            return;
        }
    }
    printf("❌ Aucun animal trouvé avec cet ID.\n");
}
