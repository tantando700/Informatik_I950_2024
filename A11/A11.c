#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// A11

// Aufbau von Funktionen in C
// <return Wert> <name_der_Funktion>(<Parameter>) {
//      <Funktion macht irgendwas>
// }

// return Wert: - irgendein Datentyp (int, float, double, ...)
//              - an irgendeinem Punkt der Funktion muss eine "return" operation irgendwas zurückgeben dabei muss der Datentyp übereinstimmen sein 
// z.B. return 1 --> gibt "1" aus der Funktion zurück --> "1" ist vom Datentyp "int" --> FUNKTION --> int <name_der_Funktion>(<Parameter>)  
// ungültig wäre: FUNKTION --> int <name_der_Funktion>(<Parameter>) {
//                              return 1.23     
//                            }
// da "1.23" vom Datentyp "float" bzw "double" ist

// name_der_Funktion: - kann generell irgendwas sein (ähnlich wie bei Variablen)
//                    - nur Namensgebung keine semantische Bedeutung fürs Programm

// Parameter: Werte welche einer Funktion übergeben werden

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
    // n >= 0; also keine Bedingung n > 0 notwendig
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

// C-Programme starten immer in der "main()" Funktion
int main() {

    int n, rc;

    printf("Eingabe für n: ");
    rc = scanf("%d", &n);

    // Bedingung erster Paragraph n >= 0
    if(n < 0) {
        printf("Bedingung n >= 0 aber n = %d\n", n);
        printf("ABBRUCH\n");
        return 1;
    }

    int mein_ergebnis = expo(n);

    printf("Ergebnis 2^n: %d\n", mein_ergebnis);
    printf("Test: %.2lf\n", pow(2, n));

    return 0;
}