#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//void functions 
void diceGameLoop();
void results();

//Global Variables 
    int dr1, dr2, dr3;
    int drs1, drs2;
    int guess;
    int guess2;
    int count = 1;
    int score = 0;
    int loop = 0;

// main - called by operating system when user runs the program 
int main ()
{
    //Ensures random numbers are generated each loop
    srand(time(NULL));

// calling the functions 
    diceGameLoop();
    results();

    return 0;
} 

void diceGameLoop() {
    // loops until conditional is false 
    while(count <= 5 )
    {
        REPEAT:

        guess = 0;
        // produces the first 3 random numbers ranging from 1 to 6
        dr1 = (rand() % 6 ) + 1;
        dr2 = (rand() % 6 ) + 1;
        dr3 = (rand() % 6 ) + 1;
        // calculation of the 3 scores added - for DRS1
        drs1 = dr1 + dr2 + dr3;

        // Prints out the result of the 3 scores added 
        printf("The sum of the 3 dices added is %d\n\n", drs1);
        
        //Prints out the question 
        printf("Please enter if the next dice rolls will be higher (H), lower(L) or the same (S) as %d\n", drs1);
        // user input - which is stored in guess 
        scanf("%c", &guess);
        // stops the while loop from missing out questions 
        scanf("%c", &guess2);
        
        // checks if the user has entered the correct input - if so do this 
        if ((guess == 'h') || (guess == 'l') || (guess == 's')) {
        // produces the second 3 random numbers ranging from 1 to 6
        dr1 = (rand() % 6 ) + 1;
        dr2 = (rand() % 6 ) + 1;
        dr3 = (rand() % 6 ) + 1;
        // calculation of the 3 scores added - FOR DRS2 
        drs2 = dr1 + dr2 + dr3;
        } else {
            // if user has not entered the correct input do this - start again 
            printf("INVALID INPUT! Try Again \n");
            goto REPEAT;
        }
        
    
    // If you get the answer correct this happens
    if (guess == 'h' && drs2 > drs1) {
        printf("you are spot on %d is higher than %d\t", drs2, drs1);
        score++;
    } 
    else if (guess == 'l' && drs2 < drs1) {
        printf("you are spot on %d is lower than %d\t", drs2, drs1);
        score++;
    }
    else if (guess == 's' && drs2 == drs1) {
        printf("you are spot on %d are the same %d\t", drs2, drs1);
        score++;
    } 
    // if you get the answer wrong this happens 
    else {
        printf("That is wrong! You said %c which %d is not against %d \t", guess, drs2, drs1 );
    }
    //prints out your current score 
    printf("your current score is %d out of %d\n\n", score, count );
        count++;
    }
    return;  
}

// The results depending on your score
void results() {
    if(score <= 2 ) {
        printf("you suck\n");
    } else if (score >= 3 && score <= 4) {
        printf("Nice score\n");
    } else if ( score == 5) {
        printf("you are a wizard!!!\n");
    }
    return;
}