//
// Created by Hakan Halil on 21.08.20.
//

#include <unistd.h>
#include <string.h>

int main(void){
    char* buff = "Hello, world!\n";
    int p;
    if (fork() == 0)
        write(1, buff, strlen(buff)); // -> Hello, world! from child proc
    p = fork();
    write(1, buff, strlen(buff));
}

// My guess on hello world display count:
// 5

// Correct

// P -> F1
// P -> F2
// F1 -> F3

// P prints 1 time
// F2 prints 1 time
// F3 prints 1 time
// F1 prints 2 times
// total: 5