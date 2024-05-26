#include <stdio.h>
#include <unistd.h>

void key(){
    char *bash[] = {"/bin/sh", 0};
    execve(bash[0], bash, 0);
}

int main(){

    char a[8] = {0, };

    read(0, a, 24);

    return 0;
}