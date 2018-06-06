#include <stdio.h>
#include <time.h>

int main()
{
    for(int i = 0; i < 30000000; i++);
    float ticks = clock();
    printf("%f \n", ticks/ CLOCKS_PER_SEC);
}

/* //FAST - O(1)
// CONSTANT TIME = O(1) - Data size/input does not affect program execution speed - constant upper bound
int main()
{
    int array[] = {5, 6, 8, 13, 2}; 
    int sum; // 1 unit = O(1) as its runs 1 time
    sum = array[0] + array[1]; // 2 units =  O(1) as it runs 1 time 
    // O(1) + O(1) = O(1) - fasting growing term 
    printf("The sum array[0] = %d + array[1] = %d == %d \n", array[0], array[1], sum);
}
*/

/*
// SLOW DEPENDING AMOUNT OF INPUT // basedon additon - O(n)
// if single loop is incremented or drecremented by constant amount its O(n)
// LINEAR TIME = O(n) // the more data/input, the slower the program execution 
//The running time of the loop is directly proportional to N. When N doubles, so the running time DOUBLES.
int main()
{
    int n; // 1 unit O(1)
    int totalSum = 0; // 1 unit O(1)

    for(n = 0; n < 10; n++) // n*O(1) - repreats loop n times which is 10 in this case 
    {
        totalSum += n; // 2 units = O(1) 
    }
    // O(1) + O(1) = c1 (put it into const to improve readability)
    // middle O(1) = c2 (put it into const to improve readability)
    // c1 + n*c2 = n*c2 is the fastest growing term 
    // n*c2 = remove coefficient (c2) 
    // get the result O(n)
    //(O(1) + n*O(1) + O(1) = O(n)
    printf("sum total = %d", totalSum);
}
*/

/*
// VERY SLOW TRY TO AVOID - O(n2)
// if nested loop is incremented or drecremented by constant amount its O(n2)
// QUADRATICS = O(n2) - The running time of the two loops is proportional to the square of N (n2).
// When N doubles, the running time increases by N * N.
int main()
{
    int i, j; // 1 unit = O(1)
    int n = 1000; // 1 unit = O(1)

    for ( i = 0; i < n; i++ ) 
    {                            // n2*O(1) - because two loops are combined 
        for ( j = 0; j < n; j++ )
        {
            // O(1) + O(1) = c1 (put it into const to improve readability)
            // last O(1) = c2 (put it into const to improve readability)
            // c1 + n2 * c2 = get the fastest growing term
            // fastest growing term n2 * c2
            // remove coefficient (c2)
            // ANSWER O(n2)
            // O(1) + O(1) + n2 * (01) = O(n2)
            printf("love = %d \n", i+1);
        }
    }
}
*/

/*
//FASTEST METHOD!!! AND MOST USEFUL - O(log n) -LOGARITHM
// O(log n) - keep halfing array until you left with 1 element // based multiplication 
// log is for logarithmic - to the power using base 2 and exponents
// the time it takes to run the algorithm is proportional to the logarithm of the input size 
// algorithm continually gets faster as it halves input each round, as it has less input to process 
// BINARY SEARCH - ITERATION EXAMPLE - DIVIDE AND CONQUER 
int BinarySearch(int A[], int n, int x)
{
    int low = 0, high = n-1;

    while(low <= high) // ends program when the expression is false meanng "low > high" 
    {
        int mid = (low+high)/2;
        if(x == A[mid]) return mid;

        else if(x < A[mid]) high = mid-1;
        
        else low = mid+1; 
        
    }
    return -1; 
}

int main()
{
    int A[]={11, 22, 33, 44, 55, 66, 77, 88};

    printf("enter a number \n");
    int x; scanf("%d", &x);

    int index = BinarySearch(A, 8, x);

    if(index != -1) printf("Number %d is at index %d", x, index);
    else printf("number %d not found \n", x); 
}
*/

/*
//FASTEST METHOD!!! AND MOST USEFUL - O(log n) -LOGARITHM
// O(log n) - keep halfing array until you left with 1 element // based multiplication 
// log is for logarithmic - to the power using base 2 and exponents
// the time it takes to run the algorithm is proportional to the logarithm of the input size 
// algorithm continually gets faster as it halves input each round, as it has less input to process 
// BINARY SEARCH - RECURSION EXAMPLE - DIVIDE AND CONQUER 
int BinarySearch(int A[], int low, int high, int x)
{
    
    printf("BINARY SEARCH -------------------------------------------------- \n");

    if(low > high) // base condition 
    {
        printf("not valid \n");
        return -1; 
    }

    int mid = (low+high)/2;
    printf("AFTER low = %d --- high = %d and mid = %d \n", low, high, mid);
    
    if(x == A[mid])
    {
        printf("matched up \n");
        return mid; // base condition
    } 

    else if(x < A[mid])
    {
        printf("%d is less than %d \n", x, A[mid]); 
        printf("A = %d --- low= %d --- mid-1 = %d --- x = %d \n", A, low, mid-1, x);
        return BinarySearch(A, low, mid-1, x);
    }    
    else
    {
        printf("%d is greater than %d \n", x, A[mid]);
        printf("A = %d --- mid+1= %d --- high = %d --- x = %d \n", A, mid+1, high, x);
        return BinarySearch(A, mid+1, high, x); 
    } 
}

int main()
{
    int A[]={2, 6, 13, 21, 36, 47, 63, 81, 97};

    printf("enter a number \n");
    int x; scanf("%d", &x);

    int index = BinarySearch(A, 0, 8, x);

    if(index != -1) printf("Number %d is at index %d", x, index);
    else printf("number %d not found \n", x); 
}
*/

/*
//Fibonacci Series using Recursion // the greate the number, the slower the response 
#include<stdio.h>
int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n-1) + fib(n-2);
}
 
int main ()
{
  int n;
  printf("enter number \n ");
  scanf("%d", &n);
  printf("%d", fib(n));
  getchar();
  return 0;
}
*/