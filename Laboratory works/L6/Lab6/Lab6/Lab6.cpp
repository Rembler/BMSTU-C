#include <iostream>
struct str { char word[80]; str* next; str* prev; };

int main()
{
    char s[80], *l;
    printf("Enter string\n");
    gets_s(s);
    printf("Original string:\n%s\n", s);
    str *op, *ed, * cur, * nex;
    cur = new str;
    op = cur;
    cur->prev = NULL;
    l = strtok(s, " ");
    while (l != NULL)
    {
        strcpy(cur->word, l);
        nex = new str;
        cur->next = nex;
        nex->prev = cur;
        cur = nex;
        l = strtok(NULL, " ");
    }
    cur->next = NULL;
    ed = cur->prev;
    ed->next = NULL;
    printf("String in alphabetical order:\n");
    cur = op;
    str* ri = ed;
    bool dot = false;
    while ((!dot)&&(ri!=NULL))
    {
        dot = true;
        while (cur != ri)
        {
            nex = cur->next;
            bool ex = false;
            int i = 0, l1, l2, ma = 0;
            while (!ex)
            {
                ((int)cur->word[i] < 97) ? (l1 = (int)cur->word[i] + 32) : (l1 = (int)cur->word[i]);
                ((int)nex->word[i] < 97) ? (l2 = (int)nex->word[i] + 32) : (l2 = (int)nex->word[i]);
                if (l1 != l2)
                {
                    ma = l1 - l2;
                    ex = true;
                }
                if ((cur->word[i + 1] == '\0') || (nex->word[i + 1] == '\0'))
                    ex = true;
                else
                    i++;
            }
            if (ma == 0)
                ma = strcmp(cur->word, nex->word);
            if (ma >= 0)
            {
                str* tem = new str;
                strcpy(tem->word, cur->word);
                strcpy(cur->word, nex->word);
                strcpy(nex->word, tem->word);
                dot = false;
                delete tem;
            }
            cur = cur->next;
        }
        ri = ed->prev;
        cur = op;
    }
    cur = op;
    while (cur!=NULL)
    {
        printf("%s ", cur->word);
        cur = cur->next;
    }
    cur = ed;
    printf("\nString in reverse alphabetical order:\n");
    while (cur != NULL)
    {
        printf("%s ", cur->word);
        cur = cur->prev;
    }
    cur = op;
    printf("\nWord(s) with lenght less than 5:\n");
    int co = 0;
    while (cur != NULL)
    {
        if (strlen(cur->word) < 5)
        {
            printf("%s ", cur->word);
            co++;
        }
        cur = cur->next;
    }
    printf("\nThere are %d word(s) with length less than 5", co);
    cur = op;
    delete cur->prev;
    while (cur != NULL)
    {
        nex = cur->next;
        delete cur;
        cur = nex;
    }
    delete cur;
}