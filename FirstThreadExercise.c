#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void * funcion(void *arg){
    int id = (int) pthread_self();
    printf("Hilo %d\n", id);
    pthread_exit(0);
}

int main(int argc, char *argv[]){
    pthread_t h1, h2;
    pthread_create(&h1,NULL,funcion,NULL);
    pthread_create(&h2,NULL,funcion,NULL);

    printf("main() Sigue su ejecucion\n");
    printf("main() Sigue su ejecucion\n");
    printf("main() Sigue su ejecucion\n");

    pthread_join(h1,NULL);
    pthread_join(h2,NULL);

    printf("main() termina\n");
    return 0;
}