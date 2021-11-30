// CS 3100 Nov 29,2021
// Anthony Bahl
// Program 6 Assignment
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to prompt the user
int promptUser() {
    int userChoice = 0;
    printf("1) Print out my name\n2) Find the i-th Fibonacci number\n3) Exit\n");
    scanf("%d", &userChoice);
    return userChoice;
}

// Recursive function to calculate Fibonacci number
long fibo(int i) {
    if (i<2) {
        return i;
    } else {
        return fibo(i-1) + fibo(i-2);
    }
}

// Function that can be called by a thread to calculate the Fibonacci number
void *calcFib(void *arg) {
    int i = *((int *) arg);   // Get the value of i
    printf("You entered %d\n", i);
    printf("The Fibonacci of i is %ld\n", fibo(i));     // Print the result of the Fibonacci number
}

// Function that can be called by a thread to print my name
void *printName(void *arg) {
    printf("My name is Anthony Bahl\n");
}

// Have the user pick a Fibonacci number
int chooseFibNumber() {
    int userChoice = 0;
    printf("What would you like the Fibonacci number of?\n");
    scanf("%d", &userChoice);
    return userChoice;
}

int main(){
    bool flag = true;   // flag to control loop
    int fibNumb = 0;
    printf("Welcome!\n");

    do {
        int choice;
        choice = promptUser();
        pthread_t thread;           // variable for thread
        switch (choice) {
            case 1:
                pthread_create(&thread, NULL, printName, NULL);
                break;

            case 2:
                // Get a valid input from the user
                while (!(fibNumb > 0)) {
                    fibNumb = chooseFibNumber();
                    if (fibNumb > 0) {
                        pthread_create(&thread, NULL, calcFib, (void *) &fibNumb);
                    }
                    else {
                        printf("Invalid input\n");
                    }
                }                
                break;

            case 3:
                flag = false;
                break;
            
            default:
                printf("%d is an invalid choice.\n", choice);
                break;
        }
        fibNumb = 0;        // reset the fib number
        printf("\n");       // Start on a fresh line
    } while (flag);

    printf("Thank you! Goodbye!\n");
    return 0;
}