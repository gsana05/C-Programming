/* Program which calculates pointer per average which is depending on user input. As well as a function to convert fahrenheit into celsisus */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function declarations 
void numberAveraging(int* appearances, int* goals, float* ppg);
float tempConverting(float* fahrenheitInput, float* celsiusConversion);
void delay(float timeDelay);
void introduction(); 

int main () 
{
    // local varibles to main
    int appearances;
    int goals;
    float ppg;
    char name[30];
    float bestPPG = 0.0;
    char bestPlayer[30];
    char exitLoop;
    int loopCount = 1;
    char whatToDo;
    
    introduction();

    while(1) // the main while loop that contains everything 
    {
        printf("Enter 1 = PLAYER PPG || Enter 2 = FAHRENHEIT TO CELSIUS CONVERSION || Enter 3 = EXIT PROGRAM  \n");
        scanf("%c", &whatToDo);
        if(whatToDo - 48 == 1) // if user enters '1' this if starts 
        {       
            while(1) // while loop for finding PLAYER PPG 
            {
                printf("Enter the name of player number %d \n", loopCount); // tracks the number of loops 
                printf("Enter name (max of 30 characters): ");
                fflush(stdin); // makes sure the gets(name) is NOT MISSED OUT ON THE LOOPS  //clears out standard input
                gets(name);     //Function to read string from user.
                printf("Welcome %s \n", name); // puts(name); 

                numberAveraging(&appearances, &goals, &ppg); // calling a function and passing pointers as arguments
                printf("Player: %s \t Games Played = %d \t Goals Scored = %d \t \t PPG = %.2f \n", name, appearances, goals, ppg);   

                    // GETS THE BESTPPG
                    if(ppg > bestPPG) // only do this if the new ppg is greater than the current bestPPG
                    {
                        bestPPG = ppg; // putsthe highest ppg into bestPPG 
                        strncpy(bestPlayer, name, 30); // gets the name (string) of player with best ppg and puts it into bestPlayer 
                    }
                
                        
                        printf("\n"); // prints out name and ppg of the best player 
                        printf("%s has the best PPG with = %.2f \n \n", bestPlayer, bestPPG );
                    
                        LOOP: // GOTO - if invalid input is entered 
                        printf("hit 'y' if you want add another player or press 'n' to exit if you're finished \n");
                        scanf("%c", &exitLoop); // takes user input and stores in variable 

                        if(exitLoop == 'y') // enter y do this 
                        {
                            printf("continue with loop \n");
                            fflush(stdin); // clear out standard input which stops the next scanf being missed out
                            loopCount++; // increment loopCount 
                            continue; // goes back to the start of inner while loop - PPG WHILE LOOP
                        }
                        else if (exitLoop == 'n') // enter n do this
                        {
                            printf("leave the loop \n");
                            printf("%s has the best PPG with = %.2f \n \n", bestPlayer, bestPPG );
                            break; // exits inner while loop 
                        }
                        else // enter anything else than invalid 
                        {
                            printf("incorrect input. try again \n");
                            fflush(stdin); // clear out standard input which stops the next scanf being missed out
                            goto LOOP; // GOTO
                        }  
                        
                    }
        fflush(stdin); // clear out standard input which stops the next scanf being missed out
        continue; // goes back to the start of inner while loop - MAIN WHILE LOOP 
        }
        else if(whatToDo - 48 == 2) // if user enters 2 do this
        {
            // local variables 
            float fahrenheitInput;
            float celsius;
            char leaveOrStay;
            
            while(1)
            {
                tempConverting(&fahrenheitInput, &celsius); // calling function with pointer addresses
                printf("fahrenheit you entered = %.2f converted into celsius = %.2f \n", fahrenheitInput, celsius); 
                fflush(stdin);// clear out standard input which stops the next scanf being missed out
                
                CONVERT_LOOP: //GOTO
                printf("press 'y' to convert another || press 'n' to exit \n");
                scanf("%c", &leaveOrStay); // stores user input in variable 

                if(leaveOrStay == 'y') // user enters 'y' do this
                {
                    printf("Lets convert another fahrenheit to calsius \n"); 
                    continue; // goes back to the start of inner while loop - MAIN WHILE LOOP 
                }
                else if(leaveOrStay == 'n') // user enters 'n' do this 
                {
                    printf("Exit temprature conversion loop \n");
                    fflush(stdin); // clear out standard input which stops the first man printf being printed twice
                    break; 
                }
                else // invalid input by user
                {
                    printf("invalid input, Please enter 'y' or 'n' \n");
                    fflush(stdin); // clear out standard input which stops printf under converloop being printed twice
                    goto CONVERT_LOOP;// GOTO
                }
            }
        }
        else if(whatToDo - 48 == 3)
        {
            printf("Program ends \n");
            delay(1.0);
            printf("\t .\a"); 
            delay(1.0);
            printf("\t .\a"); 
            delay(1.0);
            printf("\t .\a \n"); 
            printf("Thank you for using the program, goodbye for now \n"); 
            break;
        }
        else 
        {
            printf("invalid input \n");
            fflush(stdin); // clear out standard input which stops the next scanf being missed out
            continue; // goes back to the start of inner while loop - MAIN WHILE LOOP 
        } 
    }
}

/* GETS THE NUMBER OF GAMES PLAYED AND GOALS SCORED TO FIND THE AVERAGE (PPG) */
void numberAveraging(int* appearances, int* goals, float* ppg)
{
    // local varibales 
    char userInputGames[64];
    char userInputGoals[64];
    int gamesPlayed = 0;
    int goalsScored = 0;
    int * pointerGamesPlayed;
    int * pointerGoalsScored; 
    
    while(gamesPlayed == 0) // keeps looping until gamesPlayed is no long equal to 0 
    {
        printf("Please enter the numbers of GAMES PLAYED: \n");	
		fgets(userInputGames, sizeof(userInputGames), stdin); // stores data in userInput and makes sure the specifed char size does not overflow (prevents buffer errors)
        
        // sscanf = puts the value in "userInputGames" as a "%d" into "goalsPlayed" 
		if( sscanf(userInputGames, "%d", &gamesPlayed) != 1) //checks if its a number "!=1"
        {
            // puts the value of "userInput" into "howMany" and checks if its a number "!=1"
			printf("Invalid input please enter a number g \n");
			continue; // if a number is not enetered ( meaning howMany is still 0) repeat the loop
        }
    }

    while(goalsScored == 0) // keeps looping until gamesScored is no long equal to 0 
    {
        printf("Please enter the number of GOALS SCORED \n");
        fgets(userInputGoals, sizeof(userInputGoals), stdin); // stores data in userInput and makes sure the specifed char size does not overflow (prevents buffer errors)
        
        // sscanf = puts the value in "userInputGoals" as a "%d" into "goalsScored" 
        if(sscanf(userInputGoals,"%d", &goalsScored) != 1) // checks if its a number "!=1"
        {
            printf("Invalid input buddy \n");
            continue; // if a number is not enetered ( meaning howMany is still 0) repeat the loop
        }
    }
    
    // putting the numbers from this function into pointers (dereferencing) so that MAIN function has access to them 
    *appearances = gamesPlayed;
    *goals = goalsScored;
    *ppg = (float)goalsScored / (float)gamesPlayed;
}

/* CONVERTING FAHRENHEIT TO CELSIUS */
float tempConverting(float* fahrenheitInput, float* celsiusConversion)
{
    // local variables 
    float enteredInput = 0.0;
    float celsius = 0.0;
    char userInputFahrenheit[64];
    
    while(enteredInput == 0) // keeps looping until enteredInput is no longer 0.0
    {
        printf("Please enter the fahrenheit you want converted \n");
        fflush(stdin); // clear out standard input 
        fgets(userInputFahrenheit, sizeof(userInputFahrenheit), stdin );  // puts value of one variable in another with max size 
        
        if(sscanf(userInputFahrenheit, "%f", &enteredInput) != 1) // checks a number has been entered 
        {
            printf("invalid input.Try again \n");
            continue; // while loop repeats until user enters a number 
        }
    }
    
    *fahrenheitInput = enteredInput; // putter the entered input in a pointer variable 
    *celsiusConversion = (enteredInput - 32 ) * 5/9; // calculation to convert fahrenheit to celsius and putting it in pointer
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

/* Introducing the program */
void introduction()
{
    // Gets the current time and displays
    time_t currentTime;
    time(&currentTime); 
    printf("\n");
    printf("The current date and time: %s", ctime(&currentTime));

    printf("*** This is a software app built to calculate PPG and convert Fahrenheit to celsius *** \n\n");
}










