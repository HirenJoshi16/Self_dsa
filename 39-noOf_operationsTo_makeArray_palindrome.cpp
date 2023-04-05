// Program to find minimum no. of operations to make an array palindrome
#include <bits/stdc++.h>
using namespace std;

// Finds no of operations ~ O(n) & O(1)
int findOperations(int *A, int n){
    int i = 0;
    int j = n-1;
    int count = 0; // Stores operation counts

    // Iterate while i & j not collide
    while(i <= j){
        // If elements are equal just move i and j
        if(A[i] == A[j]){
            i++;
            j--;
        }
        // If A[i] is lesser move i and sum this ith value with its previous ith value
        else if(A[i] < A[j]){
            i++;
            A[i] += A[i-1];
            count++; // Increament count as merging taken
        }
        // If A[j] is lesser move j and sum this jth value with its previous jth value
        else{
            j--;
            A[j] += A[j-1];
            count++; // Increament count as merging taken
        }
    }
    return count;
}
 
// Driver code
int main(){
    // int A[] = {11, 14, 15, 99};
    int A[] = {1, 4, 5, 1};
    int n = 4;

    // Display array elements
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }

    cout<<endl;
    // Function call
    if(int operations = findOperations(A, n)){
        cout<<"Minimum no of operations : "<<operations;
    }
    else{
        cout<<"Already a palindrome";
    }
    return 0;
}