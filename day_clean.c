#include "includes.h"
//Calcul du temps de nettoyage hebdomadaire
void calculer_nettoyage_hebdomadaire(const Animal animaux[], int nb) {
    int total = 0;

    for (int i = 0; i < nb; i++) {
        int quotidien = 0, hebdo = 0;

        if (strcmp(animaux[i].espece, "hamster") == 0 ||
            strcmp(animaux[i].espece, "chat") == 0) {
            quotidien = 10;
            hebdo = 20;
        } else if (strcmp(animaux[i].espece, "autruche") == 0) {
            quotidien = 20;
            hebdo = 45;
        } else if (strcmp(animaux[i].espece, "chien") == 0) {
            quotidien = 5;
            hebdo = 20;
        } else {
            quotidien = 2; //Cage vide ou espce inconnue
        }

        total += quotidien * 7 + hebdo;
    }

    printf("⏱️ Temps de nettoyage hebdomadaire : %d minutes (%dh %dm)\n",
           total, total / 60, total % 60);
}
