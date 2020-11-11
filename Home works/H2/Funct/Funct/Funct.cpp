#include <iostream>

int mas[50];

int fragment(long long imn)
{
    int ii = -1;
    while (imn != 0)
    {
        ii++;
        mas[ii] = imn % 10;
        imn = imn / 10;
    }
    return ii;
}

long long revasum(long long imn, int in)
{
    long long rev = 0, fac = 1;
    for (int ii = in; ii >= 0;ii--)
    {
        rev += mas[ii] * fac;
        fac *= 10;
    }
    return imn + rev;
}

bool check(int in)
{
    int iif = 0, iib = in;
    bool flag = true;
    while (iif != (in / 2)+1)
    {
        if (mas[iif] != mas[iib])
            flag = false;
        iif++;
        iib--;
    }
    return flag;
}

int main()
{
    printf("Enter natural number\n");
    long long mn; 
    int i = 1;
    scanf_s("%lld", &mn);
    printf("Original number: %lld\n", mn);
    while (!check(fragment(mn)))
    {
        mn = revasum(mn, fragment(mn));
        printf("Step %d: %lld\n", i, mn);
        i++;
    }
    printf("The last number is palindrome");
}