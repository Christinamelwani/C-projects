#include <stdio.h>
#include <stdlib.h>

void insertion(double *array, int size);

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
    printf("\nUnsorted array = ");
    for (int i = 0; i < size; i++)
    {

        printf("%.2lf ", array[i]);
    }
    insertion(array, size);
    printf("\nSorted array = ");
    for (int i = 0; i < size; i++)
    {

        printf("%.2lf ", array[i]);
    }
    printf("\n");
    return 0;
}

void insertion(double *array, int size)
{
    for (int n = 1; n < size; n++)
    {
        double temp = array[n];
        int p = n - 1;
        while ((p > -1) && (array[p] > temp))
        {
            array[p + 1] = array[p];
            p--;
        }
        array[p + 1] = temp;
    }
}
