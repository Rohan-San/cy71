#include <stdio.h>
#include <omp.h>
#define SIZE 1000000

int array[SIZE]; // Large array to be filled

int main() {
  // Step 1: Initialize array with random numbers
  for (int i = 0; i < SIZE; i++) {
    array[i] = rand() % 100;
  }
  int sum = 0;
  
  // Step 2: Parallelize the loop using OpenMP
  #pragma omp parallel for reduction(+:sum)
  for (int i = 0; i < SIZE; i++) {
    sum += array[i]; // Calculate sum
  }
  printf("Total Sum: %d\n", sum);
  return 0;
}
