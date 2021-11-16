/* Anthony Bahl
 CS3100 - Fall 2021
 Assignment: Program 5 Assignment
 File: countingProgram.c
 Usage: Counts to a specified number.
 */
#include "types.h" //include all libraries that are necessary
#include "user.h"

// General Format to run should be countingProgram [number to count to] [child number]
int main(int argc, char *argv[]){
    int count;      // Number to Count to
    int chinum;     // Number of Children to Fork
    int i;          // for loop

    if (argc < 2) {
        printf(1, "Usage: countingProgram <num to count> [child number]\n");
        exit();
    } else {
        count = atoi(argv[1]);  // get the number we are counting to.
        if (argc > 2) {
            chinum = atoi(argv[2]); // we recieved a child number to use.
        } else {
            chinum = 0; // default for the child is child number 0
        }        
    }

    // now loop and print out the count
    for (i = 1; i <= count; i++)
    {
        printf(1, "Child: %d\t Count: %d\n", chinum, i);
        sleep(10);
    }    

    exit();
}