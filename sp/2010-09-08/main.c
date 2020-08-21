//
// Created by Hakan Halil on 20.08.20.
//

#include <stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include <sys/wait.h>

main()   {
    int fdr, fdw, n_byt, i = 0 , status;
    char buff [40], c ;
    if (fork( ))      {
        wait (&status);
        if (open("file_new", 0) != -1)
            execlp("grep", "grep", "$", "file_new",0);
    }      else       {
        if ((fdr = open("fileB.txt",0))== -1)         {
            printf("\n Cannot open \n"); return 1;
        }
        if (( fdw = creat ("file_new",0666))== -1)         {
            printf ("\n Cannot creat \n"); return 1;
        }
        n_byt = read (fdr,buff,40);
        c = buff[i++];
        if (c <= '1' || c >= '9')         {
            while ( buff [i ++] != '\n' && i < n_byt)
                write( fdw, "$", 1 );
            write(fdw,"\n",1);
            write(1,"\n",1);
        }         else {
            write(1,buff,n_byt );
            write ( 1, "\n", 1 );
        }
        write (fdw, "$", 1);
        close (fdr);
        close (fdw);
    }
}
