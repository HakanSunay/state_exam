//
// Created by Hakan Halil on 20.08.20.
//

#define LST "ls"

#include <stdio.h>
#include <zconf.h>
#include <sys/wait.h>

int main() {
    int  pid, k=5, status;

    printf("Stoinostta na k = %d;\n", k-2);
    // Stoinostta na k = 3;

    ++k;

    printf("Stoinostta na k = %d;\n", k);
    // Stoinostta na k = 6;

    execlp(LST,LST,0);
    // result of ls in cwd

    // NEVER REACHED
    if ((pid = fork()) == 0 ) {
        k++;
    }
    else {
        wait(&status);
        --k;
    }

    printf("Stoinostta na k = %d;\n", k);
}
