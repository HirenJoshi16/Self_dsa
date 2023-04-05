#include <bits/stdc++.h>
using namespace std;

// Method to Find least no of jumps to reach end of the array - O(n) & O(1)
int minJumps(int *A, int n){
    // Edge case
    if(n<=1 || A[0] == 0) return 0;
    
    int maxReach = A[0]; // Stores maximum reaches of first value
    int steps = A[0]; // Stores maximum steps can be taken by first value
    int jumps = 1; // Everytime there will be a single jump needed to reach indeces

    // Iterate till end
    for(int i=1; i<n; i++){
        // If end point is reached return no of jumps
        if(i == n-1) return jumps;

        // Will update maximum reaches of current value in the array  
        maxReach = max(maxReach, A[i]+i); // Where A[i]+i is the maximum reach point of current index value, hence we have to insure that the current index max reach is maximum or previously reached is maximum hence store the max reach

        steps--; // As we move further we will decrease the steps because as we used up a step to get to the current index hence it has to be decreased 
            // If no further steps are left or When there is no step left hence we must used a jump then, thus increase jumps
            if(steps == 0){
                jumps++;

                // Check in case current index value is negative or zero, if it is then cant move further
                if(i >= maxReach){
                    return -1;
                }
            steps = maxReach-i; // When steps is 0 we have to find no of steps to reach maximum reach from the ith position hence re-initialize steps
        }
    }
    return -1;
}

// Drive code
int main(){
    int A[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(A) / sizeof(A[0]);
    cout<<"Minimum no of jumps are : "<<minJumps(A, n);
    return 0;
}