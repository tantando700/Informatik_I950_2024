#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// A12
// kein bool Datentyp in C
// bool geht auch mit if(n): 
// n == 0 ist FALSE und n != 0 ist TRUE
// bsp: if(0){} => Bedingung in if(Bedingung) ist 0 deswegen FALSE
// if(1){} oder if(26) oder if(-203) => Bedingung in if(Bedingung) ist ungleich 0 deswegen TRUE
// einfach gesagt 0 ist FALSE und alles andere TRUE

// 2. Option "#include <stdbool.h>" um bool Datentyp in C zu nutzen
// bool <variable_name> = true oder bool <variable_name> = false

int unter_16(int alter) {

    int eval = 0;

    if(alter < 16) {
        eval = 1;
    }

    return eval;
}

int ist_rentner(int alter) {

    int eval = 0;

    if(alter >= 67) {
        eval = 1;
    } 

    return eval;
}

int ist_student(int alter) {

    int eval = 0;

    if(alter >= 21 && alter <= 25) {
        eval = 1;
    }

    return eval;
}

int main() {

    int alter, r, s;

    // b)
    // "||" ist logischer OR
    // Aussagenlogischer Ausdruck für Vollzahler
    // (alter > 16 || r == 0 || s == 0)

    // Aussagenlogischer Ausdruck für Ermäßigte
    // (alter < 16 || r != 0 || s != 0) 

    // c)

    // Array mit Testwerten
    int testwerte[] = {10, 13, 16, 19, 22, 25, 65, 75};

    // Ausdruck: (sizeof(testwerte) / sizeof(int)) gibt Anzahl an Array Elemente zurück -> hier 8
    // auch möglich "i < 8" wenn die Anzahl an Elementen bekannt ist
    for(int i = 0; i < (sizeof(testwerte) / sizeof(int)); i++) {
        
        int person_alter = testwerte[i];

        alter = unter_16(person_alter);
        r = ist_rentner(person_alter);
        s = ist_student(person_alter);

        printf("Person %d ist %d:\n", i + 1, person_alter);

        // hier 3 Bedingungen verkettet mit logischem OR ("||") 
        // wenn eine der Bedingungen TRUE dann geht Programm in if(){} rein
        if(alter != 0 || r != 0 || s != 0) {

            if(alter != 0) {
                printf("-- Person ist unter 16 --\n");
            } else if (r != 0) {
                printf("-- Person ist Rentner --\n");
            } else if (s != 0) {
                printf("-- Person ist Student --\n");
            }

            printf("--> Ermäßigt\n");
        } else {
            printf("--> NICHT Ermäßigt\n");
        }

        printf("\n\n");
    }

    return 0;
}