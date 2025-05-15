#include "includes.h"
//Calcule l annee actuelle
int annee_courante() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return tm.tm_year + 1900;
}
