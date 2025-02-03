//Circular Queue Implementation using Array
#include<stdio.h>  
#include<conio.h>
#include<stdlib.h>

#define MAX 3  

int queue[MAX];  //Array declaration   for circular queue
int front=-1;  
int rear=-1;  

void enqueue()  
{
	int data;
//    printf("\n\nThe front : %d\n\n",front);
//    printf("\n\nThe rear : %d\n\n",rear);
    printf("Enter the element to insert in queue: ");  
    scanf("%d", &data);  
	if(front==-1 && rear==-1)   //First case : Queue can be empty  
    {  
        front=0;  
        rear=0;  
        queue[rear]=data;  
    }  
    else if((rear+1)%MAX==front)  // Second Case : Queue can be full  
    {  
        printf("\n\nQueue is Full\n\n");  
    }  
    else  		// Third Case : Queue can have space
    {  
        rear=(rear+1)%MAX;       // rear is incremented so that it goes back to the first location to make the queue circular  
        printf("%d is inserted\n",data);
        queue[rear]=data;    //Inserting the given data
        
    }  
}  

int dequeue()  
{  
    if((front==-1) && (rear==-1))  // First Case : Queue can be empty  
    {  
        printf("\n\nQueue is Empty\n\n");  
    }  
	else if(front==rear)       // Second Case : Both front and rear are pointing at same value
	{  
	   printf("\nThe dequeued element is %d", queue[front]);  
	   front=-1;  
	   rear=-1;  
	}   
	else  //Third Case : Front and rear are in different places
	{  
		printf("\nThe dequeued element is %d", queue[front]);  
	    front=(front+1)%MAX;  
	}  
}
  
// To display the elements of a queue  
void display()  
{  
    int i=front;
    if(front==-1 && rear==-1)  
    {  
        printf("\n\nQueue is empty\n\n");  
    }  
    else  
    {  
    	printf("\n\nElements in a Queue are : ");  
		while(i!=rear)
       	{
       		printf("%d\t", queue[i]);
			i=(i+1)%MAX;    
       	}
       	printf("%d",queue[rear]);
	}
} 

int main()  
{  
    int choice;  
      
    while(1)   
    {  
        printf("\n\nCircular Queue Menu:\n");
	    printf("\nPress 1: Insert an element in circular queue");  
	    printf("\nPress 2: Delete an element from circular queue");  
	    printf("\nPress 3: Display the element of circular queue");
	    printf("\nPress 4: Quit");
		  
	    printf("\nEnter your choice: ");  
	    scanf("%d", &choice);  
      
	    switch(choice)  
	    {  
	          
	        case 1:  
		        enqueue(); 
				display(); 
		        break;  
	        case 2:  
		        dequeue(); 
				display();  
		        break;  
	        case 3:  
	        	display(); 
	        	break;
			case 4:
                printf("\nProgram Exited Successfully...\n\n");
				exit(1); 
			default:
				printf("\nInvalid Choice\n");
				break;
	    }
	}  
	getch();
    return 0;  
}  
