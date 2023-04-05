// Logic & coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Shows the element
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

// Finds product of A[i] except A[i] itself ~ O(n) & O(1)
bool findProduct(int *A, int n){
    long product=1;
    long zeroCount=0;
    // When array is 0 sized
    if(n<=0){
        return false;
    }
        // Iterate the array
        for(int i=0; i<n; i++){
            // Calculate the total product with handling zeros
            A[i] != 0 ? product *= A[i] : zeroCount++;
        }

        for(int i=0; i<n; i++){
            if(zeroCount > 1){
                A[i] = 0;
            }
            else if(zeroCount < 1){
                A[i] = product/A[i];
            }
            else if(zeroCount == 1 && A[i] != 0){
                A[i] = 0;
            }
            else{
                A[i] = product;
            }
        }
    return true;
}

// Driver code
int main(){
    int A[] = {4, 6, 3, 2, 10};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A, n);

    // Function call
    if(findProduct(A, n)){
        printArray(A, n);
    }
    else{
        cout<<"Array Size Can't Be Zero Or Negative!";
    }
    return 0;
} 