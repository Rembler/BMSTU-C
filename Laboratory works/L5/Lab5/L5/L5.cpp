#include <stdio.h>

int main()
{
	puts("Enter your string");
	char s[241];
	int i = 0,j=0,c=0,cj=0;
	gets_s(s);
	puts("Words:");
	while (s[j] != '\0')
	{
		printf("%c", s[j]);
		if ((s[j] == ' ') || (i == 11))
		{
			i=0;
			printf("\n");
		}
		else
			i++;
		if ((s[j] == ' ') && (c != 2))
		{
			c++;
			if (c == 2)
				cj = j + 1;
		}
		j++;
	}
	puts("\nAddresses of chars of third word:");
		while ((s[cj] != ' ') && (s[cj]!='\0'))
		{
			printf("%X ", &s[cj]);
			cj++;
		}
	return 0;
}
