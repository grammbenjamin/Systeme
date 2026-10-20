#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_bits(uint16_t x) {
    for (int i = 15; i >= 0; i--) {
        printf("%u", (x >> i) & 1u);
        if (i == 8) {
            printf(" ");
        }
    }
}
void print_status(uint16_t a, uint16_t b) {
    printf("A Hex: %04X Bits:", a); //04X füllt A als hex mit 4 stellen
    print_bits(a);
    printf("\n B Hex: %04X Bits:", b);
    print_bits(b);
    printf("\n");
}
int main(void) {
    uint16_t a = 0;
    uint16_t b = 0;
    uint8_t wahl = 1;

    while (1) {
        print_status(a, b);

        printf("\n1  A eingeben (Hex)\n");
        printf("2  B eingeben (Hex)\n");
        printf("3  A = A + B\n");
        printf("4  A = A UND B\n");
        printf("5  A = A ODER B\n");
        printf("6  A = A XOR B\n");
        printf("7  A = NICHT A\n");
        printf("8  A um B Stellen nach links schieben\n");
        printf("9  A um B Stellen nach rechts schieben\n");
        printf("10 Ein Bit in A setzen\n");
        printf("11 Ein Bit in A löschen\n");
        printf("12 Ein Bit in A umschalten\n");
        printf("13 Ein Bit in A prüfen\n");
        printf("0  Ende\n");
        printf("Wahl: ");
        scanf("%d", &wahl);
        if (scanf("%d", &wahl) != 1) {
            int c;
            while ((c == getchar()) && (c != EOF)){
                printf("Ungültige Eingabe");
                continue;
            }
        }
        switch (wahl) {
            case 1:
                printf("A bitte eingeben");
                scanf("%hx", &a);
                break;
            case 2:
                printf("B bitte eingeben");
                scanf("%hx", &b);
                break;
            case 3:
                a = a + b;
                break;
            case 4:
                a = a & b;
                break;
            case 5:
                a = a || b;
                break;
            case 6:
                a = a ^ b;
                break;
            case 7:
                a = !a;
                break;
            case 8:
                if (b > 15) {
                    printf("B muss zwischen 0 und 15 liegen");
                }else {
                    a = a << b;
                }
                break;
            case 9:
                if (b > 15) {
                    printf("B muss zwischen 0 und 15 liegen");
                }else {
                    a = a >> b;
                }
                break;
            case 10:
                

        }
    }
}