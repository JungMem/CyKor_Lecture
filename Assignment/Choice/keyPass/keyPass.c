// gcc -o keyPass keyPass.c -no-pie -fno-stack-protector

#include<stdio.h>
#include<stdlib.h>

#define KEY 4294963046
#define PASSWORD 4250

void getShell(){

    system("/bin/sh");

}

void auth(unsigned int key){

    if(key == KEY){
        printf("Welcome!-!\n");
    }
    else{
        printf("You don't have chance to login!-!\n");
        exit(-1);
    }

}

int main(void){

    char password[0x10];
    long flag = 1;
    int block = 2;
    int key = 3;

    printf("Enter your key: ");
    scanf("%d", &key);

    auth(key);
    
    printf("Enter Password: ");
    scanf("%s", password);

    if(block != 2){

        printf("\n*****BOF Detected!-!*****\n");
        return -1;

    }

    if(flag == PASSWORD){

        printf("\nHello Admin!-!\n");
        printf("You deserve Shell\n");

        getShell();

    }
    else{

        printf("Hello User!-!₩n");
        printf("Bye~~\n");

    }

    return 0;

}