#include <stdio.h>
#include <unistd.h>

int main(int argc, char *args[]){
	int fildes[2];
	if (pipe(fildes)<0){
		perror("Error al crear la tuberia\n");
		return(1);
	}
	if (fork()==0){
		int dato_entra=100;
		write(fildes[1], &dato_entra, sizeof(int));
		printf("Dato enviado por tuberia: %d\n", dato_entra);
	} else{
		int dato_sale;
		read(fildes[0], &dato_sale, sizeof(int));
		printf("Dato recibido por tuberia: %d\n", dato_sale);
	}
	close(fildes[0]);
	close(fildes[1]);
	return 0;
}