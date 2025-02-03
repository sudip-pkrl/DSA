/*
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. 

The objective of the puzzle is to move the entire stack to another rod, obeying the following
simple rules:
1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on 
    top of another stack or on an empty rod.
3. No disk may be placed on top of a smaller disk.
*/

#include <stdio.h>

// Function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);
    // Move the nth disk to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n; // Number of disks
    printf("\nEnter the number of disks: ");
    scanf("%d", &n);
    printf("\nThe moves are:\n");
    towerOfHanoi(n, 'A', 'C', 'B'); // A is source, C is destination, B is auxiliary
    return 0;
}

// Explanation:-

// 1. The towerOfHanoi function is a recursive function that solves the Tower of Hanoi problem.
// 2. The function takes four parameters: n, source, destination, and auxiliary.
// 3. The base case is when n is 1, which means there is only one disk to move. 
//    In this case, we print the move and return.
// 4. Otherwise, we recursively move n-1 disks from the source to the auxiliary, 
//    then move the nth disk to the destination, and finally move n-1 disks from the 
//    auxiliary to the destination.
// 5. In the main function, we take the number of disks as input and call the towerOfHanoi 
//    function with the source as 'A', destination as 'C', and auxiliary as 'B'.
// 6. The time complexity of the Tower of Hanoi problem is O(2^n) and 
//    the space complexity is O(n).