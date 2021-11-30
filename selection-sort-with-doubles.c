#include <stdio.h>
#include <stdlib.h>

double GetUserInput (void);
double *GetArray (int ArraySize);
void SelectionSort (double arr[], int limit);
void swap (double *i, double *j);
void Print (double *arr, int size);

int main (void)
{
  //Take input from user in the form of an array of doubles:
  printf ("How many numbers would you like to sort? ");
  int NumberOfDoubles = GetUserInput ();
  double *arr = GetArray (NumberOfDoubles);

  //Print the unsorted array:
  printf ("Unsorted Array: \n");
  Print (arr, NumberOfDoubles);

  //Sort the array:
  SelectionSort (arr, NumberOfDoubles);
  //Print the sorted array:
  printf ("\nSorted Array:\n");
  Print (arr, NumberOfDoubles);
  return 0;
}

double GetUserInput (void)
{
  //Take input from user in the form of a number:
  double Input = 99999999;
  while (Input == 99999999)
    {
      char buffer[20];
      fgets (buffer, 20, stdin);
      Input = atof (buffer);
      if (Input == 99999999)
	{
	  printf ("Invalid input! Try again:\n");
	}
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

void SelectionSort (double arr[], int limit)
{
  for (int i = 0; i < limit; i++)
    {
      int small = i;
      for (int j = i + 1; j < limit; j++)
	{
	  if (arr[j] < arr[small])
	    {
	      small = j;
	    }
	}
      swap (&arr[i], &arr[small]);
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
