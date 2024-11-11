#include <stdio.h>
#include <math.h>

// A11

// Funktion
// rekursive Funktionen sind Funktionen welche sich selber aufrufen
// expo ruft sich in Fall 2 und 3 selber auf
int expo(int n) {

    // Fall 1: n == 0
    if(n == 0) {
        return 1;
    } 
    // Fall 2: n > 0 und geradzahlig
    // n wird hier immer größer oder gleich null sein da Bedingung in 1. Paragraph der Aufgabe 
    // n >= 0 also keine Bedingung n > 0 notwendig
    // "%" ist "modulo" operator. "Rest" von einer Division. Mit n % 2 kann man geradzahligkeit bestimmen
    // z.B. 8 Rest 2 == 0 ; 7 Rest 2 == 1 ; 11 Rest 3 == 2
    //      8 % 2 == 0; 7 % 1 == 1; 11 % 3 == 2 usw. 
    else if(n % 2 == 0) {
        int potenz = expo(n / 2);
        return potenz * potenz;
    } 
    // Fall 3: n > 0 und ungerade
    else {
        int potenz = expo((n-1) / 2);
        return 2 * potenz * potenz;
    } 

    
}

int main() {

    int n, rc;

    printf("Eingabe für n: ");
    rc = scanf("%d", &n);

    int mein_ergebnis = expo(n);

    printf("Ergebnis 2^n: %d\n", mein_ergebnis);
    printf("Test: %.2lf\n", pow(2, n));

    return 0;
}