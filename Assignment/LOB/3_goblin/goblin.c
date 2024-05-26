#include <stdio.h>
#include <string.h>

int main()
{
    char dummy[16], buffer[16];
    gets(buffer);
    printf("%s\n", buffer);

    memset(buffer, 0, 16);

    return 0;
}