#include <stdio.h>
#include <math.h>

int main()
{
    puts("Enter coordinates of vertices of the triangle");
    int x1, y1, x2, y2, x3, y3;
    scanf_s("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    double l1, l2, l3, hp, p;
    l1 = sqrt(pow(abs(x2 - x1),2)+pow(abs(y2-y1),2));
    l2 = sqrt(pow(abs(x3 - x2), 2) + pow(abs(y3 - y2), 2));
    l3 = sqrt(pow(abs(x1 - x3), 2) + pow(abs(y1 - y3), 2));
    if ((l1 + l2 > l3) && (l2 + l3 > l1) && (l3 + l1 > l2))
    {
        hp = (l1 + l2 + l3) / 2;
        p = sqrt(hp * (hp - l1) * (hp - l2) * (hp - l3));
        printf("Square: %5.2f\n", p);
        if ((l1 == l2) && (l2 == l3))
            puts("Triangle is equilateral");
        else
            if (((l1 == l2) && (l1 != l3)) || ((l2 == l3) && (l2 != l1)) || ((l1 == l3) && (l2 != l1)))
                puts("Triangle is isosceles");
            else
                puts("Triangle is scalene");
    }
    else
        printf("ERROR");
    return 0;
}
