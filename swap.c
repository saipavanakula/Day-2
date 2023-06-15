#include <stdio.h>

void swap(void *a, void *b, size_t size) {
    char temp[size]; // Temporary storage buffer

    // Copy contents of 'a' to 'temp'
    char *tempPtr = (char *)temp;
    char *aPtr = (char *)a;
    for (size_t i = 0; i < size; i++) {
        tempPtr[i] = aPtr[i];
    }

    // Copy contents of 'b' to 'a'
    char *bPtr = (char *)b;
    for (size_t i = 0; i < size; i++) {
        aPtr[i] = bPtr[i];
    }

    // Copy contents of 'temp' to 'b'
    for (size_t i = 0; i < size; i++) {
        bPtr[i] = tempPtr[i];
    }
}

int main() {
    int x = 10;
    int y = 20;

    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y, sizeof(int));
    printf("After swapping: x = %d, y = %d\n", x, y);

    double a = 3.14;
    double b = 2.718;

    printf("Before swapping: a = %f, b = %f\n", a, b);
    swap(&a, &b, sizeof(double));
    printf("After swapping: a = %f, b = %f\n", a, b);

    char c1 = 'A';
    char c2 = 'B';

    printf("Before swapping: c1 = %c, c2 = %c\n", c1, c2);
    swap(&c1, &c2, sizeof(char));
    printf("After swapping: c1 = %c, c2 = %c\n", c1, c2);

    return 0;
}
