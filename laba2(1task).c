#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <locale.h>
#define lmax 200 



int main()
{
	printf("Lab 2.\n");
	printf("Task 1.\n");
	int Z[lmax][lmax], F[lmax], Q[lmax], n, m, k, f;
	printf("Enter length of matrix Z from 1 to %d and columns from 1 to %d: ", lmax, lmax);
	do
	{
		f = scanf("%d%d", &n, &m);
		while (getchar() != '\n');
	} 
	while (n <= 0 || m <= 0 || n >= lmax || m >= lmax || f != 2);

	printf("Enter elements of matrix Z: \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			do
			{
				f = scanf("%d", &Z[i][j]); //заполнение матрицы
				while (getchar() != '\n');
			} 
			while (Z[i][j] > INT_MAX || f != 1);
		}
	}
	printf("The led matrix: \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", Z[i][j]); //вывод введенной матрицы для удобства пользователя
		}
		printf("\n");
	}
	printf("Enter length of arr F from 1 to %d: ", lmax);
	do
	{
		f = scanf("%d", &k);
		while (getchar() != '\n');
	}
	while (k <= 0 || k >= lmax || f != 1);
	printf("Enter elements of arr F: \n");
	for (int i = 0; i < k; i++)
	{
		do
		{
			f = scanf("%d", &F[i]); //заполнение массива
			while (getchar() != '\n');
		} 
		while (F[i] > INT_MAX || f != 1);
	}

	int p = 0;
	int flag2 = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Z[j][i] < 0)
			{
				printf("first negative - %d", Z[j][i]);
				for (int t = j + 1; t < m; t++)
				{
					flag2 = 0;
					for (int v = 0; i < k; i++)
					{
						if (Z[t][i] == F[v])
						{
							flag2 = 1;
							break;
						}
					}
					if (flag2 == 0)
					{
						Q[p] = Z[t][i];
						p++;
					}
				}
				break;
			}
		}

	}
	for (int a = 0; a < p; a++)
	{
		printf("%d ", Q[a]);
	}
	return 0;
}
