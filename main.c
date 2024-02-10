/*
 Write a function called print_numbers that takes two parameters: pointer to constant integers and
number of integers to print.
void print_numbers(const int *array, int count);
The function prints the numbers on separate lines in eight characters wide field.
Write a program that defines an array of 15 integers and fills the array with random numbers and
then uses the function to print the array contents. */

void print_numbers(const int *array, int count);

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15  //size of array
#define M 15  //how many numbers should be printed
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int numbers[N];
    const int* n_link = numbers;
    srand(time(NULL));
    for (int i=0; i < N; ++i){
        numbers[i] = rand();
    }
    print_numbers(n_link, M);
    return 0;
}

void print_numbers(const int *array, int count){

    for (int i=0; i<min(count,N); i++){
        printf("%8d \n", array[i]);
    }

}
