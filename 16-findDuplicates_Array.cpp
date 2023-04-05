// Program to find duplicates in an array of n+1 integers ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Prints array elements
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

// Finds duplicates to array ~ O(n*logn) & O(1)
void findDuplicates(int *A, int n){
    int count;
    sort(A, A+n); // Sort the original array

    // Iterate array till end
    for(int i=0; i<n; i++){
        count = 1;
            if(A[i+1] == A[i] && A[i] != A[i-1]){
                count = 0;
            }
            if(count == 0){
                cout<<A[i]<<" ";
        }
    }
}

int main(){
    int A[] = {5, 6, 6, 7, 7, 7, 7, 7, 10, 10};
    // int A[] = {7, 7, 7};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A, n);
    cout<<"\nDuplicate elements are : ";
    findDuplicates(A, n);
    return 0;
} 