#include <stdio.h>
#include <math.h>

// A09
// Algorithmus in A02

int main() {

    int rc;
    double x;
    double G = 0.001;

    printf("x: ");
    rc = scanf("%lf", &x);

    double a = x;
    double b = 1;
    double betrag;

    do {

        a = (a + b) / 2;
        b = x / a;

        // Betrag
        betrag = a - b;
        if(betrag < 0) {
            betrag = -1 * betrag;
        }

    } while(betrag > G);

    printf("Die Wurzel aus %.2lf ist %.2lf\n", x, a);
    printf("Test: %.2lf\n", sqrt(x));


    return 0;
}