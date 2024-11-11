#include <stdio.h>
#include <math.h>

// A11

// Funktion
double expo(int n) {

    if(n == 1) {
        return n;
    } else if(n > 0 && n % 2 == 0) {
        return pow(expo(n / 2), 2);
    } else if(n > 0) {
        return 2 * pow(expo((n-1) / 2), 2);
    } else {
        return 1337;
    }

    
}

int main() {

    int n, rc;

    printf("Eingabe für n: ");
    rc = scanf("%d", &n);

    double mein_ergebnis = expo(n);

    printf("Ergebnis 2^n: %.4lf\n", mein_ergebnis);
    printf("Test: %.4lf\n", pow(2, n));

    return 0;
}