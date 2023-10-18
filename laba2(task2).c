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
	for (int i = 0; i < k; i++)
	{
		a = X[i];
		while (a >= 1)
		{
			a = a / 10; //"откидывание" последней цифры числа для поиска количества цифр
			s += 1;//количество цифр в числе
		}
	}
	printf("Arr has been changed:\n");
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", X[i]);
	}
	return 0;
}
