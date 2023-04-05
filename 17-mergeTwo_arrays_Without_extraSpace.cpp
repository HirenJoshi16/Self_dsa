// Merge two sorted array without any extra space means in O(1), check out Gap method to solve it, its an another way to do it 
#include <bits/stdc++.h>
using namespace std;

// Shows the element
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

// Merge's two array without any extra space ~ Hiren's code it takes - O(n*logn) and O(1) but it cant handle duplicates
void mergeTwo(int *A, int *B, int n, int m){
    int j=0;
    int tmp;
    for(int i=0; i<n; i++){
        if(A[i] > B[j]){
            tmp = A[i];
            A[i] = B[j];
            B[j] = tmp;
            sort(B, B+m);
        }
    }
}

// Driver code
int main(){
    int A[] = {1, 5, 9, 10, 15, 20};
    int B[] = {2, 3, 8, 13};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    printArray(A, n);
    cout<<"  ";
    printArray(B, m);
    cout<<endl;

    cout<<"After Merge : ";
    mergeTwo(A, B, n, m);
    printArray(A, n);
    printArray(B, m);

    return 0;
} 