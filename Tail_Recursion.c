// Tail-recursive factorial program in C

/* 
A recursive function is said to be tail recursive if the recursive call is the last thing
done by the function.There is no need to keep record of previous state.
*/

#include <stdio.h>

// Tail recursive factorial function
int tail_recursive_factorial(int n, int accumulator) {
    if (n == 0 || n == 1)
        return accumulator;
    return tail_recursive_factorial(n - 1, n * accumulator);
}

int main() {
    int num;
    
    // Taking user input
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Input validation
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        int result = tail_recursive_factorial(num, 1);
        printf("Factorial of %d is %d.\n", num, result);
    }

    return 0;
}


/*

## How It Works:-

# Uses scanf("%d", &num) to take an integer input from the user.
# Checks if the number is negative (factorial is undefined for negative numbers).
# Calls the tail-recursive function with an initial accumulator of 1.
# Outputs the factorial result.

*/


/*

## Limitations:-

# Using int can cause integer overflow for large values (e.g., 13! exceeds int limit).
# Use long long for larger factorial values:

    long long tail_recursive_factorial(int n, long long accumulator);
    printf("Factorial of %d is %llu\n", num, result);

*/