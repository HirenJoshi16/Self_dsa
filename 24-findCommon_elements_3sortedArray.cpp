#include <bits/stdc++.h>
using namespace std;

// Shows the element
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

// Finds common in O(n+m+l) and O(1)
void findCommon(int *A, int *B, int *C, int n, int m, int l){
    int i, j, k;
    i=j=k=0;

    cout<<"Common elements are : ";
    while(i<n && j< m && k<l){
        if(A[i] == B[j] && B[j] == C[k]){
            cout<<A[i]<<" ";
            i++;
            j++;
            k++;
        }
        else if(A[i] < B[j] && B[j] > C[k]){
            i++;
        }
        else if(B[j] < A[i] && B[j] > C[k]){
            j++;
        }
        else{
            k++;
        }
    }
} 

int main(){
    // int A[] = {4, 9, 10, 20};
    // int B[] = {6, 20, 30, 50};
    // int C[] = {4, 20, 30, 60};
    int A[] = { 5, 5, 10, 20, 40, 80};
    int B[] = { 6, 7, 20, 80, 100 };
    int C[] = { 3, 4, 15, 20, 30, 70, 80, 100};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);
    int l = sizeof(C) / sizeof(C[0]);

    findCommon(A, B, C, n, m, l);
    return 0;
} 