#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <argumento>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "exitoso") == 0) {
        return 0;
    } else {
        return 1;
    }
}
