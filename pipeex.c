#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    int cp[2];

    pipe(cp);

    int id = fork();
    
    if(id == 0 ) 
    {
        close(cp[0]);
        int x = 33;

        write(cp[1], &x, sizeof(int));
        close(cp[1]);
    }
    else {
        
        close(cp[1]);
        int y;
        read(cp[0], &y, sizeof(int));
        close(cp[0]);

        printf("\n Received value for y from the child: %d", y);

    }

    printf("\n DONE FOR THE DAY!");

    return 0;
}