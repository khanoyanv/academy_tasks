#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <signal.h>
#include <string.h>

//Client
int main(int argc, char * argv[]) {
    pid_t client_id = getpid();
    pid_t server_id = atoi(argv[2]);
    char * string = argv[1];
    printf("Server pid id: %d\n", server_id);

    int string_length = strlen(argv[1]);
    for(int i = 0; i < string_length; i++) {
        for(int j = 0; j < 8; j++) {
            if((string[i] >> j) & 1) {
                kill(server_id, SIGUSR2);
                usleep(100);
            } else {
                kill(server_id, SIGUSR1);
                usleep(100);
            }
        }
    }
}