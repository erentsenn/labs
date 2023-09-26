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
    scanf("%d",&n);
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
    //delete negative elements
    int count = 0;
    for (int k = 0; k < n; k++)
    {
        if (k < maxx_index && R[k] < 0) {
            for (int j = k; j > count - 1; j--) {
                R[j] = R[j - 1];
            }
            count = count + 1;
        }
    }
    //got array[n-count]
    if (count == 0)
        printf("There are no elements satisfying the condition \n");
    else
    {
        printf("Array r of %d elements\n", n - count);
        for (int i = count; i < n; i++)
        {
            printf("%1.6f\n", R[i]);
        }
    }
    // 3 task
    int last_positive_ind = 0;  
    for (int d = count; d < n; d++)
    {           
        if (R[d] >= R[last_positive_ind] && R[d] > 0)
        {             
            last_positive_ind = d;           
        }     
    } 
    if ((last_positive_ind == 0 && R[last_positive_ind] < 0) || (n - last_positive_ind - 1) == 0)
        printf("The arithmetic mean was not revealed\n");
    else
    {    
        float smm = 0; 
        for (int m = last_positive_ind + 1; m < n - count; m++) {
                
            smm = R[m] + smm;
           
        }
        printf("avg = %f \n", smm / (n - last_positive_ind - 1));
    }
}
