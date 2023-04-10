// Program to find total ways to reach the N ~ coded by Hiren
#include <iostream>
#include <cstring>
using namespace std;

// Top-Down Approach :-
int memArray[46]; // N+1 to avoid out of bound accesses when N is 45

// #1 Method Helper: Finds total ways to climb the top
int countSteps(int n){
    // We can make no steps as its not possible to step up negatively
    if(n < 0)
        return 0;
    
    // If current N is computed before than return its step count
    if(memArray[n] != -1)
        return memArray[n];

    // We can make 1 step only
    if(n == 0)
        return 1;

    int oneStep = countSteps(n-1); // Take all the different ways to climb using 1 step
    int twoStep = countSteps(n-2); // Take all the different ways to climb using 2 step

    return (memArray[n] = oneStep + twoStep); // Store the steps count and than return it
}

// #1 Method to find total ways to climb the top using Recursion and Memoization - O(2^N) & O(N)
int climbStairs_1(int n){
    memset(memArray, -1, sizeof(memArray));
    return countSteps(n);
}

// Bottom-Up Approach using DP :-
// #2 Method to find total ways to climb the top - O(N) & O(N)
int climbStairs_2(int n){
    // Cases we know
    if(n==0 || n==1 || n==2 || n==3)
        return n;

    int arr[n+1];
    // i - Represents the stair | arr[i] - Represents the number of ways to reach ith stair
    arr[0] = 0; // There are 0 ways to reach 0th stair
    arr[1] = 1; // There are 1 ways to reach 1th stair
    arr[2] = 2; // There are 2 ways to reach 2th stair

    // Store the total ways to reach for each ith stair till N
    for(int i=3; i<=n; i++)
        arr[i] = arr[i-1] + arr[i-2];

    return arr[n]; // Finally return the nth stair ways stored in arr[n]
}

// Bottom-Up Approach using DP :-
// #3 Method to find total ways to climb the top using Fibonacci Sequence Intuition - O(N) & O(1)
int climbStairs_3(int n){
    // Cases we know
    if(n==0 || n==1 || n==2 || n==3)
        return n;

    int a = 1;
    int b = 2;
    int c = 3;

    // Generate the next number of sequence and store it in c and than move a and b correctly
    for(int i=3; i<=n; i++){
        c = a + b;
        int prevB = b;
        b = c;
        a = prevB;
    }
    return c;
}

// Driver code
int main(){
    int n = 5;
    // Method call
    int distinctSteps = climbStairs_3(n);
    cout<<"The distinct ways to climb to the top is "<<distinctSteps;
    
    return 0;
}
// Link: https://leetcode.com/problems/climbing-stairs/