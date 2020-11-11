#include <iostream>

int main()
{
    FILE* f, * g, * h;
    f = fopen("F.dat", "w+");
    g = fopen("G.dat", "w+");
    char *s = new char[50];
    printf("Enter content of the first file\n");
    s = gets_s(s,50);
    for (int i=0; i <= strlen(s); i++)
        fputc(s[i], f);
    printf("Enter content of the second file\n");
    s = gets_s(s, 50);
    for (int i = 0; i <= strlen(s); i++)
        fputc(s[i], g);
    delete[]s;
    rewind(f);
    rewind(g);
    if ((fgetc(f) == '\0') || (fgetc(g) == '\0'))
        printf("One of the files is empty. Futher actions are pointless.");
    else
    {
        rewind(f);
        rewind(g);
        char ch = fgetc(f);
        printf("File 'F' content:\n");
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = fgetc(f);
        }
        printf("\n");
        ch = fgetc(g);
        printf("File 'G' content:\n");
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = fgetc(g);
        }
        printf("\n");
        rewind(f);
        rewind(g);
        printf("File 'H' content:\n");
        char c1, c2;
        bool flag = true;
        h = fopen("H.dat", "w+");
        while (flag)
        {
            c1 = fgetc(f);
            c2 = fgetc(g);
            if ((c1 != c2) || (c1 == '\0'))
                flag = false;
            else
            {
                fputc(c1, h);
                printf("%c", c1);
            }
        }
        if (fgetc(h) == EOF)
            printf("File 'H' is empty");
        fclose(f);
        fclose(g);
        fclose(h);
    }
}