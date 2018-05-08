#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations 
void introduction();
void delay(float t);
void board(); 

void human_vs_computer(char * h, int lev); // pointer variable to playerName (char * h) and takes the number stored in lev (1 or 2)

// global = Two dimensional array that can hold 9 elements 
char move[3][3];

int main()
{
    introduction(); // calling the function
    delay(1.8);
    //system("cls"); // clears the output screen of the program - to keep things tidy on CMD

    char p_again = 'A'; // local variable to main whihc controls the while loop below
    
    while(1) // (1) runs the loop infinitely 
    {
        int i, j, k = 49; // has to be 49 because in the ASCII TABLE decimal 49 =  char 1 to decimal 57 = char 9 
        for(i = 0;  i < 3; i++) // assigning values in the boxes 0 - 9 in userface of the game  
        {
            for(j = 0; j < 3; j++)
            {
                // puts the number from two dimensional array in position for userface 
                move[i][j] = k; // only takes 9 elements so it gets 1 to 9 from ASCII 
                k++; // increment by one in order to move to the next char in the ASCII: 49 = 1, 50 = 2, ect..
            }
        }
        char against; // local variable which stores user input
        if(p_again != 'y') // input will be asked first time
        {
            delay(1.2);
            printf("\n* Whom do you want to play against?\n");
            delay(0.8);
            printf("Press-\t1.against computer\n");
            delay(0.5);
            printf("\t2.against human.\n");
            delay(0.5);
            printf("Selection- ");
            fflush(stdin); // clear out standard input which stops the next scanf being missed out
            scanf("%c", &against);
            //fflush(stdin); // clear out standard input which stops the next scanf being missed out
            printf("\n");
            
            // if 1 or 2 is not entered do this - and repeats loop
            //if(against>2 || against<1) printf("\n**Wrong input!\a\n**Try again.\n"); 
        }
        // if user enters '1' to PLAY AGAINST COMPUTER do this 
        // this gets 49 in decimal when put this into %c ASCII it stands for '1' 
        if(against-48 == 1)
        {
            // local variable to store an 8 character array of player name 
            char playerName[8];
            // pointer variable 
            //char * namesArray;
            if(p_again != 'y')
            {
               printf("* Enter your name: ");
               scanf("%s", &playerName);
               //namesArray = (char*) malloc(playerName * sizeof(char)); // gets memory from heap accordingly to the amount of user input 
               //gets(p);
               //printf("Player name = %s", playerName); //crashes program 
               printf("Your symbol is 'X'.\n");
               delay(0.5);
               printf("\nComputer's symbol is 'O'.\n");
               delay(0.9);
            }
            int lev;
            if(p_again !='y')
                
                // keeps looping until user enters valid input 
                while(1)
                {
                    printf("\n* What should be computer's level?\n");
                    delay(0.5);
                    printf("* Press 1(normal) or 2(advanced): ");
                    char ch;  //this technique prevents program crush when error is input
                    fflush(stdin); // clear out standard input which stops the next scanf being missed out
                    scanf("%c", &ch); // stores user input in 'ch' user input will either be 1 or 2 
                    lev=ch-48; // setting lev: ch = 1 - 48 = decimal 49 in char ASCII '1' || ch = 2 - 48 = decimal 50 in char ASCII '2'
                    
                    // if 1 or 2 is not entered do this - and repeats loop
                    if(lev>2 || lev<1) printf("\n**Wrong input!\a\n**Try again.\n"); 
                    else break;
                }
                // passing the playerName and which level of computer they want to play against 
            human_vs_computer(playerName, lev); 
        }

    } // first while loop end
} // main end 

// This function is only called if user inputs '1' to play against computer otherise its never called 
void human_vs_computer(char * h, int lev)
{
    int p;

    while(1)
    {
        delay(0.4);
        printf("\n* Who will give first move?\n");
        delay(0.5);
        printf("* Press 1(human) or 2(computer): ");
        char ch;  //this technique prevents program crush when error is input
        fflush(stdin);
        scanf("%c", &ch); // ch stores user input 
        p=ch-48;
        
        // if 1 or 2 is not entered do this - and repeats loop until it is 
        if(p>2 || p<1) printf("\n**Wrong input!\a\n**Try again.\n");
        else break;
    }

    int sel;  //player's selection
    int i=0;
    while(i<9)  //the loop will give at most 9 chances
    {
        // clears the screen and and prepares screen for the game to begin 
        system("cls");  //this action makes a still screen
        // screen is cleared and shows what is below here 
        introduction();
        printf("\n##**HUMAN vs. COMPUTER\n\n");
    } 
}

//Functions 
void introduction()
{
    // Gets the current time and displays
    time_t currentTime;
    time(&currentTime); 
    printf("%s \n", ctime(&currentTime));
    
    // prints out what the game is about 
    printf("***This game is called Tic Tac Toe or also known as noughts and crosses*** \n");
    printf("--- You can either play against a friend or the computer --- \n \n \n");

    return;
}

void delay(float t)
{
    // The time between the previous function and the next upcoming function 
    clock_t start = 0;
    start = clock();
    // whatever number entered in the function parameters (t) * 1000 millieseconds - that is the delay
    while((clock()-start) < (t*1000));

    return; 
}