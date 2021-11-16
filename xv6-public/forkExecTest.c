/* Anthony Bahl
 CS3100 - Fall 2021
 Assignment: Program 5 Assignment
 File: ForkExecTestt.c
 Usage: Generates output that will allow us to test our scheduler and see the results onthe screen.
 */
#include "types.h" //include all libraries that are necessary
#include "user.h"

// General Format to run should be forkExecTest [# to count to] <# of childre>
int main(int argc, char *argv[]){
    int numchi = 2;         // Number of Children to Fork, 2 by default
    char *args[4];          // name of prog, num to count, child num, {char *} 0
    int i;                  // for loop
    int pid;                // process id for forking
    char childnum[6];       // parameter for the child number

    if (argc < 2) {  // not enough arguments
        printf(1, "Usage: forkExecTest <# to count to> [# of childre]\n");
        exit();
    } else {
        //strcpy(args[1], argv[1]);   // Copy the count number to send to the child
        args[1] = argv[1];  // Copy the count number to send to the child
        if (argc == 3)
        {
            numchi = atoi(argv[2]); // get number of children if supplied
        }        
    }
    args[3] = (char *) 0;
    args[0] = "countingProgram";

    // Loop creating children
    for (i = 1; i <= numchi; i++)
    {
        strcpy(childnum, itoa(i));  // Copy the chars into an array
        args[2] = childnum;   // Set Child Number Argument to address of childnum
        pid = fork();
        if (pid == 0)
            exec("countingProgram", args); 
    }

    // Loop waiting for children
    for (i = 0; i <= numchi; i++)
    {
        wait();
    }
    

    exit();
}