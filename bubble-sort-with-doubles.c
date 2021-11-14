#include <stdio.h>
#include <stdlib.h>

void bubblesort(double *array, int size);
void swap (double* bigger, double* smaller);

int main(void)
{
    int size;
    printf("Welcome! Please enter the size of your array: ");
    scanf("%d", &size);
    double *array = malloc(sizeof(double) * size);
    for (int i = 0; i < size; i++)
    {
        printf("Please enter element %d: ", i + 1);
        scanf("%lf", &array[i]);
    }
    printf("Unsorted array = ");
    for (int i = 0; i < size; i++)
    {

        printf("%.2lf ", array[i]);
    }
    bubblesort(array, size);
    printf("\nSorted array = ");
    for (int i = 0; i < size; i++)
    {

        printf("%.2lf ", array[i]);
    }
    return;
}

void bubblesort(double *array, int size)
{
    int flag = 0;
    for (int n = 0; n < size - 1; n++)
    {
        flag = 0;
        for (int i = 0; i < size - 1 - n; i++)
        {
            if (array[i] > array[i + 1] )
            {
                swap(&array[i], &array[i + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            return 0;
    }
}

void swap (double* bigger, double* smaller)
{
    double temp = *smaller;
    *smaller = *bigger;
    *bigger = temp;
}
