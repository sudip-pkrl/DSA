# Function to calculate GCD using recursion
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

# Input two numbers
num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))

# Output the result
print(f"GCD of {num1} and {num2} is {gcd(num1, num2)}.")