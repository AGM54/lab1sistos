#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int f = fork();
    if (f == 0) {
        execl("./hola", "hola", (char*)NULL);
    } else if (f > 0) {
        printf("Parent PID: %d\n", (int)getpid());
        wait(NULL);
        execl("./hola", "hola", (char*)NULL);
    } else { 
        printf("fork failed\n");
        return 1;
    }
    
    return 0;
}

