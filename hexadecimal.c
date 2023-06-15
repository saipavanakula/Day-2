#include <stdio.h>

void printExponent(double x) {
    unsigned long long ptr = (unsigned long long)&x;
    unsigned long long exponent = (*ptr >> 52) & 0x7FF;
    unsigned int hexExponent = (unsigned int)exponent;
    unsigned int binaryExponent = 0;

    printf("Hexadecimal exponent: 0x%X\n", hexExponent);

    // Convert to binary
    for (int i = 10; i >= 0; i--) {
        binaryExponent = (binaryExponent << 1) | ((hexExponent >> i) & 1);
    }

    printf("Binary exponent: 0b");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (binaryExponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);
    return 0;
}
