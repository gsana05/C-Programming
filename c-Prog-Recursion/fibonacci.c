#include <limits.h>  
#include <stdio.h>  
#include <math.h>
#include <string.h>

int fibo(int);
 
int main()
{
    int num;
    int result;
 
    printf("Enter the nth number in fibonacci series: ");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("Fibonacci of negative number is not possible.\n");
    }
    else
    {
        result = fibo(num);
        printf("The %d number in fibonacci series is %d\n", num, result);
    }
    return 0;
}
int fibo(int num)
{
    if (num < 2)
    {
        return num;
    }
    else
    {
        printf("num - 1 = %d --- num - 2 = %d \n", num - 1, num - 2);
        printf("%d --- \n", (num - 1 ) + (num - 2));
        return(fibo(num - 1) + fibo(num - 2));
    }
}
 



