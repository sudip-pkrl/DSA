# Recursive function to calculate Fibonacci numbers
def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

# Main code
n = int(input("Enter the position of the Fibonacci term you want: "))

# Print the nth Fibonacci number
print("Fibonacci term at position",n,"is",fibonacci(n))
# print(f"Fibonacci term at position {n} is: {fibonacci(n)}")