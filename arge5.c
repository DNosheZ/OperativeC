#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main(){
	pid_t pid;
	pid=fork();
	if (pid < 0){
		printf("Fallo fork()");
		return 1;
	}
	else if (pid == 0){
		execlp("/bin/ls","ls","-l",NULL);
	}
	else {
		wait(NULL);
		printf("Hijo termina\n");
	}
	return 0;
}
