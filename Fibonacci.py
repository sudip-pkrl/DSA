# Recursive function to calculate Fibonacci numbers
def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

# Main code
n = int(input("Enter the number of terms: "))

print("Fibonacci sequence:")
for i in range(n):
    print(fibonacci(i), end="\n")