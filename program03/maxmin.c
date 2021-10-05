#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char * argv[]) {
    const char * filename;  // name of file to read
	FILE * ft;  // file handle for the file
	int pid,    // process id of this process
        cnum,   // child number
	    num,    // the number of integer values in the file
	    i,      // loop control variable for reading values
	    temp=0, // used to store each value read from the file
        min=-1,    // used to store the minimum value
        max=-1;    // used to store the maximum value
	long size;  // size in bytes of the input file
    clock_t start_t,    // Start Time
            end_t;      // End Time
    double total_t;    // Total Time
/*********************************************************************/

    // Validate Arguments
    if (argc != 3) {  // not enough arguments

        printf("Usage: maxmin <child number> <filename>\n");

        return 1;

    }
    
    start_t = clock();      // get starting CPU clock time
    cnum = atoi(argv[1]);   // Store the child # that the user passed in
    filename = argv[2];     // Store the file name that the user passed in

    ft = fopen(filename, "rb"); // Open file for reading (b maybe stands for binary?)

    if(ft){ // Make sure that the file successfully opened

        pid = getpid(); // Get Process ID and store it in our variable
        fseek(ft, 0, SEEK_END); // set the file position of the stream to the end of the file
        size = ftell(ft); // get file size by by using our location at the end of the file
        num = (int) size / (int) sizeof(int); // calculate the number of numbers in the document
        fseek(ft,0,SEEK_SET); // go back to the beginning of the file

        fread(&temp, sizeof(int),1,ft); // read the first number
        min = temp; // initialize min
        max = temp; // initialize max

        // loop through remaining values
        // (start at i = 1 since we already read first number)
        for ( i = 1; i < num; i++ )
        {
            fread(&temp,sizeof(int),1,ft);  // read number
            if (temp < min) // Update min if this number is smaller
            {
                min = temp;
            } else if (temp > max)  // Update max if this number is larger
            {
                max = temp;
            }
        }
        
        end_t = clock();    // get ending CPU clock time
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        printf("child #: %i | ", cnum);
        printf("pid: %i | ", pid);
        printf("min: %i | ", min);
        printf("max: %i | ", max);
        printf("CPU(sec): %f", total_t);
    }

    return 0;
}