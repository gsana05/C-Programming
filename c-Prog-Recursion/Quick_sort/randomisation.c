/*
DIVIDE AND CONQUER
 * C Program to Implement Quick Sort Using Randomisation: 
 - GENERATING A RANDOM PIVOT POINT point each time
 - recursive algorithm
 - uses less auxiliary space than merge sort - by randomisation it out performs merge sort
 Randomisation will ensure that the time complexity with be "O(n log n)" 
 - input validation has been applied so only numbers can be entered 
 */
#include <stdio.h> /* standard input output library */
#include <stdlib.h> /* standard library - support for rand() */
#include <time.h> /* generate random numbers each time */

void quick_sort(int *array, int start, int end);
int partition(int *array, int start, int end);
void swap(int *x, int *y);

int main()
{
    int howMany = 0;
    int* input; 
    int count = 1;
    int i, k;
    int arraySize;
    
    // allocating dynamic memory for user "number" input 
    char* number; 
    number = (char*)malloc(30*sizeof(char)); // dynamic memory
    if(number == NULL) // checking if the memory has been allocated 
    {
        printf("memory has NOT been allocated \n");
    }
    else
    {
        printf("memory has been allocated \n");
    }
    
    // takes in number of elements you want in the array and validates
    while(howMany == 0) 
    {
        printf("how many numbers do you want to sort \n");
        fgets(number, sizeof(number), stdin); 
        // moving number value into howMany by decimal 
        if(sscanf(number, "%d", &howMany) != 1) // "!= 1" checks if number has been entered 
        {
            printf("Invalid input - please enter a number \n");
            continue;
        }
       
    }
    printf("size of number = %d bytes \n", sizeof(number));  

    input = (int*)malloc(howMany*sizeof(int)); // dynamic memory allocation

    arraySize = sizeof(input)*howMany / sizeof(int); // show the amount of elements in the array 
    if(input == NULL) // check if dynamic memory has been allocated 
    {
        printf("memory has not been allocated \n");
    }
    else 
    {
        printf("memory has been allocated \n");
        printf("sizeof input = %d elements in array which is = %d bytes \n", arraySize, arraySize*sizeof(int));
    }
    
    char* userNumber;
    userNumber = (char*)malloc(30*sizeof(char)); // dynamic memory 
    if( userNumber == NULL) // checks if dynamic memory has been allocated 
    {
        printf("memory has NOT been allocated \n");
    }
    else
    {
        printf("memory has been allocated \n"); 
    }

    for (i = 0; i < howMany; i++) // user inouts the individual number elements in the array 
    {
        input[i] = 0;
        while(input[i] == 0)
        {
            printf("current value --- &input[%d] \n", input[i]);
            printf("enter %d element in the array - to stop putting numbers in press any character key  \n", count);
            fgets(userNumber, sizeof(userNumber), stdin); 
            if(sscanf(userNumber, "%d", &input[i]) != 1) // checks a number has been entered 
            {
                printf("invalid input - please enter a number \n");
                continue; 
            }
            //printf("input OKAY \n");
            count++;
        }
    } 
    
    printf("\n \n");
    printf("unsorted elements \n");
    for(i = 0; i < howMany; i++)
    {
        printf("input[%d] = %d \t", i, input[i]); 
    }

    quick_sort(input, 0, arraySize - 1);

    printf("SORTED \n");
    for(i = 0; i < howMany; i++)
    {
        printf("input[%d] = %d \t", i, input[i]); 
    }
   
}
/* end of main */

void quick_sort(int *array, int start, int end)
{
    printf("\n \n");
    printf("start = %d --- end = %d \n", start, end);
    if (start < end) // base case for recursive calls 
    {
        int split = partition( array, start, end);

        quick_sort(array, start, split - 1); // recursive call
        quick_sort(array, split + 1, end); // recursive call 
    }
    /*
    int i;
    printf("\n\n");
    printf("first element in *array = %d --- length = %d \n", *array, end);

    for(i = 0; i < end; i++)
    {
        printf("QUICK SORT = %d \n", array[i]);
    }
    */
}

int partition(int *array, int start, int end)
{
    // =========================================
  //    RANDOMISED ALGORITHM IMPLEMENTATION
  // =========================================
    srand(time(NULL));
    int pivot_index = start + rand()%(end - start + 1);
    printf("\n\n");
    printf("end - start + 1 = %d \n", end - start + 1);
    printf("pivot index = %d \n", pivot_index);

    int pivot_value = array[pivot_index];
    printf("pivot value = %d \n", pivot_value);

    printf("arr[pivot_index] = %d --- arr[end] = %d \n", array[pivot_index], array[end]);
    swap(&array[pivot_index ], &array[end]); /* swap random pivot to end */
    printf("arr[pivot_index] = %d --- arr[end] = %d \n", array[pivot_index], array[end]);

    int i = start - 1;

    for(int j = start; j <= end - 1; j++)
    {
        printf("array[j] = %d <= pivot_value = %d \n", array[j], pivot_value);
        printf("i = %d \n", i);
        if(array[j] <= pivot_value)
        {
            i++;
            printf("BEFORE -- INSIDE FOR LOOP: array[i] = %d --- array[j] = %d \n", array[i], array[j]);
            swap(&array[i], &array[j]);
            printf("AFTER -- INSIDE FOR LOOP: array[i] = %d --- array[j] = %d \n", array[i], array[j]);
        }
    }
    printf("BEFORE --> OUTSIDE FOR LOOP array[i + 1] = %d --- A[end] = %d \n", array[i + 1], array[end]); 
    swap( &array[i + 1], &array[end] ); /* put the pivot in its rightful position */
    printf("AFTER --> OUTSIDE FOR LOOP array[i + 1] = %d --- A[end] = %d \n", array[i + 1], array[end]); 
    printf("i + 1 = %d \n", i + 1);
    return ( i + 1 );
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("SWAP COMPLETE \n");
}