#include<stdio.h>

int main(void){

    unsigned int ch = 4294967295;

    printf("unsigned: %u %x\n", ch, ch);
    printf("signed: %d %x\n", ch, ch);

    return 0;

}
