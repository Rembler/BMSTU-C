#include <iostream>
#include <ctime>

int main()
{
	int mas[4][4];
	srand(time(0));
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)
			mas[i][j] = rand() % 99 + 1;
	printf("Matrix:\n");
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
			printf("%2d ", mas[i][j]);
		printf("\n");
	}
	int k, mn = 0, max = mas[0][0] * mas[3][3];
	for (int i = 1; i <= 3; i++)
	{
		k = i - 1;
		if (mas[i][i] * mas[k][k] > max)
		{
			mn = i;
			max = mas[i][i] * mas[k][k];
		}
	}
	printf("Desired element is %d and it is located in a row number %d\n", mas[mn][mn], mn + 1);
	printf("Addresses of elements in a row number %d:\n", mn + 1);
	for (int i = 0; i <= 3; i++)
		printf("%X ", &mas[mn][i]);
	printf("\nAddresses of elements in a colon number %d:\n", mn + 1);
	for (int i = 0; i <= 3; i++)
		printf("%X ",  &mas[i][mn]);
}