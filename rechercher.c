#include "includes.h"
//Recherche selon criteres
void rechercher_animaux(const Animal animaux[], int nb) {
    char nom[TAILLE_CHAINE] = "", espece[TAILLE_CHAINE] = "";
    int age_type;

    printf("Nom (laisser vide pour ignorer) : ");
    lire_chaine_securise(nom, TAILLE_CHAINE);   //Securise
    printf("Espèce (laisser vide pour ignorer) : ");
    lire_chaine_securise(espece, TAILLE_CHAINE);  //Securise
    printf("Type d’âge (0=ignorer, 1=jeune <2 ans, 2=sénior >10 ans) : ");
    age_type = lire_entier_securise();
//Calcul de l annee courante
    int trouve = 0;
    int annee_courante = get_current_year();

    for (int i = 0; i < nb; i++) {
        int age = annee_courante - animaux[i].annee_naissance;
        int correspond = 1;

        if (strlen(nom) > 0 && strstr(animaux[i].nom, nom) == NULL)
            correspond = 0;
        if (strlen(espece) > 0 && strcmp(animaux[i].espece, espece) != 0)
            correspond = 0;
        if ((age_type == 1 && age >= 2) || (age_type == 2 && age <= 10))
            correspond = 0;

        if (correspond) {
            printf("→ [%d] %s (%s), %d kg, né en %d\n", animaux[i].id,
                   animaux[i].nom, animaux[i].espece,
                   (int)animaux[i].poids, animaux[i].annee_naissance);
            if (strlen(animaux[i].commentaire) > 0)
                printf("   Commentaire : %s\n", animaux[i].commentaire);
            trouve = 1;
        }
    }
//Cas de non trouvaille
    if (!trouve) {
        printf("Aucun animal trouvé avec ces critères.\n");
    }
}
