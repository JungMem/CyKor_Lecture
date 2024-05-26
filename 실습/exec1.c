#include<stdio.h>

int main(void){

    // 0x4d = ASCII "M"
    char tmp[8] = {0x4d, 0x4d, 0x4d, 0x4d, 0x4d, 0x4d, 0x4d, 0}; // $ebp-0x8
    char buf[8] = {0, };                                         // $ebp-0xc

    printf("tmp: %s\n", tmp);

    scanf("%s", buf);
    printf("%s", tmp);

    return 0;

}

