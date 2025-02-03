//Queue implementation using array

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 3

void insert(); //To insert the data from the linear queue
void delete(); //To delete the data from the linear queue
void display(); //To display the data from the linear queue

int queue[MAX]; //To create queue named queue
int rear = 0;	//To point the back of the queue
int front = 0;  //To point the front of the queue

int main()
{
	int choice;
	while(1) //To display the menu driven program
	{
		printf("\n\n1.Insert element to queue (enqueue)");
		printf("\n2.Delete element from queue(dequeue)");
		printf("\n3.Display all elements of queue");
		printf("\n4.Exit");
		printf("\n");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
                printf("\nProgram Exited Successfully...\n\n");
				exit(1);
			default:
				printf("\nInvalid choice");
				break;
		}
	}
	getch();
	return 0;
}

void insert()
{
	int item;
	if(rear == MAX)
		printf("\n\n\tQueue is full, can't add more elements\n\n");
	else
	{
		printf("\nInsert the element in queue : ");
		scanf("%d", &item);
		queue[rear] = item;
		printf("\n%d is inserted in the queue\n",item);
		rear++;	
	}
}

void delete()
{
	if(front == rear)
	{
		printf("\n\n\tQueue Underflow, no elements to delete\n\n");
		return;
	}
	else
	{
		printf("\n%d is deleted from queue....", queue[front]);
		front = front + 1;
	}
}

void display() //To display all the elements of the queue
{
	int i;
	if(front == rear)
		printf("\n\n\tQueue is empty, nothing to display\n\n");
	else
	{
		printf("Elements in Queue : ");
		for(i = front; i < rear; i++)
			printf("%d ", queue[i]);
		printf("\n");
	}
}	
