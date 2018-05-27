#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct employee
{
    char* name;
    int age;
    FILE* pFile;
} emp;

void creatBinaryFolder(emp* i);
void employeeName(emp* i);
void employee_age(emp* i); 

int main()
{

    emp staff;
    emp* pStaff;
    pStaff = &staff;

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
    
    creatBinaryFolder(pStaff);
    employeeName(pStaff);
    employee_age(pStaff);

}

void creatBinaryFolder(emp* i)
{
    i->pFile = fopen("trials.bin", "w+");
    if(i->pFile == NULL)
    {
        printf("failed to open file for reading and writing \n");
    }
    else
    {
        printf("binary folder has been created \n");
    }
    
    
}

void employeeName(emp* i)
{
    printf("please enter your name \n");
    gets(i->name);
    printf("The name you entered = %s \n", i->name);

    fwrite(i->name, strlen(i->name) + 1, 1, i->pFile);
    rewind(i->pFile); 
    //fseek(i->pFile, 1, SEEK_SET);
    fread(i->name, strlen(i->name) + 1, 1, i->pFile);

    printf("after fread - The name you entered = %s \n", i->name);
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


    