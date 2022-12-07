#ifndef OMP_BRICK_SORT
#define OMP_BRICK_SORT

#include "utils_sort.h"
#include <omp.h>
#include <stdbool.h>

/** Amount of threads to use **/
#ifndef OMP_THREADS
#define OMP_THREADS 2
#endif

/**
 * Implementation for simple brick sort  using OpenMP Pragmas
 * @param arr as array to sort
 * @param n as amount of elements in the array
 */
void brick_sort(int arr[], int n)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
#pragma omp parallel for schedule(static) num_threads(OMP_THREADS) reduction(&& sorted)
		for (int j = 1; j < n - 1; j += 2)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				sorted = false;
			}
		}
#pragma omp parallel for schedule(static) num_threads(OMP_THREADS) reduction(&& sorted)
		for (int j = 0; j < n - 1; j += 2)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				sorted = false;
			}
		}
	}
}

#endif
