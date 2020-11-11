#include <iostream>

int main()
{
	char strs[10][40];
	printf("Enter strings\nEnter 'End' to stop input process\n");
	gets_s(strs[0]);
	int n = 0;
	while (strcmp(strs[n], "End") != 0)
	{
		n++;
		gets_s(strs[n]);
	}
	printf("Original strings:\n");
	for (int i = 0;i < n;i++)
		printf("%s\n", strs[i]);
	printf("New strings:\n");
	char temp[3][30];
	for (int i = 0;i < n;i++)
	{
		strcpy(temp[0], strtok(strs[i], " "));
		strcpy(temp[1], strtok(NULL, " "));
		strcpy(temp[2], strtok(NULL, " "));
		printf("%s %s %s", temp[1], temp[2], temp[0]);
		printf(" (%s %c. %c.)\n", temp[0], temp[1][0], temp[2][0]);
	}
}