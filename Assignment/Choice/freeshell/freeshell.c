// gcc -o freeshell freeshell.c -no-pie -fno-stack-protector -z execstack

#include<stdio.h>
#include<string.h>
#include<unistd.h>

void (*shellcode)(void);

void printMenu(){

    printf("\n-----Menu-----\n");
    printf("1. Load Shellcode\n");
    printf("2. Run Shellcode\n");
    printf("3. Quit\n");
    printf("--------------\n");
    printf("> ");

    return;

}

void loadShellcode(char* buf){

    char shellcode[] = 
        "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e"
        "\x89\xe3\x50\x53\x89\xe1\x31\xd2\xb0\x0b\xcd\x80";

    memcpy(buf, shellcode, sizeof(shellcode));

    return;

}

void runShellcode(char* buf){

    shellcode = (void (*)(void))buf;
    shellcode();

    return;

}

void loadMemory(char* buf){

    printf("Input Value: ");
    read(0, buf, 0x30);

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
            loadShellcode(buf);
            break;

        case 2:
            runShellcode(buf);
            break;

        case 3:
            printf("Bye~~\n");
            return 0;

        case 4:
            loadMemory(buf);
            break;

        default:
            printf("Wrong Input Value\n");
            break;
            
        }

    }

}