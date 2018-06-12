#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

void introduction();
void gameTime(int* startGame);
void questionTime(int* result);
void switchGrades();

int main()
{
  int startGame;
  int score;

  introduction();
  gameTime(&startGame);
  printf("number entered was = %d \n", startGame);
  //questionTime(&score);
  //printf("the score returned to main = %d \n", score);
  switchGrades();



  return 0;
}

void introduction()
{
    printf("Welcome to the Maths game! \n");
    printf("you have 10 questions to answer\n \n");
}

void gameTime(int* startGame)
{
    int start = 0;
    char userInput[64];
    
    while(start == 0)
    {
    
        printf("press '1' to begin || press any other number key to exit \n");
        fgets(userInput, sizeof(userInput), stdin); // stores data in userInput and makes sure the specifed char size does not overflow (prevents buffer errors)
        
        // sscanf = puts the value in "userInputGames" as a "%d" into "goalsPlayed" 
		if( sscanf(userInput, "%d", &start) != 1) //checks if its a number "!=1"
        {
            // puts the value of "userInput" into "howMany" and checks if its a number "!=1"
			printf("Invalid input please enter a number g \n");
			continue; // if a number is not enetered ( meaning howMany is still 0) repeat the loop
        }
        else if (atoi(userInput) == 1)
        {
            printf("LETS GO \n");
        }
        else
        {
            printf("GOOD BYE \n");
            exit(0); 
        }
    }
        
    *startGame = start;
}


void questionTime(int* result)
{
    //Ensures random numbers are generated each loop
    srand(time(NULL));

    int randNum_1;
    int randNum_2;
    int randTotal;
    int answer = 0;
    int i;
    int k = 0; 
    int score = 0;
    
    for(i = 0; i < 3; i++)
    {
        randNum_1 = (rand() % 10 ) + 1;
        printf("random number_1 = %d \n", randNum_1); 
        randNum_2 = (rand() % 10 ) + 1;
        printf("random number_2 = %d \n", randNum_2); 

        printf("what is %d + %d = ", randNum_1, randNum_2); 
        
        while(scanf("%d", &answer) == 0) // false is represented by 0 // keeps looping until a number is entered 
        {
            printf("invalid input - please enter a number \n");
            printf("what is %d + %d = ", randNum_1, randNum_2); 
            scanf("%*s");
            /* 
            %*s will instruct scanf to parse the input as though it's attempting to convert a string of characters
             (removing characters in the process from the stream), 
             but thanks to the asterisk, it won't attempt to write it anywhere.
            */
        }
               
        printf("the answer you entered = %d \n", answer);

        randTotal = randNum_1 + randNum_2;

        if(answer == randTotal)
        {
            printf("Excellent! You are right! \n");
            printf("%d + %d = %d \n", randNum_1, randNum_2, randTotal); 
            score++; 
        }
        else
        {
            printf("Unlucky! You are wrong! \n"); 
            printf("%d + %d = %d \n", randNum_1, randNum_2, randTotal); 
        }
    }
    printf("you currently have %d correct out of %d \n", score, i); 
    *result = score;
}

void switchGrades()
{
    int score;
    questionTime(&score);
    printf("the score returned to switchGrades= %d \n", score);

    switch(score)
    {
        case 0: printf("terrible score \n");
            break;
        case 1: printf("bad score \n");
            break;
        case 2: printf("OK score \n");
            break;
        case 3: printf("Good score \n");
            break;
        default: goto FAIL;
    }
    
        goto EXIT;
        FAIL:
        printf("Fail.\n");
        EXIT:
        return;
}
