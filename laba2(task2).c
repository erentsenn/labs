#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <locale.h>
#define lmax 200 

int main() 
{
	printf("Lab 2.\n");
	printf("Task 2.\n");
	int X[lmax], Q[lmax], f, k;
	printf("Enter length of arr X from 1 to %d: ", lmax);
	do
	{
		f = scanf("%d", &k);
		while (getchar() != '\n');
	}
	while (k <= 0 || k >= lmax || f != 1);
	printf("Enter elements of arr X: \n");
	for (int i = 0; i < k; i++)
	{
		do
		{
			f = scanf("%d", &X[i]); //заполнение массива
			while (getchar() != '\n');
		} while (X[i] > INT_MAX || f != 1 || X[i] < 0);
	}
	int a;
	int s;
	int odd;
	int even;
	int p = 0;
	for (int i = 0; i < k; i++)
	{
		s = 0;
		even = 0;
		odd = 0;
		a = X[i];
		while (a >= 1)
		{
			if (s % 2 == 0)
			{
				odd += a % 10;
			}
			else
			{
				even += a % 10;
			}
			a = a / 10; //"откидывание" последней цифры числа для поиска количества цифр
			s += 1;//количество цифр в числе
		}
		if (odd == even)
		{
			Q[p] = X[i];
			p++;
		}
	}
	if (p > 0)
	{
		printf("Array Q: \n");
		for (int j = 0; j < p; j++)
		{
			printf("%d ", Q[j]);
		}
	}
	else
	{
		printf("Array Q is empty");
	}
	
	return 0;
}
