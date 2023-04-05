//Condition ~ in O(n) time && O(1) space
#include <iostream>
using namespace std;

void printArray(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

void rotate(int A[], int n){
    int tmp = A[n];

    for(int i=n-1; i>=0; i--){
        A[i+1] = A[i];
    }
    A[0] = tmp;
}

int main(){
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n=10;
    printArray(A, n);
    cout<<endl;
    rotate(A, n-1);
    printArray(A, n);
    return 0;
}