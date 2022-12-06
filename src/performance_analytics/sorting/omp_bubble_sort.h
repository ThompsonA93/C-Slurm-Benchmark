#ifndef OMP_BUBBLE_SORT
#define OMP_BUBBLE_SORT

#include "utils_sort.h"
#include <omp.h>
#include <stdbool.h>
/**
 * Implementation for simple bubble sort
 * @param arr as array to sort
 * @param n as amount of elements in the array
 */

void omp_bubble_sort(int arr[], int n)
{
	bool sorted = false;
    while (!sorted)
    {
	sorted = true;
    	#pragma omp parallel for schedule(static) default(none) shared(arr) shared(n)  reduction(&&:sorted) 
        for (int j = 1; j < n - 1; j+=2)
        {
            if (arr[j] > arr[j + 1])  
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
		sorted = false;
            }
        }
	#pragma omp parallel for schedule(static) reduction(&&:sorted)
	for(int j = 0; j < n -1; j+=2){
	   if (arr[j] > arr[j +1]){
		int t = arr[j];
     		arr[j] = arr[j + 1];
		arr[j + 1] = t;
		sorted = false;		
	   }
	}
    }
}

#endif
