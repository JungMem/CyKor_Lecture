// gcc -o fin fin.c -no-pie -fno-stack-protector -z execstack

#include<stdio.h>
#include<string.h>
#include<unistd.h>

void printMenu(){

    printf("\n-----Menu-----\n");
    printf("1. Print Buf\n");
    printf("2. Scan Buf\n");
    printf("3. Quit\n");
    printf("--------------\n");
    printf("> ");

    return;
}

void printBuf(char* buf){

    long idx;

    printf("Index: ");
    scanf("%ld", &idx);

    printf("Value: ");
    write(1, (buf+idx), sizeof(char));

    return;
}

void scanBuf(char* buf){

    long idx;

    printf("Index: ");
    scanf("%ld", &idx);

    printf("Value: ");
    read(0, (buf+idx), sizeof(char));

    return;
}

int main(void){
    
    int idx;
    char buf[0x30];

    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);

    while(1){

        printMenu();
        scanf("%d", &idx);

        switch(idx){
        case 1:
            printBuf(buf);
            break;

        case 2:
            scanBuf(buf);
            break;

        case 3:
            printf("Did you succeed?\n");
            return 0;

        default:
            printf("Wrong Input Value\n");
            break;
            
        }

    }

}