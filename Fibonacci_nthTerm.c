#include <stdio.h>

// Recursive function to calculate Fibonacci numbers
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter the position of the Fibonacci term you want: ");
    scanf("%d", &n);
    
    // Print the nth Fibonacci number
    printf("Fibonacci term at position %d is: %d\n", n, fibonacci(n));
    
    return 0;
}
