#include <stdio.h>
#include <fcntl.h>

main(int argc, char * argv[]) {
    int des1, des2, k, broi, i = 0, status;
    char buff[40], c;
    if ((des1 = open(argv[1], O_RDWR))== -1){
        printf("\n Cannot open  \n");exit(1);
    }
    if ((des2 = open(argv[2], O_CREAT |O_TRUNC |O_RDWR,0666)) == -1) {
        printf("\n Cannot open  \n");exit(1);
    }

    // des1 f1.txt
    // des2 f2.txt
    if (fork() == 0) {
        // buff will have: xyzabcd\n0123456789\nABC
        broi = read(des1, buff, 22);

        // stdout:
        // xyzabcd
        // 0
        write(1, buff, 10);


        k = dup(1);
        // k now has real stdout

        close(1);
        dup(des1);

        // des1 is the new stdout (f1.txt)
        c = buff[i++];
        // c = x
        // i = 1
        if (c <= '0' || c >= '9') {
            // buff[7] is \n
            // broi is 22
            // so while will terminate when i gets 7
            while (buff[i++] != '\n' && i < broi)
                write(1, "x", 1); // i=2; i=3; i=4; i=5; i=6; i=7; => 6 times x will be appended to f1.txt
            write(1, "\n", 1); // new line to f1.txt
            close(1);
            dup(k); // recover real stdout
            write(1, buff, 4); // stdout: xyza
            write(des2, buff, 12); // f2.txt: xyzabcd\n0123
        } else {
            write(1, buff, broi);
            close(1);
            dup(k);
            write(1, "x\n", 2);
        }
        lseek(des2, 0, 0); // point to beginning of f2.txt
        write(des2, "x\n", 2); // f2.txt becomes: x\nzabcd\n0123
        close(des1);
        close(des2);
    } else {
        wait( &status );
        close(1);
        dup(des1);
        // f1.txt becomes stdout

        // first 2 lines of f2.txt will be appended to f1.txt
        // x\nzabcd will b appended to f1.txt
        execlp("head", "head", "-2",argv[2],0);
        execlp("wc", "wc", "-l", argv[1], 0);
    }
    execlp("grep", "grep", "x", "f1.txt", 0);
    // only child will get here
    // stdout:
    // xyzabcd
    // ABCDxxxxxx
}

// Result:

// stdout:
// xyzabcd
// 0xyzaxyzabcd
// ABCDxxxxxx

// f1.txt:
// xyzabcd
// 012456789
// ABCDxxxxxx
// x
// zabcd

// f2.txt:
// x
// zabcd
// 0123

// Actual result: matches (with some single char diffs, but that is expected, because we cannot know if the last line of the input text has a newline or not)
