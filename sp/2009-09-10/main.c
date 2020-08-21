//
// Created by Hakan Halil on 20.08.20.
//

#include <zconf.h>
#include <sys/wait.h>
#include "stdio.h"

main() {
    int i, pid, flag = 2, status;
    pid = fork();
    if ( pid ) { --flag; wait(&status); }
    else for ( i=1; i <= 2; i++ ) ++flag;
    ++flag;
    if  (flag == 3)  return --i;
    printf ( "flag = %d\n",flag);
}

// My guess for expected output:
// flag = 5
// flag = 2

// Real output:
// flag = 5
// flag = 2