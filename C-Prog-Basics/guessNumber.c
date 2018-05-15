/* number guessing game 0 - 20 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    // local variables to main
    int i;
    int guess = 0;
    int numberOfGuesses = 5;
    int randomNumber = 0;
    // ensures random number is generated each time 
    time_t t;
    srand((unsigned) time(&t));

    //Game rules
    printf("--- GUESS THE NUMBER BETWEEN 0 - 20 \n");
    printf("You get %d attempts\n\n", numberOfGuesses);

    //Get Random Number
    randomNumber = rand() % 21;
    printf("The random number = %d\n\n", randomNumber);

    // Loops 5 times until i is not less than numberOfGuesses
    for(i = 0; i < numberOfGuesses; i++)
    {
        // goto keyword 
        GUESS:
        //Take user input and store in guess variable
        printf("Guess the number - this is %d out of %d attempt \n", i+1, numberOfGuesses);
        scanf("%d", &guess);

        // validation - checks if number are between 0 - 20
        if( (guess < 0) || (guess > 20))
        {
            printf("You need to enter a number between 0 to 20 \n");
            // if incorrect number is entered ask question again 
            goto GUESS;
        } 
        // user guess is lower than random number do this
        else if (guess < randomNumber)
        {
            printf("Your guess is too low \n");
        }
        // user guess is higher than random number
        else if (guess > randomNumber)
        {
            printf("Your guess is too high \n"); 
        } 
        // user guess is correct
        else
        {
            printf("CONGRATULATIONS! You entered the correct answer after %d attempts \n", i+1);
            break;
        }
        
        // ONLY prints if you get all 5 attempts wrong
        if( (i+1 == numberOfGuesses && guess < randomNumber) || (i+1 == 5 && numberOfGuesses > randomNumber))
        {
            printf("Unlucky you got all 5 attemps wrong - the correct answer is %d\n", randomNumber); 
        }
    }
    return 0;
}