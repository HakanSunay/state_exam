//
// Created by Hakan Halil on 20.08.20.
//

#include <zconf.h>
#include "stdio.h"

main(){
    int a=1000;
    if(fork()){
        a/=2;
        printf("\nValue of a = %d\n",a);
    }else{
        if(fork()){
            a*=2;
            printf("\nValue of a = %d\n",a);
            if(execlp("ls","‐l",0) == -1){
                a=a+2;
                printf("\nValue of a = %d\n",a);
            }
        }else{
            a+=2;
            printf("\nValue of a = %d\n",a);
        }
    }
    a++;
    printf("\nValue of a = %d\n",a);
}

// My guess (!!! ORDER IS UNKNOWN):
//
// Value of a = 500
// Value of a = 501
// Value of a = 2000
// <result of ls -l>
// Value of a = 1002
// Value of a = 1003


// Actual output:
// Matches guess, but not in the same order
