/* Calculating your basal metabolic rate */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// struct - is a block data type in memory: used to group a bunch of variables which can be different types 
// all the variables/members of the struct can be accessed via single pointer 
// no memory is allocated so no harm on using it globally - usually put struct in different header file 
typedef struct basalMetabolicRate
{
    char* name;
    char* gender;
    float age;
    float weight;
    float height;
    float bmrTotal;
}bmr;

// function declarations 
void userInput(bmr *i); // passing struct as pointer
void results(bmr *i); // passing struct as pointer
void introduction();
void delay(float timeDelay);

int main()
{
    bmr calorieCounter; // naming the struct calorieCounter to be accessed in this function
    bmr *pCalorieCounter, *pGenderChoice; // setting pointer variables to struct
    pCalorieCounter = &calorieCounter; // assigning pointer variables 
    pGenderChoice = &calorieCounter;  // assigning pointer varaible 

    // creating dynamic memory for name 
    pCalorieCounter -> name = (char*) malloc(30* sizeof(char));
    if(pCalorieCounter == NULL)
    {
        printf("memory NOT allocated \n");
        exit(-1);
    }
    else
    {
        printf("memory has been allocated for NAME \n");
    }
    
    // creating dynamic memory for gender 
    pGenderChoice -> gender = (char*) malloc(30* sizeof(char));
    if(pGenderChoice == NULL)
    {
        printf("memory NOT allocated \n");
        exit(-1);
    }
    else
    {
        printf("memory has been allocated for GENDER \n");
    }
    
    introduction(); // calling function

    userInput(pCalorieCounter); // calling function and passing pointer varaible 
    
    delay(1.5); // calling function

    results(pCalorieCounter); // calling function and passing pointer varaible 

    free(pCalorieCounter->name); // free the memory so it can be used by other software
    pCalorieCounter->name = NULL; // making sure its free

    free(pGenderChoice->gender); // free the memory so it can be used by other software 
    pGenderChoice->gender = NULL; // making sure its free

}

/* 
Gets user input: name, gender, age, height and weight. 
Checks if user input is valid
*/
void userInput(bmr *i) // takes in pointer variable 
{
    printf("Please enter your name \n");
    gets(i->name);
    
    SEX: //GOTO
    printf("please enter your gender 'm' for male and 'f' for female \n");
    gets(i->gender);

    if( (strcmp(i->gender, "m") == 0) ) // checks if 'm' is entered
    {
        printf("valid input \n"); 
    }
    else if ( (strcmp(i->gender, "f") == 0) ) // checks if 'f' is entered
    {
        printf("valid input \n"); 
    }
    else // if 'm' or 'f' is not entered repeat loop
    {
        printf("invalid input \n");
        goto SEX; 
    }
    
    char userAge[64]; // local variable 
    i->age = 0; // assigning varaible 
    while(i->age == 0) // keep looping until this is not true 
    {
        printf("Please enter your age \n");
        fgets(userAge, 63, stdin); // stores data in userAge and makes sure the specifed char size does not overflow (prevents buffer errors)
        // puts the value in userAge in i->age via float
        if(sscanf(userAge, "%f", &i->age) != 1) // "!= 1" checks if number has been entered 
        {
            printf("invalid input \n");
            continue; // go back to the start of loop
        }
        printf("Number OK:%.2f\n", i->age);
    }

    char userHeight[64];
    i->height = 0;
    while(i->height == 0)
    {
        printf("Please enter your height \n");
        //scanf("%f", &i->height);
        fgets(userHeight, 63, stdin);
        if(sscanf(userHeight, "%f", &i->height) != 1)
        {
            printf("invalid input \n");
            continue;
        }
        printf("Number OK: %.2f \n", i->height); 
    }

    char userWeight[64];
    i->weight = 0;
    while(i->weight == 0)
    {
        printf("Please enter your weight \n");
        //scanf("%f", &i->weight);
        fgets(userWeight, 63, stdin);
        if(sscanf(userWeight, "%f", &i->weight) != 1)
        {
           printf("invalid input \n");
           continue; 
        }
        printf("Number OK: %.2f \n", i->weight);
    }

}

// uses the input from "userInput" and calculates an output for BMR 
void results(bmr *i)
{
    printf("\n");
    printf(" \t Name = %s \n", i->name);
    printf(" \t Age = %.2f \n", i->age);
    printf(" \t Height = %.2f \n", i->height);
    printf(" \t Weigtht = %.2f \n", i->weight);
    printf(" \t Gender = %s \n", i->gender);

      if(strcmp(i->gender, "m") == 0) // if user is male do this 
    {
        // bmr calculation for males
        printf(" \t you are male \n");
        i->bmrTotal = 66.5 + ( 13.75 * i->weight ) + (5.003 * i->height) - (6.755 * i->age);
    }
    else if (strcmp(i->gender, "f") == 0) // if user is female do this 
    {
        // bmr calculation for females 
        printf(" \t you are female \n");
        i->bmrTotal = 655.1 + ( 9.563 * i->weight ) + (1.850 * i->height) - (4.676 * i->age);
    }
    else
    {
        printf("invalid input - please enter 'm' for male and 'f' for female \n");
    }
    
    printf(" \t your bmr is = %.2f \n", ceil(i->bmrTotal)); // prints BMR RESULT 

}

/* Introducing the program */
void introduction()
{
    // Gets the current time and displays
    time_t currentTime;
    time(&currentTime); 
    printf("\n");
    printf("The current date and time: %s", ctime(&currentTime));

    printf("*** This is a software built to calculate BASAL METABOLIC RATE *** \n\n");
}

/* TIME DELAY BETWEEN FUNCTIONS */
void delay(float timeDelay)
{
    // The time between the previous function and the next upcoming function 
    clock_t start = 0;
    start = clock();
    // whatever number entered in the function parameters (t) * 1000 millieseconds - that is the delay
    while((clock()-start) < (timeDelay*1000));

    return; 
}
