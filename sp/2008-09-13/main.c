//
// Created by Hakan Halil on 20.08.20.
//

#include <zconf.h>
#include <fcntl.h>

int main() {
    int filed, i;
    filed = creat( "exam_txt", 0777 );

    // stdin 0
    // stdout 1
    // stderr 2

    // closing stdout
    close(1);

    // replacing stdout with exam_txt file
    // since dup chooses first free fd --> 1
    i = dup(filed);

    // write will now redirect to fd 1 --> exam_txt
    write(i,"TEST \n",sizeof("TEST \n"));
    write(1,"TEST \n",sizeof("TEST \n"));

    // exam_txt file must have 2 occurrences of TEST

    // exam_txt:
    // TEST
    // TEST
    //
}