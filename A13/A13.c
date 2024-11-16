#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// A13

// a) als Kommentare und b) als Funktionen
// b) sehr ausführlich ausgedrückt bzw. verbos um Bedingungen auf Korrektheit zu kontrollieren
// "l" wurde hierbei als Kontrolle verwendet -> wenn "l" returned wird ist irgendwas ganz falsch gelaufen

// keine Ahnung ob die richtig sind oder nicht bin selber verwirrt

// PAP 13-1
// nach B wenn: x == 0 v y == 0 v z == 0
// nach C wenn: !(x == 0 v y == 0 v z == 0)

char pap_13_1(int x, int y, int z) {

    if(x == 0 || y == 0 || z == 0) {
        return 'B';
    } else if (!(x == 0 || y == 0 || z == 0)) {
        return 'C';
    } else {
        return 'l';
    }
}

// PAP 13-2
// nach B wenn: (r > 0 ^ r == f) v r == w
// nach C wenn: !(r > 0) v !(r == f ^ r == w)
char pap_13_2(int r) {

    // nur Beispielwerte kann beliebig geändert werden
    int f = 10;
    int w = 50;

    if((r > 0 && r == f) || r == w) {
        return 'B';
    } else if(!(r > 0) || !(r == f && r == w)) {
        return 'C';
    } else {
        return 'l';
    }
    
}

// PAP 13-3
// nach B wenn: (x > 0 ^ y > 0) v (x < 0 ^ y < 0)
// nach C wenn: !(x > 0 ^ y > 0) v !(x < 0 ^ y < 0)
char pap_13_3(int x, int y) {

    if((x > 0 && y > 0) || (x < 0 && y < 0)) {
        return 'B';
    } else if(!(x > 0 && y > 0) || !(x < 0 && y < 0)) {
        return 'C';
    } else {
        return 'l';
    }
}

// PAP 13-4
// nach B wenn: (x > 0 ^ x > y)
// nach C wenn: (x > 0 ^ !(x > y)) v !(x > 0) ^ x < y 
// nach D wenn: !(x > 0 ^ x < y)
char pap_13_4(int x, int y) {

    if(x > 0 && x > y) {
        return 'B';
    } else if((x > 0 && !(x > y)) || !(x > 0) && x < y) {
        return 'C';
    } else if(!(x > 0 && x < y)) {
        return 'D';
    } else {
        return 'l';
    }
    
}


int main() {

    int pap;
    int rc;

    // welches PAP
    // kann mit switch cases ignoriert werden
    // nur zum auswählen der PAP -> alle PAPs könnten auch in eigenes Program
    printf("(1) PAP 13-1\n");
    printf("(2) PAP 13-2\n");
    printf("(3) PAP 13-3\n");
    printf("(4) PAP 13-4\n");
    printf("---> Welches PAP soll ausgeführt werden: ");
    rc = scanf("%d", &pap);

    // Ziel wo wir ankommen
    char ergebnis;


    // hätte ordentlicher geschrieben werden können -> ganze Ausführung von einem PAP in einer Funktion
    switch (pap) {
    case 1:
        // PAP 13-1
        int x1, y1, z1;
        printf("### PAP 13-1 ###\n\n");
        printf("x: ");
        rc = scanf("%d", &x1);

        printf("y: ");
        rc = scanf("%d", &y1);

        printf("z: ");
        rc = scanf("%d", &z1);

        ergebnis = pap_13_1(x1, y1, z1);

        break;
    case 2:

        // PAP 13-2
        int r;
        printf("### PAP 13-2 ###\n\n");
        printf("r: ");
        rc = scanf("%d", &r);

        ergebnis = pap_13_2(r);

        break;
    case 3:
        // PAP 13-3
        int x3, y3;
        printf("### PAP 13-3 ###\n\n");
        printf("x: ");
        rc = scanf("%d", &x3);

        printf("y: ");
        rc = scanf("%d", &y3);

        ergebnis = pap_13_3(x3, y3);

        break;
    case 4:
        // PAP 13-4
        int x4, y4;
        printf("### PAP 13-4 ###\n\n");
        printf("x: ");
        rc = scanf("%d", &x4);

        printf("y: ");
        rc = scanf("%d", &y4);

        ergebnis = pap_13_4(x4, y4);

        break;
    default:
        printf("ungültige Option ausgewählt: %d\n", pap);
        printf("!!! ABBRUCH !!!\n\n");

        // aus main() Funtkion raus
        return 1;
    }

    printf("Angekommen bei: %c\n", ergebnis);

    printf("\nFERTSCH\n");

    return 0;
}