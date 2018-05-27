/* BINARY FILE */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct employee
{
    char* name;
    int age;
    FILE* pFile; // file pointer 
} emp;

// function declarations - passing in struct as pointer 
void creatBinaryFolder(emp* i);
void employeeName(emp* i);
void employee_age(emp* i); 

int main()
{
    // create a pointer to store the address of struct 
    emp staff;
    emp* pStaff;
    pStaff = &staff;
    
    // dynamic memory allocation 
    pStaff -> name = (char*)malloc(30* sizeof(char));
    if(pStaff == NULL)
    {
        printf("memory has NOT been allocated for char name \n");
        exit(0);
    }
    else
    {
        printf("memory has been allocated for char name \n");
    }
    
    // calling functions 
    creatBinaryFolder(pStaff);
    employeeName(pStaff);
    employee_age(pStaff);

}

// function to create file for writing and reading 
void creatBinaryFolder(emp* i)
{
    i->pFile = fopen("trials.bin", "w+"); // w+ write and read 
    if(i->pFile == NULL)
    {
        printf("failed to open file for reading and writing \n");
    }
    else
    {
        printf("binary folder has been created \n");
    }
    
    
}

// function to input user name and store in binary 
void employeeName(emp* i)
{
    printf("please enter your name \n");
    gets(i->name);
    printf("The name you entered = %s \n", i->name);

    fwrite(i->name, strlen(i->name) + 1, 1, i->pFile); // writes the name to pFile which is stored in binary 
    rewind(i->pFile); // read content again from beggining to print all characters 
    //fseek(i->pFile, 1, SEEK_SET); // picks out a position to start from --- SEEK_CUR and SEEK_END 
    fread(i->name, strlen(i->name) + 1, 1, i->pFile); // reading from binary 

    printf("after fread - The name you entered = %s \n", i->name); // printing out data stored in binary into text 
}


void employee_age(emp* i)
{
    printf("please enter your age \n");
    scanf("%d", &i->age);
    printf("entered age = %d \n", i->age);

    fwrite(&i->age, sizeof(int), 1, i->pFile);
    fread(&i->age, sizeof(int), 1, i->pFile);

    printf("after fread - entered age = %d \n", i->age);

}


    