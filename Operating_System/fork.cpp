#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() {
    pid_t child = fork();
    if(child < 0) {
        printf("fork error\n");
    } else if(child == 0) {
        printf("I am child\n");
        execlp("/bin/ls", "ls", NULL);
        exit(0);
    } else {
        printf("I am parent, waiting for child, pid = %d\n", child);
        int wait_status;
        waitpid(child, &wait_status, 0);
        printf("child finished\n");
    }
}   