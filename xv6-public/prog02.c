/**
 * Anthony Bahl
 * 09/19/2021
 * Program 02
**/

#include "types.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[]){

    char buf[500];
    char standardOutput[21] = "The input string is:\n";
    int fd;

    printf(1, "My name is Anthony Bahl.\n");
    printf(1, "Please enter a string to save: ");
    gets(buf, sizeof(buf));
    fd = open("bob.txt", O_CREATE|O_RDWR);
    write(fd, standardOutput, sizeof(standardOutput));
    write(fd, buf, sizeof(buf));
    close(fd);

    exit();
}