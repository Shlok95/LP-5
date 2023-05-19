#include <iostream>
//#include <vector>
#include <omp.h>
#include <climits>
using namespace std;

void
max_reduction (int arr[], int n)
{
  int max_value = INT_MIN;
#pragma omp parallel for reduction(max: max_value)
  for (int i = 0; i < n; i++)
    {
      if (arr[i] > max_value)
	{
	  max_value = arr[i];
	}
    }
  cout << "Maximum value: " << max_value << endl;
}

void
sum_reduction (int arr[], int n)
{
  int sum = 0;
#pragma omp parallel for reduction(+: sum)
  for (int i = 0; i < n; i++)
    {
      sum += arr[i];
    }
  cout << "Sum: " << sum << endl;
}
int
main ()
{
  int *arr, n;
  cout << "\n enter total no of elements=>";
  cin >> n;
  arr = new int[n];
  cout << "\n enter elements=>";
  for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
// int arr[] = {5, 2, 9, 1, 7, 6, 8, 3, 4};
// int n = size(arr);
  
  max_reduction (arr, n);
  sum_reduction (arr, n);
  
}