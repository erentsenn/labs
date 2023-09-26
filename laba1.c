#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#define lmax 200

int main()
{
    // Declare the variables
    float x;
    float h;
    float a;
    int n;
    printf("Laboratory work N. 1\n");
    printf("Task 1\n");
    // Input variables
    printf("Enter the length of the array r from 1 to %d: ", lmax);
    printf("\nEnter the float x: ");
    scanf("%f", &x);
    printf("\nEnter the float h: ");
    scanf("%f", &h);
    printf("\nEnter the float a: ");
    scanf("%f", &a);
    // declare massiv
    double R[lmax];
    for (int i = 0; i < n; i++) {
        R[i] = 2.5 * sin(a * x + i * i * h);
    }
    //output massiv
    printf("Array r of %d elements \n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%3d %1.6f\n", i, R[i]);
    }

    // 2 task
    // find max
    printf("Task 2\n");
    float maxx = -3;
    int maxx_index = 0;
    for (int j = 0; j < n; j++) {
        if (R[j] > maxx)
        {
            maxx = R[j];
            maxx_index = j;
        }
    }
    printf("max = %f index =%d\n", maxx, maxx_index);

    //delete negative before maxx_index
    int count = 0;
    int k = 0;
    while (k < n)
    {
        if (k < maxx_index && R[k] < 0) {
            for (int j = k; j < n - count; j++) {
                R[j] = R[j + 1];
            }
            count = count + 1;
            k = k - 1;
        }
        k = k + 1;
    }
    //got array[n-count]
    printf("Array r of %d elements\n", n - count);
    for (int i = 0; i < n - count; i++)
        {
        printf("%3d %1.6f\n", i, R[i]);
        }
    if (n - count == 0) {
        printf("The array has been completely deleted\n");
        printf("Task 3\n");
        printf("The arithmetic mean was not revealed\n");

    }
    else {

        // 3 task
        int last_positive_ind = -1;
        int last_maxx = -3;
        for (int d = 0; d < n - count; d++)
        {
            if (R[d] >= R[last_positive_ind])
            {
                last_positive_ind = d;
            }
        }
        printf("last positive maxx = %d %f \n", last_positive_ind, R[last_positive_ind]);
        if (last_positive_ind == -1)
            printf("There are no positive elements\n");
        else
        {
            float smm = 0;
            for (int m = last_positive_ind + 1; m < n - count; m++) {
                smm = R[m] + smm;
            }
            printf("avg = %f \n", smm/(n - count - last_positive_ind - 1));
        }
    }
    
}
