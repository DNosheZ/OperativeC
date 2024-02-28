#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	printf("Proceso padre (pid:%d)\n", (int) getpid());
	int rc = fork();
	if (rc < 0){		
		printf("Fallo fork()\n");
	} else if(rc==0){
		printf("Proceso hijo (pid:%d)\n", (int) getpid());
	}else{
		printf("Proceso padre de (pid:%d)\n", rc);
	}
	return 0;
}