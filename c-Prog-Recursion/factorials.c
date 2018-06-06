/* FACTORIALS RECURSION vs ITERATION */
#include <stdio.h>
#include <time.h>

// RECURSION ---------------------------------------------------

// function declarations 
int factorials(int n);

int main()
{
    int n;
    int result;
    double ticks = clock(); 

    printf("Please enter a number \n");
    scanf("%d", &n);
    printf("number entered main = %d \n", n);

    result = factorials(n); // makes frames until n == 0 - once 0 it comes back up to calculate the frames for main

    printf("factorial of %d is = %d \n",n, result);

    printf("execution time = %lf \n", ticks/ CLOCKS_PER_SEC);

}

int factorials(int n)
{
    int result;

    printf("I am calculating = %d \n", n);

    if(n == 0) // BASE CASE - statement to end all recurisve calls - other wise recursion would be infinite 
    {
        result = 1;
    }
    else
    {
        result = n * factorials(n-1); // RECURSION - function that is calling itself 
        printf("DONE --- n = %d = %d \n", n, result);
    }
    return result;
}

// ITERATION ----------------------------------------------------

// Iterative function to find factorial of a number using for loop
/*
int factorial(int n)
{
	int fact = 1;
	int i;

	for (i = 1; i <= n; i++)
		fact = fact * i;

	return fact;
}

// main function
int main()
{
	int n;
    printf("enter a number \n");
    scanf("%d", &n);

	printf("The Factorial of %d is %lu", n, factorial(n));
	
	return 0;
}
*/
