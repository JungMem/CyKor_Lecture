#include<stdio.h>

int main(void){

    setvbuf(stdout, 0, 2, 0);

    char buf[0x40] = {0,};

    printf("Hello! Enter Your Input: ");
    read(0, buf, 0x50);

    return 0;

}
