//
// Created by Hakan Halil on 20.08.20.
//

#include <stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include <sys/wait.h>

int main( ) {
    int fd, n_byt, i = 0, status;
    char sline [ 40 ], c ;
    if ( fork( ) ) {
        // in father

        // waiting for any child to finish
        wait(&status);

        // will spill End_of_program to fd1/stdout
        execlp("echo", "echo", "End_of_program", 0); // #5 -> End_of_program
    } else {
        if ((fd = open("fileA.txt",O_RDONLY)) == -1 ) {
            printf ("\n Cannot open  \n" );
            return 1;
        }
        n_byt = read ( fd , sline, 20 );
        c = sline[i++];
        // c is first char in text, but i has become 1
        if  ( c >= 'a' && c <= 'z' ) {
            while( sline [ i ++] != '\n' && i < n_byt ) // #1 -> $$$$$$$$$
                write( 1, "$", 1 );
            write( 1, "\n", 1 ); // #2 -> '\n
        }
        while(  i < n_byt )
            write(1,&sline[i++],1); // #3 -> abcdefgh
        close(fd);
        execlp("wc", "wc", "-l","fileA.txt",0 ); // #4 -> 3 fileA.txt
    }
}
