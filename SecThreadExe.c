#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void * funcion(void *arg){
    printf("Hilo %d \n", (int) pthread_self());
    pthread_exit(0);
}
int main(int argc, char *argv[]){
    int j;
    pthread_t hilos[10];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    
    for (j=0; j < 10; j++){
        pthread_create(&hilos[j], &attr, funcion, NULL);
    }
    sleep(5);

    printf("main() termina\n");
    return 0;
}