#include <stdio.h>
#include <stdlib.h>

int fn(int a, int b) {
    int dummy = 44;
    printf("\n a in fn is residing at: %p", &a);
    printf("\n b in fn is residing at: %p", &b);
    printf("\n dummy in fn is residing at: %p", &dummy);
    return(a+b);
}

int main(int argc, char* argv[]){

    int i = 35; // stack
    int j = 70; // stack

    int *ip = (int*) malloc(10  * sizeof(int));   // ip is on stack, array of int is on heap

    printf("\n i is residing at: %p", &i);  // Text Section of memory
    printf("\n j is residing at: %p", &j);  // Text Section of memory

    int k = fn(i,j);    // return address goes into the stack

    printf("\n\nCODE is residing at: %p", main);    // Text Section of memory
    printf("\n\nfn is residing at: %p", fn);    // Text Section of memory

    ip[0] = 11;
    *(ip+1) = 22;
    printf("\n\nip[0] Value is: %d", ip[0]);    // Text Section of memory
    printf("\nip[1] Value is: %d", ip[1]);    // Text Section of memory
    //location of the block of memory
    printf("\n where is the heap address: %p", ip);


    free(ip);

    printf("\n");

    return 0;
}