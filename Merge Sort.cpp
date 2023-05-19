#include<stdio.h>
#include<omp.h>

void
merge (int array[], int low, int mid, int high)
{
  int temp[30];
  int i, j, k, m;
  j = low;
  m = mid + 1;
  for (i = low; j <= mid && m <= high; i++)
    {
      if (array[j] <= array[m])
	{
	  temp[i] = array[j];
	  j++;
	}
      else
	{
	  temp[i] = array[m];
	  m++;
	}
    }
  if (j > mid)
    {
      for (k = m; k <= high; k++)
	{
	  temp[i] = array[k];
	  i++;
	}
    }
  else
    {
      for (k = j; k <= mid; k++)
	{
	  temp[i] = array[k];
	  i++;
	}
    }
  for (k = low; k <= high; k++)
    array[k] = temp[k];
}


void
mergesort (int array[], int low, int high)
{
  int mid;
  if (low < high)
    {
      mid = (low + high) / 2;

#pragma omp parallel sections num_threads(2)
      {
#pragma omp section
	{
	  mergesort (array, low, mid);
	}

#pragma omp section
	{
	  mergesort (array, mid + 1, high);
	}
      }
      merge (array, low, mid, high);
    }
}


int
main ()
{
  int array[50];
  int i, size;
  printf ("Enter total no. of elements:\n");
  scanf ("%d", &size);
  printf ("Enter %d elements:\n", size);
  for (i = 0; i < size; i++)
    {
      scanf ("%d", &array[i]);
    }
  mergesort (array, 0, size - 1);
  printf ("Sorted Elements as follows:\n");
  for (i = 0; i < size; i++)
    printf ("%d ", array[i]);
  printf ("\n");
  return 0;
}
