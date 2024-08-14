#include <stdio.h>

int main() {
    int a = 5;  // Example values for a and b
    int b = 10;

    printf("Before swapping: a = %d, b = %d\n", a, b);

    // Swap using XOR
    a = a ^ b;  // Step 1: a becomes a ^ b
    b = a ^ b;  // Step 2: b becomes a (a ^ b) ^ b = a
    a = a ^ b;  // Step 3: a becomes a (a ^ b) ^ a = b

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}