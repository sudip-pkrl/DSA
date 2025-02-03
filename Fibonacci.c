#include <stdio.h>

// Recursive function to calculate Fibonacci numbers
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    printf("Fibonacci sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", fibonacci(i));
    }
    
    return 0;
}
