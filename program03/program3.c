/*
 * Anthony Bahl
 * Homework Assignment 3
 * 10/3/2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char * argv[]) {
    const char * filename;          // name of file to read
    char name[] = "Anthony Bahl";   // My Name
    int cp[2];                      // integer array for the pipes
    int pid = 0;                    // process id of this proccess
    int i;                          // used as a for-loop control variable 
    char ch;                        // character read from the pipe
    clock_t start_t,    // Start Time
            end_t;      // End Time
    double total_t,     // Total Time CPU
            wall_t;     // Total Time Wall
/*********************************************************************/

    // Validate Arguments
    if (argc != 3) {  // not enough arguments

        printf("Usage: hw3 [number of forks] <filename>\n");

        return 1;

    } else if (atoi(argv[1]) != 1 && atoi(argv[1]) != 4) { // invalid number of forks
        
        printf("Usage: [number of forks] must be 1 or 4\n");

        return 1;
    }

    start_t = clock();      // get starting CPU clock time
    filename = argv[2];     // Store the file name that the user passed in
    
    // Print name
    printf("My name is %s\n\n", name );

    for ( i = 0; i < atoi(argv[1]); i++)
    {

        // Establish the pipe
        if (pipe(cp) < 0) {
            printf("Failed to establish pipe.\n");
            return 1;
        }

        // fork it
        pid = fork();
        if (pid == 0) { // Child Process

            close(1);       // close stout
            dup2(cp[1], 1); // move stdout to pipe of cp[1].
            close(0);       // close stdin
            close(cp[0]);   // close pipe in

            char str[2];    //create an empty string to store number
            sprintf(str, "%i", i);
            execl("maxmin", "maxmin", str, filename, (char *) 0);   // call maxmin program

        } else {    // Parent Process
            close(cp[1]);   // close pipe out
            while ( read(cp[0], &ch, 1) == 1)
            {
                printf("%c", ch);
            }
            printf("\n\n");
        }
    }

    end_t = clock();    // get ending CPU clock time
    total_t = (double) (end_t - start_t) / CLOCKS_PER_SEC;
    printf("Main CPU time %lf\n", total_t);

    return 0;
}