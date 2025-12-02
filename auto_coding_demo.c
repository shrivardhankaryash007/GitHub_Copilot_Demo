#include <stdio.h>
#include <stdint.h>

#define FIXED_POINT_SHIFT 16U /* number of fractional bits */
#define FIXED_POINT_ONE (1L << FIXED_POINT_SHIFT) /* 1.0 in Q16.16 */

int32_t fibonacci(int32_t n)
{
    int32_t a = 0;                        /* F(0) = 0.0 (fixed-point) */
    int32_t b = (int32_t)FIXED_POINT_ONE;/* F(1) = 1.0 (fixed-point) */
    int32_t temp;
    int32_t i;

    if (n <= 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    for (i = 2; i <= n; i++)
    {
        temp = b;
        /* keep values in fixed-point (Q16.16) when adding */
        b = (int32_t)((int32_t)a + (int32_t)b);
        a = temp;
    }

    /* convert fixed-point result to integer (truncate fractional part) */
    return (int32_t)(b >> FIXED_POINT_SHIFT);
}

int main(void)
{
    int32_t n = 10;
    int32_t result = fibonacci(n);
    printf("Fibonacci(%d) = %d\n", n, result);
    return 0;
}