//
// Created by Hakan Halil on 21.08.20.
//

#include<stdio.h>
#include           <fcntl.h>
#include <zconf.h>
#include <sys/wait.h>

main( int argc, char * argv[]){
    int fdi, fdo, k,broi, i = 0 , status;
    char buff [ 40 ], c ;
    // fdi = 3
    if  (  ( fdi = open ("file.txt", O_RDWR ) ) == -1 ){
        printf ("\n Cannot open  \n" );  return 1;
    }
    // fdo = 4
    if  (  ( fdo= open (argv[1], O_CREAT| O_TRUNC| O_RDWR,  0666) ) == -1 ){
        printf ("\n Cannot open  \n" );  return 1;  }
    if ( fork( ) == 0 ){
        k=dup(1);
        // k is a copy of real stdout at 5 now
        close(1);
        dup(fdi);
        // fdi now becomes new stdout

        // buff now contains the content of file.txt
        // broi is 22 (23 if ends with newline, cannot understand from provided input)
        broi = read ( fdi , buff, 40 );
        // c=a
        c = buff[ i++];
        // i=1
        if  ( c <= '0' || c >= '9' ){
            // the new line case will be reached first, because broi is 22/23
            // buf[6] = '\n'
            while  ( buff [ i ++] != '\n' && i < broi )
                write ( 1, "*", 1 ); // i=1; i=2; i=3; i=4; i=5 --> 5 stars will be added to file.txt
            write ( 1, "\n", 1 ); // new line will be added to file.txt
            close(1);
            dup(k); // 1 is real stdout again
            write ( 1, buff, 3 ); // abc to stdout
            write ( fdo, buff, 10 ); // ff will have abcdef\n012
        }else{
            write( 1,  buff, broi );
            close(1);
            dup(k);
            write ( 1, "*\n", 2 );
        }
        lseek( fdo,0, 0);
        write ( fdo, "*\n", 2 ); // *\ncdef\n012 will be the new content of ff
        close ( fdi); close (fdo);
    }
    else {
        wait ( &status);
        close(1);
        dup(fdi);
        // fdi becomes new stdout

        // cdef is appended to file.txt
        execlp ("grep", "grep", "c", argv[1], 0 );
        execlp("wc", "wc", "-l", "ff" , 0 );
    }
}

// result:

// stdout:
// abc

// file.txt:
// abcdef
// 0123456789
// ABCD*****
// cdef

// ff:
// *
// cdef
// 012