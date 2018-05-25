/* send data from program to file pointer from multiple functions  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct football
{
    char* name;
    int age;
    float weight; 
    FILE* player;
}details; 

void fileCreator(details* i);
void gymInput(details* i);
void happy(details* i);

int main()
{

    details love;
    details* pDetails; 
    pDetails = &love; 

    pDetails -> name = (char*) malloc(30* sizeof(char));
    if(pDetails == NULL)
    {
        printf("memory not allocated \n");
    }
    else
    {
        printf("memory allocated \n");
    }

    fileCreator(pDetails); 
    gymInput(pDetails);
    happy(pDetails);
}

void fileCreator(details* i)
{
    i->player = fopen("love.txt", "w"); // name of file and "w" writting input in
    if (i->player == NULL) 
    {
        printf("File does not exists \n");
        return;
    }
    fprintf(i->player,"Welcome to non-volatile data file \n");
}

void gymInput(details* i)
{

    printf("Please enter your age\n");
    scanf("%d", &i->age);

    printf("enter your weight \n");
    scanf("%f", &i->weight);

    fprintf(i->player,"age = %d \n", i->age);
    fprintf(i->player, "weight = %.2f \n", i->weight);

}

void happy(details* i)
{
    printf("Please enter your favourite team \n");
    fflush(stdin);
    fgets(i->name, 64, stdin);
    fprintf(i->player,"favourite team = %s \n", i->name);
}
