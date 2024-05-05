#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <signal.h>
#include <string.h>


void bit0Handler();
void bit1Handler();
//Server
int main(int argc, char* argv[]){
    pid_t server_id = getpid();
    printf("Server id is: %d\n", server_id);
    char * clientText;
    int count = 0;

    signal(SIGUSR1, bit0Handler);
    signal(SIGUSR2, bit1Handler);

    while(1);
    return 0;
}

void rec(char bit) {
    static int count = 0;
    static char str = 0;
    str |= (bit << count);
    count++;
    if(count == 8) {
        printf("%c", str);
        fflush(stdout);
        count = 0;
        str = 0;
    }
    
}

void bit0Handler() {
    rec(0);
}


void bit1Handler() {
    rec(1);
}
