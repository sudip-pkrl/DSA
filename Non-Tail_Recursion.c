/*

# A recursive function is said to be non-tail recursive if the recursive call is not the last 
thing done by the function.

# After returning back there is something left to evaluate.

*/

#include<stdio.h>
void fun(int n){
    if(n==0)
        return;
    fun(n-1);
    printf("%d ",n);
}
int main()
{
    fun(3);
    return 0;
}