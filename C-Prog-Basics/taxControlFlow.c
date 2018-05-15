/* calculate weekly pay */

#include <stdio.h>
#include <stdlib.h>

// PRE PROCESSOR TO CREATE CONSTANTS 
#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25

//Global variables 
int numberOfEmployees = 0;

// Gets user input and validates if a number is entered 
void howManyEmployees ()
{
    //local variables 
    char userInput[64];

    while (numberOfEmployees == 0) {
    // enter the number of employees you want to get weekly pay for 
    printf("Please enter the number of employess \n");
    // fills up "userInput" with user input  - // fgets = reads a file strings line by line 
    fgets(userInput, 64, stdin); 
    // sscanf = reads data from string ("userInput" in fgets) and passes this data into another string ("&numberOfEmployees") 
    // "!=1"  if userInput is not a number do this - if it is a number jump over this if statement 
    if( sscanf(userInput, "%d", &numberOfEmployees) != 1) { 
			printf("Invalid input please enter a number \n");
            // continue = jumps back to the beginning of the loop - until howMany != 0
			continue;
        }
    }
}

int main ()
{
    // local variables to MAIN FUNCTION 
    int i;
    char nameOfEmployee[50];
    double hoursWorked = 0.0;
    double weeklyPay = 0.0;
    double taxes = 0.0;
    double netPay = 0.0;
    
    // function call - for number of employees and validation a number is entered 
    howManyEmployees();
    
    // loops until i is not less than number of employees 
    for (i = 0; i < numberOfEmployees; i++){
    
        // enter the name of employee
        printf("Please enter the name of employee \n");
        scanf("%s", &nameOfEmployee); 
        
        // takes in user input and prints out
        printf("Please enter the number of hours you worked this week by %s \n", nameOfEmployee);
        scanf("%lf", &hoursWorked);
        printf("The amount of hours you worked = %.2lf \n", hoursWorked);

        // if work 40 or less hours do this
        if (hoursWorked <= 40)
        {
            // calculates weekly pay - hoursWorked x 12.00
            weeklyPay = hoursWorked * PAYRATE;
            // prints out result of weeklyPay 
            printf("40 OR LESS HOURS - the amount you get paid = $%.2lf \n", weeklyPay);
        }
        // ONLY do this if worked hour is greater than 40 
        else 
        {
            // calculates weekly pay for 40 hours
            weeklyPay = 40 * PAYRATE;
            // calculates overtime (over 40 hours) with the payrate of pay and a half (1.5)
            double overTimePay = (hoursWorked - 40) * (PAYRATE * 1.5);
            // adds weekly 40 hour pay ($12 an hour) and adds overtime hours over 40 ($18 an hour)
            weeklyPay += overTimePay;
            // prints out the sum of weekly pay from calculations above 
            printf("worked more than 40 hours = %.2lf  \n", weeklyPay);
        }

        // MR TAX MAN 
        // if you earn $300 or less 
        if( weeklyPay <= 300 )
        {
            // the amount tax that needs to be paid when earning 300 or less - tax 15%
            taxes = weeklyPay * TAXRATE_300;
        }
        // only get to this else if by earning more than $300 - 20% tax
        else if (weeklyPay <= 450)
        {
            // the amount of tax to be paid when earning 300 or less
            taxes = 300 * TAXRATE_300;
            // the amount of tax to be paid on earnings over 300 and under 450
            taxes += (weeklyPay - 300) * TAXRATE_150;
        }
        //only do this if you earn more than $450 - 25% tax
        else
        {
            // the amount of tax to be paid when earning 300 or less
            taxes = 300 * TAXRATE_300;
            // gets the current tax from 300 (above) and adds the tax from 300 to 450 that needs to be paid
            taxes += 150 * TAXRATE_150;
            // taxes the remaining money after taking away $450
            taxes += (weeklyPay - 450) * TAXRATE_REST;
        }

        // calculate netpay - the money you atually get 
        netPay = weeklyPay - taxes;

        // prints the outputs
        printf("This is the amount of gross pay you got = %.2lf \n ", weeklyPay);
        printf("This is the amount of tax you have paid = %.2f \n ", taxes);
        printf("This is your take home net pay total = %.2f \n \n", netPay);
    }

    return 0;

}