#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *args[]){
	const char mypipe[] = "/tmp/mypipe";
	

	if(mkfifo(mypipe, 0666)<0){
		if(errno != EEXIST) { 
            		perror("Error al crear la tubería");
            		return 1;
        	}else{
			printf("El programa continua ejecutandose....\n");
		}	
	}
	int fd = open(mypipe, O_RDONLY | O_WRONLY);
	int dato_entra = 200;
	write(fd, &dato_entra, sizeof(int));
}