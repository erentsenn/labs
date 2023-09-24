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
    // Input variables
    printf("\nEnter the float x: ");
    scanf("%f", &x);
    printf("\nEnter the float h: ");
    scanf("%f", &h);
    printf("\nEnter the float a: ");
    scanf("%f", &a);
    printf("\nEnter the int n: ");
    scanf("%d", &n);
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
    float maxx = -3;
    int maxx_index = 0;
    for (int j = 0; j < n; j++) {
        if (R[j] > maxx)
        {
            maxx = R[j];
            maxx_index = j;
        }
    }
    printf("max = %f \n", maxx);

    //delete negative
    for (int k = 0; k < n; k++) {
        if ((k < maxx_index && R[k] > 0) || (k >= maxx_index)) {
            for (int j = k; j < n; j++) {
                R[j + 1] = R[j];
            }
        }
    }
    if (new_index == n)
    {
        printf("There are no elements to delete \n");
    }
    else
    {
        printf("Array new_r of %d elements \n", new_index);
        for (int i = 0; i < new_index; i++)
        {
            printf("%3d %1.6f\n", i, new_R[i]);
        }
    }


    if (new_index == 0) {
        printf("The array has been completely deleted\n");
        printf("Task 3\n");
        printf("The arithmetic mean was not revealed\n");

    }
    else {
        printf("new index %d \n", new_index);

        // 3 task
        int last_positive_ind = -1;
        int last_maxx = -3;
        for (int d = 0; d < new_index; d++)
        {
            if (new_R[d] >= last_maxx)
            {
                last_positive_ind = d;
                last_maxx = new_R[d];
            }
        }
        printf("last positive maxx = %d %f \n", last_positive_ind, new_R[last_positive_ind]);
        if (last_positive_ind == -1)
            printf("There are no positive elements\n");
        else
        {
            int smm = 0;
            for (int m = last_positive_ind; m < new_index; m++) {
                smm += new_R[m];
            }
            printf("avg = %f \n", smm / (new_index - last_positive_ind));
        }
    }
}
