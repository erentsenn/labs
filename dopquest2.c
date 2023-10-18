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
	int Z[lmax][lmax], n, m, f;
	printf("Enter length of matrix Z from 1 to %d and columns from 1 to %d: ", lmax, lmax);
	do
	{
		f = scanf("%d%d", &n, &m);
		while (getchar() != '\n');
	} while (n <= 0 || m <= 0 || n >= lmax || m >= lmax || f != 2);

	printf("Enter elements of matrix Z: \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			do
			{
				f = scanf("%d", &Z[i][j]); //заполнение матрицы
				while (getchar() != '\n');
			} while (Z[i][j] > INT_MAX || f != 1);
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
	int tmp = 0;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = 0; j < m; j++)
		{
			if (Z[i][j] == 0)
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			for (int k = i; k < n; k++)
			{
				for (int v = 0; v < m; v++)
				{
					Z[k][v] = Z[k + 1][v];
				}
			}
			i -= 1;
			tmp++;	
			break;
		}
	}
	if (tmp >= n)
	{
		printf("Matrix deleted");
	}
	else
	{ 
		printf("tmp = %d \n", tmp);
		printf("New matrix \n");
		for (int i = 0; i < n - tmp; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("%d ", Z[i][j]); //вывод введенной матрицы для удобства пользователя
			}
			printf("\n");
		}
	}
	return 0;
