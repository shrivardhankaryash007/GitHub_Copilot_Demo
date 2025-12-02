// demo.c
// Print the first N Fibonacci numbers (N from command line or prompted).
// Uses unsigned long long and limits N to 93 to avoid 64-bit overflow.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    unsigned long long n = 0;
    
    if (argc >= 2) {
        n = strtoull(argv[1], NULL, 10);
    } else {
        printf("Enter number of Fibonacci terms: ");
        scanf("%llu", &n);
    }

    if (n == 0) return 0;
    if (n > 93) n = 93;

    unsigned long long a = 0, b = 1;
    printf("%llu", a);
    
    for (unsigned long long i = 1; i < n; ++i) {
        printf(" %llu", b);
        unsigned long long next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
    return 0;
}
