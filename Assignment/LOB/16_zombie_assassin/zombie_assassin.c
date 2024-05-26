//====================================
//Do you know sfp & function epilogue?
//====================================
#include <stdio.h>
#include <stdlib.h>

char stack;

int main()
{
    char buffer[40];

    stack = (int)(buffer+44) >> 24;

    read(0, buffer, 48);
    
    if(*(buffer+47) == stack)
    {
            printf("stack retbayed you!\n");
            exit(0);
    }
    
    printf("%s\n", buffer);
    return 0;
}