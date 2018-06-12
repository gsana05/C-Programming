#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

int main(){
    int i;
    const double PI = 3.1415926;
    double x, result, val; 

    srand((unsigned int)time(NULL));
    for (  i=0; i<10; i++){
        x = ((float)rand())/RAND_MAX;
        printf("%lf\n",x);

        val = 180.0 / PI;

        result = acos(x) * val;

        printf("The arc cosine of %lf is %lf degress \n", x, result); 


     }
    return 0;
}