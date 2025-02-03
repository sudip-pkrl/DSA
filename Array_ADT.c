#include<stdio.h>
#include<stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a,int tSize,int uSize){
    // (*a).total_size=tSize;
    // (*a).used_size=uSize;
    // (*a).ptr=(int*)malloc(tSize*sizeof(int));
    a->total_size=tSize;
    a->used_size=uSize;
    a->ptr=(int*)malloc(tSize*sizeof(int));
}

void display(struct myArray *a){
    printf("\n-------Elements of array-------\n");
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
}

void setVal(struct myArray *a){
    printf("\n-------Enter the elements-------\n");
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the value of  element %d : ",i);
        scanf("%d",&(a->ptr)[i]);
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks,10,2);

    // ----- For User Input -----

    // int total_size, used_size;
    // printf("Enter total size of the array: "); 
    // scanf("%d", &total_size); 
    // printf("Enter size to be used: ");
    // scanf("%d", &used_size); 
    // createArray(&marks, total_size, used_size);

    setVal(&marks);
    display(&marks);
    free(marks.ptr);
    return 0;
}