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
    FILE* filePointer; 
}bmr;

// struct to implement compound literals
typedef struct compoundLiteral
{
    int caloriesBurnt;
    int eatenCalories;
    int bmrSum;
}calories_in_and_out; 

// function declarations 
void userInput(bmr *i); // passing struct as pointer
void results(bmr *i, int* bmrSum); // passing struct as pointer // float* brmSum - returns value to main
void introduction();
void delay(float timeDelay);
void calorie_calculation_hardcode(calories_in_and_out health); // Compound literal function HARDCODE
void calorie_calculation_userinput(calories_in_and_out health_userinput); // Compound literal function USERINPUT
void fileCreator(bmr* i);

int main()
{

    bmr calorieCounter; // naming the struct calorieCounter to be accessed in this function
    bmr *pCalorieCounter, *pGenderChoice; // setting pointer variables to struct
    pCalorieCounter = &calorieCounter; // assigning pointer variables 
    pGenderChoice = &calorieCounter;  // assigning pointer varaible 

    // creating dynamic memory for name 
    pCalorieCounter -> name = (char*) malloc(30* sizeof(char)); // -> dereferencing a member in struct with a pointer
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

    fileCreator(pCalorieCounter);

    calorie_calculation_hardcode((calories_in_and_out){200, 400}); // calling Compound literal function

    userInput(pCalorieCounter); // calling function and passing pointer varaible 
    
    delay(1.5); // calling function
    
    int bmrSum; // getting the brm total so it can be accesses in main function
    results(pCalorieCounter, &bmrSum); // calling function and passing pointer varaible 
    printf("brmSum from main = %d \n", bmrSum); // getting the brm total so it can be accesses in main function

    int caloriesBurnt; // variable for compound literal
    int caloriesEaten; // variable for compound literal
    calorie_calculation_userinput( (calories_in_and_out){caloriesEaten, caloriesBurnt, bmrSum } ); // calling Compound literal function

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
    //(*i).age = 0; - this is how it would be dereferenced without "->"
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
void results(bmr *i, int* bmrSum) // float* brmSum - returns value to main function 
{
    printf("\n");
    printf(" \t Name = %s \n", i->name); // print to CMD 
    fprintf(i->filePointer, "Name    = %s\n", i->name); // printing to non-volatile file

    printf(" \t Age = %.2f \n", i->age); // print to CMD 
    fprintf(i->filePointer, "age    = %.2f\n", i->age); // printing to non-volatile file

    printf(" \t Height = %.2f \n", i->height); // print to CMD 
    fprintf(i->filePointer, "height   = %.2f \n", i->height); // printing to non-volatile file

    printf(" \t Weigtht = %.2f \n", i->weight); // print to CMD 
    fprintf(i->filePointer, "weight   = %.2f \n", i->weight); // printing to non-volatile file

    printf(" \t Gender = %s \n", i->gender); // print to CMD 
    fprintf(i->filePointer, "Gender = %s \n", i->gender); // printing to non-volatile file

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
    *bmrSum = ceil(i->bmrTotal); // putting bmrTotal in brmSum so main function has access 
    fprintf(i->filePointer, "Your BMR = %.2f \n", ceil(i->bmrTotal)); // printing to non-volatile file

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

/* HARDCODE FOR COMPOUND LITERAL - CALORIES EATEN AND BURNT */
void calorie_calculation_hardcode(calories_in_and_out health) // Compound literal function // taking in struct and assiging a name 
{
    printf("COMPOUND LITERAL: calories eaten = %d --- calories burnt = %d \n",
    health.eatenCalories, health.caloriesBurnt);
}

/* USERINPUT FOR COMPOUND LITERAL - CALORIES EATEN AND BURNT */
void calorie_calculation_userinput(calories_in_and_out health_userinput) // Compound literal function // taking in struct and assiging a name 
{

    printf("\n");
    printf("please enter the number of calories eaten today \n");
    scanf("%d", &health_userinput.eatenCalories);

    printf("please enter the number of calories burnt from exercise today \n");
    scanf("%d", &health_userinput.caloriesBurnt); 

    printf("COMPOUND LITERAL: BMR = %d --- calories burnt = %d --- calories eaten = %d \n",
    health_userinput.bmrSum, health_userinput.caloriesBurnt, health_userinput.eatenCalories);
    
    int caloriesBurnt; // local variables
    int calorieCount; // local variables 
    caloriesBurnt = health_userinput.bmrSum + health_userinput.caloriesBurnt;
    printf("calorie burnt for today (bmr + activity) = %d \n", caloriesBurnt);
    printf("calories eaten today = %d \n", health_userinput.eatenCalories);

    calorieCount = health_userinput.bmrSum + health_userinput.caloriesBurnt - health_userinput.eatenCalories;
    printf("calorie count (calories burnt - calories eaten) = %d \n", calorieCount);
    
    // calculating if you are in deficit, surplus or breakeven
    if((calorieCount > 1)) // deficit
    {
        printf("you are in a caloric deficit of = %d \n", calorieCount);
    }
    else if ((calorieCount < 0)) // surplus
    {
        printf(" you are in a caloric surplus of = %d \n", abs(calorieCount)); // abs stop it being a minus number
    }
    else
    {
        printf("you are at break even with = %d calories to spare \n", calorieCount);
    }
}

/* CREATING A FILE NON-VOLATILE DATA*/
void fileCreator(bmr* i)
{
    i->filePointer = fopen("trials.txt", "w"); // name of file and "w" writting input in
    if (i->filePointer == NULL) 
    {
        printf("File does not exists \n");
        return;
    }
    fprintf(i->filePointer,"Welcome to non-volatile data file \n");
}
