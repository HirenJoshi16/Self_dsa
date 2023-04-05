// Coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Shows the element
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

// Finds fix point to array ~ O(n) & O(1)
int findFixpoint(int *A, int n){
    // Iterate the array
    for(int i=0; i<n; i++){
        if(A[i]==i){
            return A[i], i; // Works fine but both are considerd as that value
        }
    }
    return 0;
}

// Driver code
int main(){
    int A[] = {10, 2, 5, 3, 6};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A, n);

    cout<<endl;
    if(int val = findFixpoint(A, n)){
        cout<<"element is : "<<val<<" at "<<val;
    }
    else{
        cout<<"No element";
    }
    return 0;
} 