#include "includes.h" //Fichier des bibliotheques

int main() {
    Animal chenil[MAX_ANIMAUX]; //Tableau contenant animaux du refuge
    int nb_animaux = 0;   //Nombre actuel animaux

    while (1) {
        afficher_menu();
        int choix = lire_entier_securise(); //Lecture securisee
        switch (choix) {
            case 1:
                ajouter_animal(chenil, &nb_animaux);
                break;
            case 2:
                rechercher_animaux(chenil, nb_animaux);
                break;
            case 3:
                adopter_animal(chenil, &nb_animaux);
                break;
            case 4:
                afficher_par_tranche_age(chenil, nb_animaux);
                break;
            case 5:
                calculer_nettoyage_hebdomadaire(chenil, nb_animaux);
                break;
            case 0:
                printf("Au revoir !\n");
                return 0;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}
//Affichage du menu principal
void afficher_menu() {
    printf("\n🐾 --- Menu Chenil ---\n");
    printf("1. 🆕🐕 Ajouter un animal\n");
    printf("2. 🔍 Rechercher un animal\n");
    printf("3. 🏠 Adopter un animal\n");
    printf("4. 📊 Inventaire par tranche d’âge (INV_AGE_ASC)\n");
    printf("5. 🧹 Charge de nettoyage (DAY_CLEAN)\n");
    printf("0. 🚪 Quitter\n");
    printf("🎯 Votre choix : ");
}
