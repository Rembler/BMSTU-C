#include <iostream>

class disp1
{
protected: 
    char prod[15];
    char reso[5];
    float diag;
public:
    void init()
    {
        printf("Enter the diagonal of this display\n");
        scanf_s("%f", &diag);
        printf("Enter the resolution (4:3 or 16:9) of this display\n");
        gets_s(reso);
        gets_s(reso);
        printf("Enter the manufacturer of this display\n");
        gets_s(prod);         
    }
    void print()
    {
        printf("%s is the manufacturer of this display\n", prod);
        printf("The diagonal of this monitor is %3.2f inches\n", diag);
        printf("The resolution of this monitor is %s\n", reso);
    }
    void dime()
    {
        if (strcmp(reso,"4:3")==0)
        {
            printf("The width is %3.2f centimeters\n", (2.54 * diag * 4) / 5);
            printf("The length is %3.2f centimeters\n", (2.54 * diag * 3) / 5);
        }
        else
        {
            printf("The width is %3.2f centimeters\n", (2.54 * diag * 16) / sqrt(337));
            printf("The length is %3.2f centimeters\n", (2.54 * diag * 9) / sqrt(337));
        }
    }
};

class disp2 :public disp1
{
public:
    disp2(float adi, char apr[15], char are[5])
    {
        diag = adi;
        strcpy_s(prod, apr);
        strcpy_s(reso, are);
    }
    disp2() {}
};

int main()
{
    disp1 dum1;
    dum1.init();
    float a = 14;
    char b[15] = "Benq", c[5] = "4:3\0";
    disp2 dum2(a, b, c);
    printf("\nInfo about first display:\n");
    dum1.print();
    printf("\nInfo about second display:\n");
    dum2.print();
    printf("\nLength and width of first display:\n");
    dum1.dime();
    printf("\nLength and width of second display:\n");
    dum2.dime();
}