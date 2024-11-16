#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// A14

int ist_schaltjahr(int jahr) {
    
    // Schaltjahr Check Algorithmus
    if(jahr % 4 == 0 && !(jahr % 100 == 0) || jahr % 400 == 0) {
        // printf("%d ist ein Schaltjahr\n", jahr);
        return 1;
    }

    return 0;
}

void zeitspanne_schaltjahr(int jahr1, int jahr2) {
    
    int start, ende, ergebnis;

    // festlegung start und end Werte für for-Loop
    if(jahr1 > jahr2) {
        start = jahr2;
        ende = jahr1;
    } else {
        start = jahr1;
        ende = jahr2;
    }

    printf("Schaltjahre zwischen %d-%d:\n", start, ende);
    for(int i = start; i < ende; i++) {
        ergebnis = ist_schaltjahr(i);

        if(ergebnis == 1) {
            printf("%d\n", i);
        }
    }

    printf("\nFertig\n");

}

int main() {

    int auswahl, rc;

    printf("(1) Check ob Schaltjahr\n");
    printf("(2) Schaltjahre in Zeitspanne\n");

    printf("Auswahl: ");
    rc = scanf("%d", &auswahl);

    switch(auswahl) {
        case 1:
            int eingabe_jahr, rc1, ergebnis;
            printf("Prüfe ob Jahr Schaltjahr: ");
            rc1 = scanf("%d", &eingabe_jahr);

            ergebnis = ist_schaltjahr(eingabe_jahr);

            if (ergebnis == 1) {
                printf("%d ist ein Schaltjahr\n", eingabe_jahr);
            } else {
                printf("%d ist KEIN Schaltjahr\n", eingabe_jahr);
            }

            break;
        case 2:
            int start, ende, rc2;
            printf("### Schaltjahre in Zeitspanne ###\n\n");
            printf("Jahr 1: ");
            rc2 = scanf("%d", &start);

            printf("Jahr 2: ");
            rc2 = scanf("%d", &ende);

            zeitspanne_schaltjahr(start, ende);

            break;
        default:
            printf("Ungültige Auswahl [%d]\n", auswahl);
            printf("ABBRUCH!!!\n\n");
            return 1;
    }


    return 0;
}