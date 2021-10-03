// CS 3100 Sep 28,2021
// Pipe is a buffer, a file, where you can write or read from it
// In order to create a pipe you call a function: pipe()
// it takes an array of two integers

// The example below shows a simple pipe
// A child process is created using fork
// The child process writes the variable value to the pipe.
// The parent process reads the value written to the pipe.
// Here, the read waits for something to be written to the pipe

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    //represents in and out of pipe
    // 0: you read from it
    // 1: you write to it
    int cp[2]; 

    pipe(cp);

    int id = fork();
    if(id == 0) // child
    {
        close(cp[0]); // Read is NOT done here
        int x = 33;
        write(cp[1], &x, sizeof(int));
        close(cp[1]); // Close the write end of pipe after writing.
        printf("\n I'm the child, I've sent some data.");
    }
    else
    {
        close(cp[1]); // Write is NOT done here
        int y;
        read(cp[0], &y, sizeof(int));
        close(cp[0]); // Close the read end of pipe after writing.

        printf("\n REceived value for y from the child: %d", y);
    }

    printf("\n DONE FOR THE DAY!\n");

    return 0;
}