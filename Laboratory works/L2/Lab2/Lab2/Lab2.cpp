#include <stdio.h>
#include <math.h>

int main()
{
    puts("Enter x");
    float x, res;
    scanf_s("%f", &x);
    res = (-sqrt(cos(5 * x / (1 - 6 * x))))/ pow(x, 2);
    printf("Result: %4.2f", res);
    return 0;
}