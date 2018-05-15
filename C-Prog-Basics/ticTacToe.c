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
        board();

          int pl; // local variable 
        char *name; // pointer variable 
        
        // changes player after each go - so they take it in turns to have a go 
        if( i % 2 == 0 ) // (9 loops) 0 - 8 % 2 = 0, 1, 0, 1, 0, 1, 0, 1, 0 // only enters if its equal to 0 
        {
            // ONLY if answer is 0 do this: MUST BE 0
            pl = p; // 'pl' holds the value of 'p' // p value is always 1 or 2 depending on who you choose whose turn is first above 
            printf("value of pl in IF the turns = %d \n", pl);
            delay(5.5);

        } 
        else
        {
            // any answer APART FROM 0 do this: MUST NOT BE 0 
            pl=3-p; 
            printf("value of pl in ELSE the turns = %d \n", pl);
            delay(5.5);

        } 

        // The results from the above if and else dictate this below if and else 
        if(pl==1) 
        {
            // name of player
            name=h; // *h is a pointer variable - holds the characters of players name and puts it into *name pointer (pointer to pointer)
        } 
        else
        {
            // name of computer 
            name="Computer"; // changing value wihin pointer variable 
        } 
        
        // prints out results 
        printf("## Player-%d: %s\n", pl, name);
        delay(5.35);

        i++; 
    } 
}

// the interface of the game 
void board()
{
    int i, j; // local variables 
    printf("\n\n");
    // loops 3 times - in order to display 9 spaces 
    for(i=0; i<3; i++)
    {
        // if there is an 'i' do this:
        if(i)
        {
            // shows the tic tac toe table by using characters from the ASCII SCHEME 
            printf("\n  %c%c%c%c%c%c", 196,196,196,197,196,196);
            printf("%c%c%c%c%c\n", 196,197,196,196,196);
        }
        printf("  "); // provides spacing between characters - to make interface look good
        // loops 3 ties to input numbers 1 - 9 in the spaces 
        for(j=0;j<3;j++)
        {
            printf(" %c ", move[i][j]); // displays the characters (1-9) in the spaces of the table above 
            if(j!=2) printf("%c", 179); // keeps the table characer inline for interface when char are added from move array 
        }
    }
    // creates space under the game table 
    printf("\n\n");
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