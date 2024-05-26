//====================================
//Do you know sfp & function epilogue?
//====================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void problem_child(char *src)
{
	char buffer[60];
	strncpy(buffer, src, 61);
	printf("%s\n", buffer);
}

int main()
{
    char buf[100];

    read(0, buf, 100);

	problem_child(buf);

    return 0;
}
