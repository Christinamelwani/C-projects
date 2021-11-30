#include <stdio.h>
#include <stdlib.h>
int size = 0;
int get_int(char * prompt);
void recursive_merge_sort(int * list, int low, int high);
void merge(int *list, int low, int mid, int high);
int main(void)
{
    //Main infinite loop
    for(;;)
    {
        size = get_int("Enter the size of your list: ");
        int *array_a = malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++)
        {
            char prompt[20];
            sprintf(prompt, " Enter element %d- ", i + 1);
            array_a[i] = get_int(prompt);
        }
        printf("\n\nUnsorted array:\n ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", array_a[i]);
        }
        recursive_merge_sort(array_a, 0, size - 1);
        printf("\n\nSorted array:\n ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", array_a[i]);
        }
        printf("\n\nInversion count: not implemented");
        char check = ' ';
        while (check != 'y' && check != 'n')
        {
            printf("\n\nContinue? (y/n):\n ");
            scanf("\n%c", &check);
            if (check == 'n')
            {
                return 0;
            }
            printf("\n");
        }
    }
}


int get_int(char *prompt)
{
    int input = 0;
    for(;;)
    {
        printf("%s", prompt);
        if (scanf("%d", &input) == 1)
            return input;
        else
            fflush(stdin);
    }
}


void recursive_merge_sort(int *list, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        recursive_merge_sort(list, low, mid);
        recursive_merge_sort(list, mid + 1, high);
        merge(list, low, mid, high);
    }
}


void merge(int *list, int low, int mid, int high)
{
    int temp[size];
    int leftptr = low;
    int tempptr = low;
    int rightptr = mid + 1;
    while (leftptr <= mid && rightptr <= high)
    {
        if (list[leftptr] < list[rightptr])
        {
            temp[tempptr] = list[leftptr];
            leftptr++;
        }
        else
        {
            temp[tempptr] = list[rightptr];
            rightptr++;
        }
        tempptr++;
    }
    while (leftptr <= mid)
    {
        temp[tempptr] = list[leftptr];
        tempptr++;
        leftptr++;
    }
    while (rightptr <= high)
    {
        temp[tempptr] = list[rightptr];
        tempptr++;
        rightptr++;
    }
    for (int i = low; i <= high; i++)
    {
        list[i] = temp[i];
    }
}
