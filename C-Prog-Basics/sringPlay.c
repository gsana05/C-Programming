#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char* name_1; 
    char* name_2;

    name_1 = malloc(30 * sizeof(char)); 
    name_2 = malloc(30* sizeof(char));

    printf("size of bytes = %d \n", sizeof(name_1));
    printf("size of bytes = %d \n", sizeof(name_2));

    printf("enter name 1 \n");
    gets(name_1);
    printf("name 1 = %s \n", name_1);
    printf("string length = %u \n", strlen(name_1)); 

    printf("\n \n");

    printf("enter name 2 \n");
    gets(name_2);
    printf("name 2 = %s \n", name_2);
    printf("string length = %u \n", strlen(name_2)); 

    int boolean = strncmp(name_1, name_2, 30);

    if(boolean == 0) // if the inputs are the same 
    {
        printf("same names \n");
        printf(" the same name gives = %i", boolean);
    }

}


