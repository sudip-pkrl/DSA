//Program to convert from infix to postfix
#include<stdio.h>
#include<string.h> 

//Function --> To set the precedence of the operators
int precedence(char c) 
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
//Function -->To return the associativity of the operators
char associativity(char c) 
{
	if (c == '^')
		return 'R';
	return 'L'; // Default to left-associative
}

// This is the function to convert infix to postfix
void infixToPostfix(char s[]) 
{
	char result[1000]; //To keep the final result i.e. The postfix expression
	int resultIndex = 0; // To set the result index at 0 because we are going to keep the output values here.
	int len = strlen(s); //To find how many times we need to run the loop
	char operator_stack[1000]; //To keep the operators in the stack for further operation
	int op_stackIndex = -1; //To set the index of operator stack to -1, so that it will imply that it is empty.
	int i;
	for(i = 0; i < len; i++) //This loop will check the expression from left to right untill all the characters are scanned
	{
		char c = s[i];

		// If the scanned character is an operand (alphabet or any digit), add it to the output string.
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) 
		{
			result[resultIndex++] = c; //Keep it in the result and then increase the stack index value
		}
		// If the scanned character is an ‘(‘, push it to the stack.
		else if (c == '(') 
		{
			operator_stack[++op_stackIndex] = c;
		}
		// If the scanned character is an ‘)’, pop and add to the output string from the stack
		// until an ‘(‘ is encountered.
		else if (c == ')') 
		{
			while (op_stackIndex >= 0 && operator_stack[op_stackIndex] != '(') 
			{
				result[resultIndex++] = operator_stack[op_stackIndex--];
			}
			op_stackIndex--; // To Pop '(' bracket which will get encountered
		}
		// If an operator is scanned, then check for the precedence and asssociativity
		else 
		{
			while (op_stackIndex >= 0 && (precedence(s[i]) < precedence(operator_stack[op_stackIndex]) || precedence(s[i]) == precedence(operator_stack[op_stackIndex]) && associativity(s[i]) == 'L')) 
			{
				result[resultIndex++] = operator_stack[op_stackIndex--];
			}
			operator_stack[++op_stackIndex] = c;
		}
	}

	// This will pop all the remaining elements from the stack
	while (op_stackIndex >= 0) 
	{
		result[resultIndex++] = operator_stack[op_stackIndex--];
	}
	result[resultIndex] = '\0'; 
    printf("Infix to Postfix Conversion:\n");
	printf("%s\n", result); //To print the final result.
}

// Main Function 
int main() 
{
	char expression[] = "a/b+c*d-e"; //Infix expression to convert

	// Function call which will send the given expression as parameter.
	infixToPostfix(expression);

	return 0;
}