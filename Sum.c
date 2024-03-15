#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

void sumar(int li, int ls){
	int j;
	int suma=0;
	for (j=li; j<=ls; j++){
		suma=suma+j;
	}
	sumaTotal=sumaTotal+suma;
}

int main(int argc, char *args[]){
	pid_t pid;
	pid=fork();
	if (pid < 0){
		printf("Fallo fork()");
		return 1;
	}
	else if (pid == 0){//Aqui se ingresa el proceso hijo
		sumar(1,50);
		
	}else {//Aqui se ingresa el proceso padre
		sumar(51,100);
	}
	return 0;
}