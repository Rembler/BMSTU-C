#include <iostream>

long long sum(long long ia, long long ib)
{
    return ia + ib;
}

long long sub(long long ia, long long ib)
{
    return ia - ib;
}

void print(long long ia, long long ib, int ig)
{
    long long rez = 0;
    switch (ig)
    {
    case 0:
        printf("A = ");
        if (ia < 0)
            printf("-%llX B = ", abs(ia));
        else
            printf("%llX  B = ", ia);
        if (ib < 0)
            printf("-%llX\n", abs(ib));
        else
            printf("%llX\n", ib);
        break;
    case 1:
        printf("A + B = ");
        rez = sum(ia, ib);
        break;
    case 2:
        printf("A - B = ");
        rez = sub(ia, ib);
        break;
    case 3:
        printf("B - A = ");
        rez = sub(ib, ia);
        break;
    }
    if (ig != 0)
    {
        if (rez < 0)
            printf("-%llX\n", abs(rez));
        else
            printf("%llX\n", rez);
    }
}

int main()
{
    long long a, b;
    printf("Enter A and B:\n");
    scanf_s("%llX %llX", &a, &b);
    bool ex = true;
    int op;
    while (ex)
    {
        print(a, b, 0);
        printf("Choose one of the following options:\n");
        printf(" 1 - change A and B\n");
        printf(" 2 - sum A and B\n");
        printf(" 3 - subtract B from A\n");
        printf(" 4 - subtract A from B\n");
        printf(" 5 - exit\n");
        scanf_s("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter new A and B:\n");
            scanf_s("%llX %llX", &a, &b);
            break;
        case 2:
            print(a, b, 1);
            break;
        case 3:
            print(a, b, 2);
            break;
        case 4:
            print(a, b, 3);
            break;
        case 5:
            ex = false;
            break;
        }
        if ((op > 5) || (op < 1))
            printf("Incorrect code\n");
    }
}