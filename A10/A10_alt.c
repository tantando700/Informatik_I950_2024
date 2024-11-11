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
    // Betrag hier auf 100 gesetzt weil "while(Betrag > schranke) bei Betrag = 0 dazu führen würde nicht in den loop reinzugehen
    // theoretisch besser: do { ... } while(Betrag > schranke) dann ist Anfangswert von Betrag egal
    double Betrag = 100;

    while(Betrag > schranke){
        
        // Vorzeichenteil
        double vorz = pow(-1, i - 1);

        // Zählerteil
        double zaehl = pow(x-1, i);

        // Nennerteil == i

        double summand = vorz * zaehl / i;

        sum += summand;

        Betrag = summand;
        // Wenn Betrag negativ dann positiv machen (* -1)
        if(Betrag < 0) {
            Betrag = Betrag * -1;
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