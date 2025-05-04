#include "includes.h"

void afficher_par_tranche_age(const Animal animaux[], int nb) {
    if (nb == 0) {
        printf("Aucun animal à analyser.\n");
        return;
    }

    int current = get_current_year();
    int ages[MAX_ANIMAUX];

    for (int i = 0; i < nb; i++)
        ages[i] = current - animaux[i].annee_naissance;

    // Tri par sélection
    for (int i = 0; i < nb - 1; i++) {
        for (int j = i + 1; j < nb; j++) {
            if (ages[i] > ages[j]) {
                int temp = ages[i];
                ages[i] = ages[j];
                ages[j] = temp;
            }
        }
    }

    int q1 = ages[nb / 4];
    int q2 = ages[nb / 2];
    int q3 = ages[(3 * nb) / 4];

    int t1 = 0, t2 = 0, t3 = 0, t4 = 0;

    for (int i = 0; i < nb; i++) {
        int age = current - animaux[i].annee_naissance;
        if (age <= q1) t1++;
        else if (age <= q2) t2++;
        else if (age <= q3) t3++;
        else t4++;
    }

    printf("\nTotal animaux : %d\n", nb);
    printf("Quartile 1 (<= %d ans) : %d animaux\n", q1, t1);
    printf("Quartile 2 (<= %d ans) : %d animaux\n", q2, t2);
    printf("Quartile 3 (<= %d ans) : %d animaux\n", q3, t3);
    printf("Quartile 4 (> %d ans)  : %d animaux\n", q3, t4);
}
