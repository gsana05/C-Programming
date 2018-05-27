#include <stdio.h>
#include <stdlib.h>

void WriteBinFile(void)
{
    FILE *ptr; 
    unsigned char a[] = {0xFF}; 
    ptr = fopen("test.bin","wb"); 
    fwrite (a, sizeof(unsigned char), 1, ptr);
    fclose (ptr);
}

void ReadBinFile(void)
{
    static const size_t BufferSize = 17;
    int i;
    FILE *ptr;
    unsigned char buffer2[BufferSize];

    ptr = fopen("test.bin","rb");
    const size_t fileSize = fread(buffer2, sizeof(unsigned char), BufferSize, ptr);

    printf("File size = %d bytes\n", fileSize);
    printf("Size of each item in bytes = %d\n", sizeof(unsigned char));

    for(i = 0; i < (fileSize / sizeof(unsigned char)); i++)
    {
        printf("0x%x ", (int)buffer2[i]);
    }
    fclose (ptr);
}

int main (void)
{
    WriteBinFile();
    ReadBinFile();
    printf("\nPress enter to exit\n");
    return fgetc(stdin);
}