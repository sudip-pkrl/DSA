/* Stack implementation using Array*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#define MAX 2 //Global variable
int stack[MAX]; //To create a stack using array of the MAX size
int top=-1; //It is declared to point the top of the stack and is set to -1 initially to denote that the stack is empty at starting


int isFull() //This function will check whether the stack index is not exceeding its max size
{
	if(top==MAX-1)
		return 1; //Can be interpreted as true and means that stack is full
	else
		return 0; //Can be interpreted as false and means that stack is not full
}

int isEmpty() //This function is used to check whether the stack is empty or not.
{
	if(top==-1)
		return 1; //Can be interpreted as true and means that stack is empty.
	else
		return 0; //Can be interpreted as false and means that stack is not empty.
}
void push() //Function to insert/push data into the stack
{
	int n;
	if(isFull())
	{
		printf("\n\n\aStack Overflow, can't add more data\n\n");
		printf("\n\nYou can try again following\n\n");
		return; //This will return to main or we can say that further code of this function will not get executed
	}
	printf("\nEnter the value to be pushed: ");
	scanf("%d",&n);
	top=top+1;  //First we will increase the top value
	stack[top]=n; //This will insert the data in the top of the stack
}

void pop() //Function to remove/pop the data from the stack
{
	int n; //To store the deleted item or the item which is in top
	if(isEmpty()){
		printf("\n\n\aStack Underflow, no value to pop..\n\n");
	}
	else{
		n=stack[top]; //To store the top item of the stack
		top=top-1; 
		printf("\n\nPop is successfull !, %d is deleted from stack\n\n",n);
	}
	
}
int peek() //To see the top element on the stack
{
	if(isEmpty())
	{
		printf("\n\n\aStack is Empty, No data to display\n\n");
	}
	else{
		printf("\n\nThe top element of the stack is %d\n\n",stack[top]); //shows the top element
	}
}
void print() //To see the list of all the elements present in the stack
{
	int i;
	if(isEmpty())
	{
		printf("\n\n\aStack Underflow, no data to show\n\n");
	}
	else
	{
		printf("\n\nThe elements in stack are:\n");
		for(i=top;i>=0;i--) //Loop is used to traverse all the elements of the stack
		{
			printf("%d\n",stack[i]);
		}
	}	
}

//Main function is a menu driven which provide the interface to user to perform all kinds of possible operations for stack
int main()
{
	int ch,value;
	while(1)
	{
		printf("\n");
		printf("_____________________________________ Stack Implementation Using Array __________________________________________\n\n");
		printf("1. Push");
		printf("\n2. Pop");
		printf("\n3. Peek");
		printf("\n4. Print all the elements of the stack");
		printf("\n5. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				print();
				break;
			case 5:
				exit(1);
			default:
				printf("Invalid choice\n");
		}		
	}
	return 0;
	getch();
}