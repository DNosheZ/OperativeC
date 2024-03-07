#include <stdio.h>
#include <unistd.h>
int main(){
    int fd[2];
    pid_t pid = fork();
    if (pipe(fd)<0){

    }
    if (pid == 0){
        printf("Hijo\n")
    }

    return 0;
}