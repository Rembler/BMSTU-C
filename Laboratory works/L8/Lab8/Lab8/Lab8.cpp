#include <iostream>

class bing
{
protected:
    int nof;
    float hei;
public:
    void init(int inof, float ihei)
    {
        nof = inof;
        hei = ihei;
    }
    void print()
    {
        printf("Number of floors: %d\n", nof);
        printf("Height of building: %3.2f meters\n", hei);
    }
    float floorhei()
    {
        float tem;
        tem = hei / nof;
        return tem;
    }
};

class libing : public bing
{
protected:
    float squ;
    int fof;
public:
    void init(int inof, float ihei, float isqu, int ifof)
    {
        nof = inof;
        hei = ihei;
        squ = isqu;
        fof = ifof;
    }
    void print()
    {
        printf("Number of floors: %d\n", nof);
        printf("Height of building: %3.2f meters\n", hei);
        printf("Number of flats on one floor: %d\n", fof);
        printf("Foundation area: %3.2f square meters\n", squ);
    }
    float flatsiz()
    {
        float tem;
        tem = (squ / fof) * floorhei();
        return tem;
    }
};

int main()
{
    int mnof, mfof;
    float mhei, msqu;
    printf("Enter height and number of floors\n");
    scanf_s("%f %d", &mhei, &mnof);
    bing pavl;
    pavl.init(mnof, mhei);
    pavl.print();
    printf("Height of floor: %3.2f meters\n", pavl.floorhei());
    printf("Enter number of flats on one floor and foundation area\n");
    scanf_s("%d %f", &mfof, &msqu);
    libing kosm;
    kosm.init(mnof, mhei, msqu, mfof);
    kosm.print();
    printf("Volume of flat: %3.2f cubic meters", kosm.flatsiz());
}