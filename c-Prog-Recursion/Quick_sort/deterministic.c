/* C implementation QuickSort 
DETERMINISTIC - meaning we can easily predict the next pivot point, by putting it at the start or end of array 
there is a chance that the time complexity would be O(n2) (quadratic) to avoid this use randomsiation quick sort.
if arrays are already sorted before being sorted this would hit worse case time complexity O(n2)
*/
#include<stdio.h>

void swap(int* a, int* b);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

// Driver program to test above functions
int main()
{
	int arr[] = {8, 4, 3, 2, 6, 5, 7, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
    int i;

    printf("size of n = %d and size n -1 = %d \n \n", n, n-1);
    printf("UNSORTED \n");
    for(int k = 0; k < n; k++)
    {
        printf("arr[%d] - position in array [%d]\n", arr[k], k);
    }
	quickSort(arr, 0, n-1); // "n-1" makes it 0, 1, 2, 3, 4, 5 (6 elements)--- just "n" would make it have 7 elements

	printf("SORTED: n \n");
	for (i=0; i < n; i++)
		printf("%d ", arr[i]);
	printf("n ---------------");
	return 0;
}

// A utility function to swap two elements
void swap(int* a, int* b)
{
    //printf("BEFORE - SWAP - *a = %d and *b = %d \n", *a, *b);
	int t = *a;
	*a = *b;
	*b = t;
    //printf("AFTER - SWAP - *a = %d and *b = %d \n", *a, *b);
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    //printf("\n \n \n");
    printf("partition HIGH = %d \n", high);
	int pivot = arr[high]; // pivot - gets the number in the end position of array 
	int i = (low - 1); // Index of smaller element

    printf("PIVOT VALUE = %d --- i = %d \n", pivot, i);

	for (int j = low; j <= high- 1; j++) // 
	{
        //printf("j = %d *** high - 1 = %d \n", j, high - 1);
		// If current element is smaller than or
		// equal to pivot
        //printf("!!!!arr[j] = %d <= pivot = %d \n", arr[j], pivot);
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
            //printf("SWAP ONE --- &arr[i] = %d and &arr[j] = %d \n", arr[i], arr[j]);
			swap(&arr[i], &arr[j]);
		}
        //printf("\n \n \n");
	}

    //printf("&&&arr[i + 1] = %d --- arr[high] = %d \n", arr[i+1], arr[high]);
	swap(&arr[i + 1], &arr[high]); // value at these two positions passed into swap 
    //printf("return i + 1 = %d \n", i + 1); 
	return (i + 1); // return value to "pi" in quick sort 
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    //printf("before QUICK SORT starts \n");
	if (low < high) // base case 
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
        //printf("low = %d --- high = %d \n", low, high);
		int pi = partition(arr, low, high);
        //printf("pi = %d \n", pi);

		// Separately sort elements before
		// partition and after partition
        //printf("RECIRSION ONE ----------------------------------------------- \n");
        //printf("arr = %d, low = %d, pi - 1 = %d \n", arr, low, pi-1);
		quickSort(arr, low, pi - 1);
        //printf("RECURSION TWO *********************************************** \n");
        //printf("pi = %d \n", pi);
        //printf("arr = %d, pi + 1 = %d, high = %d \n", arr, pi+1, high);
		quickSort(arr, pi + 1, high);
	}
}