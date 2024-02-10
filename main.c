/*
 * Write a program that asks user to enter a number in the range from 0 to 15 or a negative number to stop.
 * If user enters a number between 0 and 15 the program generates a random number and prints it in hexadecimal.
 * Then program shifts the number to the right by the amount user entered and uses bitwise
 * and to clear all other bits except bits 0-5 and prints the result in hexadecimal
 * with two digits and leading zeros.
Note: bit numbering starts from 0*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SHIFT 0
#define MAX_SHIFT 15
#define BUFFER_SIZE 100
#define MASK 0x3F // 0000000000111111 - mask to clear all bits except those in positions 0 to 5

int read_range(int low, int high);
int read_integer(void);


int main() {
    int user_number;
    int result;

    printf("Enter a number between %d and %d as a bit shift or a negative number to exit.\n", MIN_SHIFT, MAX_SHIFT);
    user_number = read_range(MIN_SHIFT, MAX_SHIFT);

    if (user_number < 0) {
        printf("Exiting the program.\n");
        return 0;
    } else {
        srand((unsigned int)time(NULL));
        int r_int = rand();
        printf("Here is a random integer number in hexadecimal: %x\n", r_int);

        r_int = r_int >> user_number;
        result = r_int & MASK;

        printf("After shifting to %d bits and clearing all after 5th, the random number becomes: %02x\n", user_number, result);
        return 0;
    }
}



int read_range(int low, int high) {
    int user_number;
    bool number_ok = false;

    do {
        user_number = read_integer();

        if ((user_number <= high && user_number >= low) || (user_number < 0)) {
            number_ok = true;
        } else {
            printf("Your number is neither negative nor within the interval %d - %d. Please try again.\n", low, high);
        }
    } while (!number_ok);

    return user_number;
}

int read_integer() {
    long int result;
    char input_buffer[BUFFER_SIZE];

    while (true) {
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
            printf("Invalid input - it is empty. Try again.\n");
            continue;
        }

        char *p_end_string_symbol;
        result = strtol(input_buffer, &p_end_string_symbol, 10);

        if (*p_end_string_symbol != '\0' && *p_end_string_symbol != '\n') {
            printf("Invalid input. Try again.\n");
            continue;
        }

        break;
    }

    return (int)result;
}
