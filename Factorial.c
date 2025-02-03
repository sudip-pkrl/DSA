#include <stdio.h>

int factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1)
        return 1;
    // Recursive case
    return n * factorial(n - 1);
}

int main() {
    int number;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &number);

    if (number < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else
        printf("The factorial of %d is %d.\n", number, factorial(number));

    return 0;
}
