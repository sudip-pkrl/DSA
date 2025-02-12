//Comparison Sorting : Bubble Sorting (C-Implementation)

#include<stdio.h>
#include<windows.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) 
	{
        for (j = 0; j < n - i - 1; j++) 
		{
            if (arr[j] > arr[j+1]) 
			{
                //Swap arr[j] and arr[j+1] if value of arr[j] is more than the value of arr[j+1] to make the highest number at the end
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() 
{
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

//    int arr[n]; //OR 
    int *arr = (int*)malloc(n*sizeof(int)); //to dynamically allocate the memory
    if(arr==NULL) 
	{
        printf("Memory allocation failed!");
        return 1; 
    }

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) 
	{
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n); //Function calling to sort the elements
	
	//To display the sorted elements
    printf("Sorted array elements are :\n"); 
    for(i = 0; i < n; i++)
    {
    	printf("%d ",arr[i]);
	}
	free(arr); //to free the allocated memory

    return 0; 
}