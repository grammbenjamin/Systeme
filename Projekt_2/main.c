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
void clear_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void print_status(uint16_t a, uint16_t b) {
    printf("A Hex: %04X Bits:", a); //04X füllt A als hex mit 4 stellen
    print_bits(a);
    printf("\n B Hex: %04X Bits:", b);
    print_bits(b);
    printf("\n");
}
int frage_bit(void) {
    int n;
    printf("Bitnummer (0 bis 15): ");
    if (scanf("%d", &n) != 1) {
        clear_input();
        printf("Ungültige Eingabe\n");
        return -1;
    }
    if (n < 0 || n > 15) {
        printf("Bitnummer muss zwischen 0 und 15 liegen\n");
        return -1;
    }
    return n;
}

int main(void) {
    uint16_t a = 0;
    uint16_t b = 0;
    int wahl = 1;
    int n;

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
        printf("11 Ein Bit in A loeschen\n");
        printf("12 Ein Bit in A umschalten\n");
        printf("13 Ein Bit in A pruefen\n");
        printf("0  Ende\n");
        printf("Wahl: ");
        if (scanf("%d", &wahl) != 1) {
            clear_input();
            printf("Ungültig Eingabe\n");
            continue;
            }
        switch (wahl) {
            case 0:
                printf("Ende\n");
                return 0;
            case 1:
                printf("A bitte eingeben: ");
                scanf("%hx", &a);
                break;
            case 2:
                printf("B bitte eingeben: ");
                scanf("%hx", &b);
                break;
            case 3:
                a = a + b;
                break;
            case 4:
                a = a & b;
                break;
            case 5:
                a = a | b;
                break;
            case 6:
                a = a ^ b;
                break;
            case 7:
                a = ~a;
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
                n = frage_bit();
                if (n >= 0) {
                    a = a | (1u << n);
                }
                break;
            case 11:
                n = frage_bit();
                if (n >= 0) {
                    a = a & ~(1u << n);
                }
                break;
            case 12:
                n = frage_bit();
                if (n >= 0) {
                    a = a ^ (1u << n);
                }
                break;
            case 13:
                n = frage_bit();
                if (n >= 0) {
                    printf("Bit %d ist %u\n", n, (a >> n) & 1u);
                }
                break;
            default:
                printf("Ungültiger Menüpunkt\n");
                break;
        }
    }
    return 0;
}