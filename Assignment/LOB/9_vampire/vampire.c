#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char space[0x1000] = {0, };
char tmp;

int main()
{
    char buffer[40];

    tmp = ((int)(buffer+44) >> 8)&0xFF;
    read(0, space, 0x1000);

    if(space[0x999] == 0)
    {
        printf("Go away!!\n");
        exit(0);
    }

    strcpy(buffer, space);
    printf("%s\n", buffer);

    if(*(buffer+45) == tmp)
    {
        printf("stack retbayed you!\n");
        exit(0);
    }

    memset(space, 0, 0x1000);

    return 0;
}