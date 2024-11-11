#include <stdio.h>
#include <math.h>

int main() {

    int a, b, c;
    int rc1, rc2;
    printf("Berechnung ggt(a,b)\n");
    printf("a: ");
    rc1 = scanf("%d", &a);
    printf("b: ");
    rc2 = scanf("%d", &b);

    /* mit rc1, rc2 wird angezeigt, wie viele Eingabewerte scanf()
    erfolgreich eingelesen hat. */
    if (rc1 < 1 || rc2 < 1)
    {
    printf("Fehler bei Eingabe.\n");
    return 0;
    }

    // hier soll der algorithmische Teil eingefügt werden
    while(a != b) {
        if(b < a) {
            a = a - b;
        } else {
            c = a;
            a = b;
            b = c;
        }
    }

    printf("Der ggT ist: %d\n", a);

    return 0;
}