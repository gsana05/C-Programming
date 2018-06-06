/* C program for Merge Sort */
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<conio.h>

// function declarations 
void splitting(int* userInput, int size); // divide
void mergeSort(int* userInput, int* L, int* R, int size); // conquer

int main()
{
    int howMany = 0;
    int* input; 
    int count = 1;
    int i, k;
    int arraySize;
    FILE* Binary_File; // file pointer to store data on computer 
    
    // creating binary file to write into 
    Binary_File = fopen("binary_merge.bin", "wb");
    if(Binary_File == NULL)
    {
        printf("binary file has NOT been created \n");
    }
    else
    {
        printf("binary file has been created \n");
    }
    
    // allocating dynamic memory for user "number" input 
    char* number; 
    number = (char*)malloc(30*sizeof(char)); // dynamic memory
    if(number == NULL) // checking if the memory has been allocated 
    {
        printf("memory has NOT been allocated \n");
    }
    else
    {
        printf("memory has been allocated \n");
    }

    while(howMany == 0) // takes in number of elements you want in the array and validates
    {
        printf("how many numbers do you want to sort \n");
        fgets(number, sizeof(number), stdin); 
        // moving number value into howMany by decimal 
        if(sscanf(number, "%d", &howMany) != 1) // "!= 1" checks if number has been entered 
        {
            printf("Invalid input - please enter a number \n");
            continue;
        }
       
    }
    printf("size of number = %d bytes \n", sizeof(number));  

    input = (int*)malloc(howMany*sizeof(int)); // dynamic memory allocation

    arraySize = sizeof(input)*howMany / sizeof(int); // show the amount of elemnts in the array 
    if(input == NULL) // check if dynamic memory has been allocated 
    {
        printf("memory has not been allocated \n");
    }
    else 
    {
        printf("memory has been allocated \n");
        printf("sizeof input = %d elements in array which is = %d bytes \n", arraySize, arraySize*sizeof(int));
    }
    
    char* userNumber;
    userNumber = (char*)malloc(30*sizeof(char)); // dynamic memory 
    if( userNumber == NULL) // checks if dynamic memory has been allocated 
    {
        printf("memory has NOT been allocated \n");
    }
    else
    {
        printf("memory has been allocated \n"); 
    }

    for (i = 0; i < howMany; i++) // user inouts the individual number elements in the array 
    {
        input[i] = 0;
        while(input[i] == 0)
        {
            printf("current value --- &input[%d] \n", input[i]);
            printf("enter %d element in the array - to stop putting numbers in press any character key  \n", count);
            fgets(userNumber, sizeof(userNumber), stdin); 
            if(sscanf(userNumber, "%d", &input[i]) != 1) // checks a number has been entered 
            {
                printf("invalid input - please enter a number \n");
                continue; 
            }
            printf("input OKAY \n");
            count++;
            //scanf("%d", &input[i]);
        }

        //printf(" loop number = %d \n", *(input)); 
    } 

    printf("press a character on keyboard to sort \n");
    getch(); // pasuses program until a character on key board is pressed 
    
    printf("\n \n \n");
    printf("entered unsorted elements \n");
    for(i = 0; i < howMany; i++)
    {
        printf("input[%d] = %d \t", i, input[i]); 

        fwrite(&input[i], sizeof(int), i, Binary_File); // writting data into binary 
        printf("BINARY input[%d] = %d \n", i, input[i]); 
        //rewind(Binary_File); // 
        if (fseek(Binary_File, 0, SEEK_SET) != 0) // check if FSEEK is working - points to beggining of file 
        {
            printf("FSEEK NOT WORKING \n");
        }
        else
        {
            printf("FSEEK IT WORKING \n");
        }

        fread(&input[i], sizeof(int), i, Binary_File); // read data from binary 
        
        printf("BINARY input[%d] = %d \n", i, input[i]); 
    }

    //getch(); // pauses program and exits when user presses any char on keyboard 

    printf("\n \n \n");

    splitting(input, arraySize); // calling function
    
    // Showing sorted array 
    printf("\n \n \n");
    printf("SORTED ELEMENTS \n");
    for(i = 0; i < howMany; i++)
    {
        printf("%d \t", input[i]);

        fwrite(&input[i], sizeof(int), i, Binary_File); // writting data into binary 
        printf("BINARY SORTED input[%d] = %d \n", i, input[i]); 
        // rewind doesn't return an integer indicating whether the operation has succeeded, whereas FSEEK does!
        // use FSEEK normally like in above loop
        rewind(Binary_File); 
        fread(&input[i], sizeof(int), i, Binary_File); // read data from binary 
        
        printf("BINARY SORTED input[%d] = %d \n", i, input[i]); 
    }


}

/* dividing elements in the array */
void splitting(int* userInput, int size)
{
    int* L;
    int* R;
    int i = 0;
    int mid = 0; 
    mid = size/2;

    printf("SPLITTING FUNCTION \n");
    printf("size of array = %d elements in the array \n", size);

    if(size < 2) // BASE CASE to end recursion - single array elements, its time to start merging
    {
        printf("return - only 1 element in array \n");
        return;
    }
    else
    {
        // LEFT & Right temp arrays to divide elements 
        L = (int*)malloc(sizeof(int)*mid); 
        R = (int*)malloc(sizeof(int)*(size-mid));
        
        // LEFT SIDE 
        for(i = 0; i < mid; i++)
        {
            L[i] = userInput[i]; 
            printf("LEFT <-- L[%d] -<-<-<- userInput[%d] \n", L[i], userInput[i]);
        }
        
        // RIGHT SIDE 
        for(i = mid; i < size; i++)
        {
            R[i-mid] = userInput[i]; // i-mid puts the right array to position 0 - because 'i' was incremented in above loop
            printf("RIGHT --> R[%d] = userInput[%d] \n", R[i-mid], userInput[i]);
        }
        
        printf("\n \n");
        printf("LEFT ARRAY \n");
        splitting(L, mid);

        printf("\n \n");
        printf("RIGHT ARRAY \n");
        splitting(R, size - mid);
        
        printf("\n \n");
        printf("MERGE SORT \n");
        mergeSort(userInput, L, R, size);


    }
    
}

// merging arrays in ascending order 
void mergeSort(int* userInput, int* L, int* R, int size)
{
    printf("WELCOME TO MERGE SORT \n");

    int i = 0;
    int j = 0;
    int k = 0;
    int mL, mR; 

    mL = size/2;
    mR = size - mL;
    printf("mL = %d \t mR = %d \n", mL, mR);

    while(i < mL && j < mR)
    {
        if(L[i] < R[j])
        {
            userInput[k] = L[i];
            printf("userInput[%d] = L[%d] \n", userInput[k], L[i]);
            i++; // moves to the next position in array 
        }
        else
        {
            userInput[k] = R[j];
            printf("userInput[%d] = R[%d] \n", userInput[k], R[j]);
            j++; // moves to the next position in array 
        }
        k++; // moves to the next position in array 
        printf("k++ = %d \n", k);
    }

    while(i < mL) // remainding numbers on the LEFT get added to end of array
    {
        userInput[k] = L[i];
        printf("userInput[%d] = L[%d] \n", userInput[k], L[i]);
        i++; // moves to the next position in array 
        printf("i++ = %d \n", i);
        k++; // moves to the next position in array 
        printf("k++ = %d \n", k);
    }

    while(j < mR) // remainding numbers on the LEFT get added to end of array
    {
        userInput[k] = R[j];
        printf("userInput[%d] = R[%d] \n", userInput[k], R[j]);
        j++; // moves to the next position in array 
        printf("j++ = %d \n", j);
        k++; // moves to the next position in array 
        printf("k++ = %d \n", k);
    }
}