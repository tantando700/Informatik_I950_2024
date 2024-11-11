#include <stdio.h>
#include <math.h>

// A10

int main() {

    int rc;
    double x;

    // je kleiner Schranke desto genauer Ergebnis
    double schranke = 0.0001;
    double sum = 0;

    printf("x für log(x): ");

    rc = scanf("%lf", &x);

    // Test ob x im gültigen Bereich liegt
    if(x >= 2 || x <= 0) {
        printf("Bedingung: 0 < x < 2 !!!\n");
        printf("ABBRUCH!\n");

        // aus main() funktion raus bzw. Program abbrechen
        return 1;
    }

    int i = 1;

    // while(1) => "1" == TRUE
    // loop wird unendlich lang laufen da Bedingung while(TRUE) immer wahr ist
    // nur "break" kann aus dem loop ausbrechen
    while(1){
        
        // Vorzeichenteil
        double vorz = pow(-1, i - 1);

        // Zählerteil
        double zaehl = pow(x-1, i);

        // Nennerteil == i

        double summand = vorz * zaehl / i;

        sum += summand;

        // if("Betrag" < schranke)
        // "Betrag" = ((summand < 0) ? (-1 * summand) : (summand)) => google "ternary operator in C" -> ternary operator ist das gleiche wie "if" operation nur kürzer geschrieben
        // vereinfacht kann man auch seperat "Betrag" ausrechnen
        if( ((summand < 0) ? (-1 * summand) : (summand)) < schranke) {
            // aus while loop rausbrechen
            break;
        }

        i++;
    }
    
    // Anzahl an loops die in While Schleife durchgeführt wurden
    printf("Anzahl an Summanden: %d\n", i);

    printf("ln(%.4lf) = %.4lf\n", x, sum);

    // Test mit log() funktion aus <math.h> Bibiliothek 
    printf("Test: %.4lf\n", log(x));


    return 0;
}