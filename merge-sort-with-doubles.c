#include <stdio.h>
#include <stdlib.h>

double GetUserInput (void);
double *GetArray (int ArraySize);
void MergeSort(int start, int end, double array[], int limit);
void merge(int start, int mid, int end, double array[], int limit);
void swap (double *i, double *j);
void Print (double *arr, int size);

int main (void)
{
    for (;;)
    {
        //Take input from user in the form of an array of doubles:
        printf("How many numbers would you like to sort?\n\t(press 'e' and then enter to exit)\n");
        int NumberOfDoubles = GetUserInput ();
        if (NumberOfDoubles == 99999999)
            break;
        double *arr = GetArray (NumberOfDoubles);

        //Print the unsorted array:
        printf ("\nUnsorted Array: \n ");
        Print (arr, NumberOfDoubles);

        //Sort the array:
        MergeSort(0, NumberOfDoubles - 1, arr, NumberOfDoubles);

        //Print the sorted array:
        printf("\n\nSorted Array:\n ");
        Print(arr, NumberOfDoubles);
        printf("\n\n");
    }
  return 0;
}

double GetUserInput (void)
{
  //Take input from user in the form of a number:
  double Input = 0;
  while (Input == 0)
    {
      char buffer[20];
      fgets (buffer, 20, stdin);
        if (buffer[0] != 'e')
        {
            Input = atof (buffer);
            if (Input == 0)
            {
                printf ("Invalid input! Try again:\n");
            }
        }
        else
            return 99999999;
    }
  return Input;
}

double * GetArray (int ArraySize)
{
  double *arr = malloc (sizeof (double) * ArraySize);
  for (int i = 0; i < ArraySize; i++)
    {
      printf ("Enter the %d%s number: ", i + 1,
	      (i + 1) % 10 == 1 ? "st" :
	      (i + 1) % 10 == 2 ? "nd" : (i + 1) % 10 == 3 ? "rd" : "th");
      arr[i] = GetUserInput ();
    }
  return arr;
}


void MergeSort(int start, int end, double array[], int limit)
{
    if (start < end)
    {
        int mid = (start + end)/2;
        MergeSort(start, mid, array, limit);
        MergeSort(mid + 1, end, array, limit);
        merge(start, mid, end, array, limit);
    }
}

void merge(int start, int mid, int end, double array[], int limit)
{
    double temp[limit];
    int f = start;
    int n = 0;
    int s = mid + 1;

    while (f <= mid && s <= end)
    {
        if (array[f] <= array[s])
        {
            temp[n] = array[f];
            f++;
        }
        else
        {
            temp[n] = array[s];
            s++;
        }
        n++;
    }
    while (f <= mid)
    {
        temp[n] = array[f];
        n++, f++;
    }
    while (s <= end)
    {
        temp[n] = array[s];
        n++, s++;
    }
    for (int i = start;  i <= end;  i++)
    {
        array[i] = temp[i - start];
    }
}
void swap (double *i, double *j)
{
  double temp = *i;
  *i = *j;
  *j = temp;
}


void Print (double *arr, int size)
{
  for (int i = 0; i < size; i++)
    {
      printf ("%.2lf ", arr[i]);
    }
}
